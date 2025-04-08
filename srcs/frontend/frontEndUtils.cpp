/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontEndUtils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:31:58 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 20:56:04 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/frontend.hpp"


void setNonCanonicalMode(bool enable) 
{
    static struct termios oldt, newt;
    if (enable) {
		// save old terminal setting, initializen non-canonical mode	
        tcgetattr(STDIN_FILENO, &oldt); 
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

		// set stdin to nonblocking
		fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);

		// start alternate screen buffer
		std::cout << TUI_BUFFER;
    } else {
		//restore previous terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | ~O_NONBLOCK);

		//exit alternat screen buffer
		std::cout << OLD_BUFFER;
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

winInfo	getWinSize()
{
	struct winsize w;
	struct winInfo ret = {0, 0, 0, 0, 0, 0, 0, 0};
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
	{
        perror("ioctl TIOCGWINSZ error");
		g_exit_flag = true;
		return (ret);
    }
	//full size of window
	ret.width = static_cast<size_t>(w.ws_col) - 4;
	ret.height = static_cast<size_t>(w.ws_row) - 2;
	//usable space 
	ret.field_h = ret.height - 1;
	ret.field_w = ret.width - 2;
	//helpers where usable space starts
	ret.field_left = 1;
	ret.field_up = 1;
	//single tile w/h
	ret.tile_h = ret.field_h / 9;
	ret.tile_w = ret.field_w / 9;

    std::cout << "Columns: " << w.ws_col << ", Rows: " << w.ws_row << std::endl;
	return (ret);
}

void	winSizeHandler(int i)
{
	(void)i;
	g_win_size = getWinSize();
	g_win_change = true;
}
