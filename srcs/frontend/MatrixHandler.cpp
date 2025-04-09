/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:41:12 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 17:25:13 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/MatrixHandler.hpp"


std::string	macro_cast(const char *macro)
{
	return (std::string(macro));
}

/*
   @description: constructor that initializes all the variables of the class
   				- _draw_matrix
	@called by: main
*/
MatrixHandler::MatrixHandler(): 
	_draw_matrix(g_win_size.height + 1, std::vector<std::string>(g_win_size.width + 1, macro_cast(EMPTY))),
	_completed_words(6, std::string("00000")),
	_curr_word(""),
	_curr_line(2)
{
	for (size_t i  = 0; i < g_win_size.height; i++)
	{
		for (size_t j = 0; j < g_win_size.width; j++)
		{
			if (static_cast<size_t>(j) == g_win_size.field_left 
					|| static_cast<size_t>(j) == g_win_size.field_w)
				_draw_matrix[i][j] = macro_cast(V_LINE);
			else if (static_cast<size_t>(i) == g_win_size.field_up 
					|| static_cast<size_t>(i) == g_win_size.field_h)
				_draw_matrix[i][j] = macro_cast(H_LINE);
			else
				_draw_matrix[i][j] = macro_cast(EMPTY);
		}
	}


}

/* 
   @description: this draws the chars saved in _draw_matrix to the screen)
   @called by: main
*/
void	MatrixHandler::draw()
{
	// check if window is to small
	if (g_win_size.height < 35 || g_win_size.width < 55)
	{
		std::string error_msg = "WINDOW IS TO SMALL!";
		for (size_t i = 0; i < g_win_size.height; i++)
		{
			for (size_t j = 0; j < g_win_size.width; j++)
			{
				if (i == g_win_size.height / 2
						&& j == (g_win_size.width / 2) - (error_msg.size() / 2))
				{
					std::cout << error_msg;
					j += error_msg.size();
				}
				std::cout << macro_cast(WALL);
			}
			std::cout << "\n";
		}
		return ;
	}


	for (size_t i = 0; i < _draw_matrix.size(); i++)
	{
		for (size_t j = 0; j < _draw_matrix[i].size(); j++)
		{
			std::cout << _draw_matrix[i][j];
		}
		std::cout << "\n";
	}
}

/*
   @description: this recalculates the size of _draw_matrix based on the size of terminal window
   				only runs when SIGWINCH signal is sent
   @Called by: main
*/
void	MatrixHandler::recalculate()
{
	if (g_win_change == false)
		return ;

	_draw_matrix.clear();	
	_draw_matrix.resize(g_win_size.height + 1);
	for (size_t i = 0; i < g_win_size.height; i++)
	{
		_draw_matrix[i].resize(g_win_size.width + 1, macro_cast(EMPTY));
	}

	for (size_t i = 0; i < g_win_size.height; i++)
	{
		for (size_t j = 0; j < g_win_size.width; j++)
		{
			if (static_cast<size_t>(j) == g_win_size.field_left 
					|| static_cast<size_t>(j) == g_win_size.field_w)
				_draw_matrix[i][j] = macro_cast(V_LINE);
			else if (static_cast<size_t>(i) == g_win_size.field_up 
					|| static_cast<size_t>(i) == g_win_size.field_h)
				_draw_matrix[i][j] = macro_cast(H_LINE);
			else
				_draw_matrix[i][j] = macro_cast(EMPTY);
		}
	}
	g_win_change = false;
}


