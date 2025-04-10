/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:00:36 by thiew             #+#    #+#             */
/*   Updated: 2025/04/10 14:02:26 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/main.hpp"

winInfo 			g_win_size;
bool				g_win_change(false);
bool				g_input(false);
std::atomic<bool>	g_exit_flag(false); // set to true when right signal is sent
std::atomic<char>	g_input_char(0); //char received from user
void				starting_screen();


int	main(void)
{
	//prepare and clear logfile
	std::ofstream erase_log("debug.log", std::ios::trunc);
	erase_log << ""; 
	erase_log.close();

	//set initial window size
	g_win_size = getWinSize();

	//init backend
	Back	*backend = BackendInit();
	if (!backend)
		return (1);
	char *random_word = RandomWord();
	debugPrint(backend->rand_word);
	debugPrint(random_word);

	//switch to TUI
	setNonCanonicalMode(true);

	//input thread handling
	std::thread	input_thread(checkInput, std::ref(g_exit_flag), std::ref(g_input_char));

	//instatialize MatrixHandler
	MatrixHandler Matrix(backend);

	//recalculate window size on change
	signal(SIGWINCH, winSizeHandler);
	//other signals
	signal(SIGTERM, die);
	signal(SIGINT, die);

	bool start(true);
	//main loop
	std::cout << NO_CURSOR;
	while (!g_exit_flag)
	{
		if (g_input_char != '\n' && start)
		{
			starting_screen();
			start = false;
		}
		if (g_input == true || g_win_change == true)
		{
			Matrix.wordInput();
			Matrix.recalculate();
			Matrix.rows();
			Matrix.draw();
			g_input = false;
		}
		usleep(80000);
	}
	std::cout << CURSOR;

	//cleaning up
	g_exit_flag = true;
	BackendQuit();
	(void)backend;
	input_thread.join();
	setNonCanonicalMode(false);
	std::cout << std::endl << "FINISHED" << std::endl;
	atexit(cleanup);

	return (0);
}
void 	starting_screen()
{
    // ASCII art
    std::vector<std::string> art = {
        " __        __   _                            ",
        " \\ \\      / /__| | ___ ___  _ __ ___   ___   ",
        "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\  ",
        "   \\ V  V /  __/ | (_| (_) | | | | | |  __/  ",
        "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  "
    };

    // Basic instructions
    std::vector<std::string> rules = {
		"Simple Wordle game - guess the correct word",
        "Rule 1: Enter your guess and press Enter.",
        "Rule 2: Each guess must be a valid word.",
        "Rule 3: You have 6 tries to guess the word.",
		"Hint:",
		"Green is correct placement",
		"Yellow is correct letter but wrong place",
		"Grey is incorrect letter"
    };

    // Starting prompt
    std::string prompt = "Press any key to start.";
	std::string prompt2 = " Press escape to exit.";

    // Calculate the total number of lines to display:
    // art + blank line + rules + blank line + prompt * 2.
    int total_lines = art.size() + 1 + rules.size() + 2; 

    // Calculate vertical (row) offset for centering in the window.
    int start_row = (g_win_size.height - total_lines) / 2;
    if (start_row < 0)
        start_row = 0;

    // Print enough blank lines before starting content.
    for (int i = 0; i < start_row; ++i)
        std::cout << "\n";

    // Print ASCII art lines centered horizontally.
    for (const auto &line : art)
    {
        int pad = (g_win_size.width - line.size()) / 2;
        if (pad < 0)
            pad = 0;
        std::cout << std::string(pad, ' ') << line << "\n";
    }

    std::cout << "\n"; // Blank line between art and rules.

    // Print the rules centered.
    for (const auto &rule : rules)
    {
        int pad = (g_win_size.width - rule.size()) / 2;
        if (pad < 0)
            pad = 0;
        std::cout << std::string(pad, ' ') << rule << "\n";
    }

    std::cout << "\n";

    // Print the prompt centered.
    {
        int pad = (g_win_size.width - prompt.size()) / 2;
        if (pad < 0)
            pad = 0;
        std::cout << std::string(pad, ' ') << prompt << "\n";
		std::cout << std::string(pad, ' ') << prompt2 << "\n";
    }

// {
	// 	int pad = (g_win_size.width - prompt.size()) / 2;
	// 	if (pad < 0)
	// 		pad = 0;
	// 	std::cout << std::string(pad, ' ') << prompt2 << "\n";
	// }


    std::string horizontal_border(g_win_size.width, '=');
    std::cout << "\033[H" << horizontal_border;
    std::cout << "\033[" << g_win_size.height << ";1H" << horizontal_border;

    // Flush the output.
    std::cout.flush();

}
