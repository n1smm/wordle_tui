/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandlerBlocks.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:54:00 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 19:19:33 by thiew            ###   ########.fr       */
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
			{
				if (y == _curr_line)
					tile(j, i, 1, x - 2);
				else if (y && y < _curr_line)
					tile(j,i, -1, x -2, y - 2);
				else
					tile(j,i);
			}
			x++;
		}
		x = 0;
		y++;
	}
}


void		MatrixHandler::tile(size_t pos_x, size_t pos_y, int line, size_t tile, size_t y)
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
					_draw_matrix[i][j] = macro_cast(LU_ANGLE); // Top left corner
				else if (j == pos_x + g_win_size.tile_w - 1)
					_draw_matrix[i][j] = macro_cast(RU_ANGLE); // Top right corner
				else
					_draw_matrix[i][j] = macro_cast(H_LINE);   // Top horizontal line
			}

			// Bottom row of the tile
			else if (i == pos_y + g_win_size.tile_h - 1)
			{
				if (j == pos_x)
					_draw_matrix[i][j] = macro_cast(LD_ANGLE); // Bottom left corner
				else if (j == pos_x + g_win_size.tile_w - 1)
					_draw_matrix[i][j] = macro_cast(RD_ANGLE); // Bottom right corner
				else
					_draw_matrix[i][j] = macro_cast(H_LINE);   // Bottom horizontal line
			}

			// Top-left inner cell
			else if (i == pos_y + 1 && j == pos_x + 1)
			{
				infoTiles(_draw_matrix[i][j], line, tile);
			}

			// Center of the tile
			else if (i == pos_y + g_win_size.tile_h / 2 && j == pos_x + g_win_size.tile_w / 2)
			{
				wordTiles(_draw_matrix[i][j], line, tile, y);
			}

			// Middle rows
			else
			{
				if (j == pos_x || j == pos_x + g_win_size.tile_w - 1)
					_draw_matrix[i][j] = macro_cast(V_LINE);   // Vertical borders on the sides
				else
					_draw_matrix[i][j] = macro_cast(EMPTY); 
			}
		}
	}
}

void		MatrixHandler::wordTiles(std::string &pos, int &line, size_t &tile, size_t &y)
{
	if (line == 1)
	{
		pos = macro_cast(GREEN "O" FG_RESET);
		if (line == 1)
			pos = macro_cast(GREEN) + _curr_word[tile] + macro_cast(FG_RESET);
		if (line == 1 && _curr_word.size() <= tile)
			pos = macro_cast(GREEN " " FG_RESET);
	}
	else if (line == -1)
	{
		pos = macro_cast(GREEN) + _completed_words[y][tile] + macro_cast(FG_RESET);
	}
}

void		MatrixHandler::infoTiles(std::string &pos, int &line, size_t &tile)
{
	(void)line;
	(void)tile;
	pos = macro_cast(RED "X" FG_RESET);
}
