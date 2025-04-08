/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:41:12 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 22:41:17 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/MatrixHandler.hpp"

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


void	MatrixHandler::draw()
{
	// for (size_t i  = 0; i <= g_win_size.height; i++)
	// {
	// 	for (size_t j = 0; j <= g_win_size.width; j++)
	// 	{
	// 		if (static_cast<size_t>(j) == g_win_size.field_left 
	// 				|| static_cast<size_t>(j) == g_win_size.field_w)
	// 			std::cout << V_LINE;
	// 		else if (static_cast<size_t>(i) == g_win_size.field_up 
	// 				|| static_cast<size_t>(i) == g_win_size.field_h)
	// 			std::cout << H_LINE;
	// 		else
	// 			std::cout << EMPTY;
	// 	}
	// 	std::cout << "\n";
	// }
	

	for (size_t i = 0; i < _draw_matrix.size(); i++)
	{
		for (size_t j = 0; j < _draw_matrix[i].size(); j++)
		{
			std::cout << _draw_matrix[i][j];
		}
		std::cout << "\n";
	}
}
