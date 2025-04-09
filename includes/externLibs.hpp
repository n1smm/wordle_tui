/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externLibs.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 01:23:20 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 16:26:56 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <thread>
#include <atomic>
#include <chrono>
#include <optional>
#include <algorithm>
#include <random>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <signal.h>
#include "structs.hpp"
#include "debug.hpp"

using namespace std::chrono;

//global win_size for dynamic window size handling
extern winInfo 				g_win_size;
//global for exiting program
extern std::atomic<bool>	g_exit_flag;
extern bool					g_win_change;
extern bool					g_input;
extern std::atomic<char>	g_input_char; //char received from user
