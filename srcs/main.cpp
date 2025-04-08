/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:00:36 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 13:55:06 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/main.hpp"


int	main(void)
{
	//prepare and clear logfile
	std::ofstream eraseLog("debug.log", std::ios::trunc);
	eraseLog << ""; 
	eraseLog.close();

	//switch to TUI
	setNonCanonicalMode(true);

	//input thread handling
	std::atomic<char>	input_char = 0; //char received from user
	std::atomic<bool>	exit_flag(false); // set to true when right signal is sent
	std::thread	input_thread(checkInput, std::ref(exit_flag), std::ref(input_char));

	//main loop
	while (!exit_flag)
	{


	}

	//cleaning up
	exit_flag = true;
	input_thread.join();
	setNonCanonicalMode(false);
	std::cout << std::endl << "FINISHED" << std::endl;

	return (0);
}
