/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:41:12 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 10:55:06 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/MatrixHandler.hpp"

/*
   @description: constructor that initializes all the variables of the class
   				- _draw_matrix
	@called by: main
*/
MatrixHandler::MatrixHandler(): 
	_draw_matrix(g_win_size.height + 1, std::vector<const char *>(g_win_size.width + 1, EMPTY))
{
	for (size_t i  = 0; i < g_win_size.height; i++)
	{
		for (size_t j = 0; j < g_win_size.width; j++)
		{
			if (static_cast<size_t>(j) == g_win_size.field_left 
					|| static_cast<size_t>(j) == g_win_size.field_w)
				_draw_matrix[i][j] = V_LINE;
			else if (static_cast<size_t>(i) == g_win_size.field_up 
					|| static_cast<size_t>(i) == g_win_size.field_h)
				_draw_matrix[i][j] = H_LINE;
			else
				_draw_matrix[i][j] = EMPTY;
		}
	}


}

/* 
   @description: this draws the chars saved in _draw_matrix to the screen)
   @called by: main
*/
void	MatrixHandler::draw()
{
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

	_draw_matrix.resize(g_win_size.height + 1);
	for (size_t i = 0; i < g_win_size.height; i++)
	{
		_draw_matrix[i].resize(g_win_size.width + 1, EMPTY);
	}

	for (size_t i = 0; i < g_win_size.height; i++)
	{
		for (size_t j = 0; j < g_win_size.width; j++)
		{
			if (static_cast<size_t>(j) == g_win_size.field_left 
					|| static_cast<size_t>(j) == g_win_size.field_w)
				_draw_matrix[i][j] = V_LINE;
			else if (static_cast<size_t>(i) == g_win_size.field_up 
					|| static_cast<size_t>(i) == g_win_size.field_h)
				_draw_matrix[i][j] = H_LINE;
			else
				_draw_matrix[i][j] = EMPTY;
		}
	}
	g_win_change = false;
}


