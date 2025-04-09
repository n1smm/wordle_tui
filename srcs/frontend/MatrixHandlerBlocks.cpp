/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandlerBlocks.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:54:00 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 13:06:03 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MatrixHandler.hpp"


void		MatrixHandler::rows()
{
	size_t y = 0;
	size_t x = 0;
	for (size_t i = 0; i < _draw_matrix.size(); i+= g_win_size.tile_h)
	{
		for (size_t j = 0; j < _draw_matrix[i].size(); j+= g_win_size.tile_w)
		{
			if (y > 1 && y < 8
					&& x > 1 && x < 7)
				tile(j, i);
			x++;
		}
		x = 0;
		y++;
	}
}


void		MatrixHandler::tile(size_t pos_x, size_t pos_y)
{
	size_t max_row = std::min(pos_y + g_win_size.tile_h, _draw_matrix.size());

	for (size_t i = pos_y; i < max_row; i++)
	{
        size_t max_col = std::min(pos_x + g_win_size.tile_w, _draw_matrix[i].size());

		for (size_t j = pos_x; j < max_col; j++)
		{
			 // Top row of the tile
            if (i == pos_y)
            {
                if (j == pos_x)
                    _draw_matrix[i][j] = LU_ANGLE; // Top left corner
                else if (j == pos_x + g_win_size.tile_w - 1)
                    _draw_matrix[i][j] = RU_ANGLE; // Top right corner
                else
                    _draw_matrix[i][j] = H_LINE;   // Top horizontal line
            }
            // Bottom row of the tile
            else if (i == pos_y + g_win_size.tile_h - 1)
            {
                if (j == pos_x)
                    _draw_matrix[i][j] = LD_ANGLE; // Bottom left corner
                else if (j == pos_x + g_win_size.tile_w - 1)
                    _draw_matrix[i][j] = RD_ANGLE; // Bottom right corner
                else
                    _draw_matrix[i][j] = H_LINE;   // Bottom horizontal line
            }
            // Middle rows
            else
            {
                if (j == pos_x || j == pos_x + g_win_size.tile_w - 1)
                    _draw_matrix[i][j] = V_LINE;   // Vertical borders on the sides
                else
                    _draw_matrix[i][j] = EMPTY;
			}
		}
	}
}
