/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:33:21 by tjuvan            #+#    #+#             */
/*   Updated: 2025/04/08 19:36:00 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#define WALL  		"╬" 
#define DIM_WALL 	"░"

#define EMPTY		" "


//hitables
#define V_LINE		"║"
#define H_LINE		"═"
#define RU_ANGLE	"╗"
#define RD_ANGLE	"╝"
#define LU_ANGLE	"╔"
#define LD_ANGLE	"╚"


//terminal manipulation
#define NO_CURSOR 	"\033[?25l"
#define CURSOR		"\033[?25h"
#define	TUI_BUFFER	"\033[?1049h"
#define	OLD_BUFFER	"\033[?1049l"
#define ESCAPE		'\033'
#define	BACKSPACE	'\x7f'
