/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:00:36 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 22:01:53 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/main.hpp"

winInfo g_win_size;
bool	g_win_change(false);
std::atomic<bool>	g_exit_flag(false); // set to true when right signal is sent

int	main(void)
{
	//prepare and clear logfile
	std::ofstream erase_log("debug.log", std::ios::trunc);
	erase_log << ""; 
	erase_log.close();

	//set initial window size
	g_win_size = getWinSize();

	//switch to TUI
	setNonCanonicalMode(true);

	//input thread handling
	std::atomic<char>	input_char = 0; //char received from user
	std::thread	input_thread(checkInput, std::ref(g_exit_flag), std::ref(input_char));
	//instatialize MatrixHandler
	MatrixHandler Matrix;

	//recalculate window size on change
	signal(SIGWINCH, winSizeHandler);
	//other signals
	signal(SIGTERM, die);
	signal(SIGINT, die);

	//main loop
	std::cout << NO_CURSOR;
	while (!g_exit_flag)
	{
		Matrix.recalculate();
		Matrix.draw();
		usleep(5000);
	}
	std::cout << CURSOR;

	//cleaning up
	g_exit_flag = true;
	input_thread.join();
	setNonCanonicalMode(false);
	std::cout << std::endl << "FINISHED" << std::endl;
	atexit(cleanup);

	return (0);
}
