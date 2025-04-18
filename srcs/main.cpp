/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:00:36 by thiew             #+#    #+#             */
/*   Updated: 2025/04/10 10:42:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/main.hpp"

winInfo g_win_size;
bool	g_win_change(false);
bool	g_input(false);
std::atomic<bool>	g_exit_flag(false); // set to true when right signal is sent
std::atomic<char>	g_input_char(0); //char received from user

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

	//main loop
	std::cout << NO_CURSOR;
	while (!g_exit_flag)
	{
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
