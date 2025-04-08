/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontEndUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:31:58 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 14:59:01 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/frontend.hpp"


void setNonCanonicalMode(bool enable) 
{
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt); 
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
		fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
		
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | ~O_NONBLOCK);
    }
}

void checkInput(std::atomic<bool>	&exit_flag, std::atomic<char> &input_char)
{
	::steady_clock::time_point last_event = ::steady_clock::now();
    while (!exit_flag) 
	{
		char c;
		ssize_t bytes = read(STDIN_FILENO, &c, 1);
		if (bytes > 0)
		{
			last_event = ::steady_clock::now();
			input_char = c;
			if (input_char == 'q')
				exit_flag = true;
		}
		
		::steady_clock::time_point now = ::steady_clock::now();
		long long	elapsed_time = ::duration_cast<::milliseconds>(now - last_event).count();

		if (elapsed_time > KEY_TIMEOUT_MS)
			input_char = 0;
		usleep(800);
    }
}
