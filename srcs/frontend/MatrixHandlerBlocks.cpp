/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandlerBlocks.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:54:00 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 22:45:16 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MatrixHandler.hpp"


/*
   @description: segments the screen to grid
   @called by: main
*/
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
				// if (_full_word == true)
				// {
				// 	tile(j, i, 0, x - 2, 10);
				// }
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

/*
   @description: checks each tile in grid and adjust its content accordingly
   				creates borders for inner tiles
	@params: pos_x - starting x position, pos_y - starting y position of tile
			line - 0 if no words, 1 if need to print current word, -1 if completed word
			tile - which char of the word needs to be printed
			y - which entry in _completed_words needs to be printed
	@called by: rows
*/
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
				infoTiles(_draw_matrix[i][j], line, tile, y);
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

/*
   @description: handles the center of tile (char of a word passed or from completed words)
   @params: check tiles function for explanation
   @called by: tiles
*/
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
		if (_completed_words_pos[y][tile] == 0)
			pos = macro_cast(BRIGHT_BLACK) + _completed_words[y][tile] + macro_cast(FG_RESET);
		else if (_completed_words_pos[y][tile] == 1)
			pos = macro_cast(YELLOW) + _completed_words[y][tile] + macro_cast(FG_RESET);
		else if (_completed_words_pos[y][tile] == 2)
			pos = macro_cast(GREEN) + _completed_words[y][tile] + macro_cast(FG_RESET);
		else
			pos = macro_cast(RED) + _completed_words[y][tile] + macro_cast(FG_RESET);
	}
}


/*
   @description: handles the corner info tile (symbol indicating if ok or no)
   @params: check tiles function for explanation
   @called by: tiles
*/
void		MatrixHandler::infoTiles(std::string &pos, int &line, size_t &tile, size_t &y)
{
	if (_full_word)
	{
		if (_correct_word)
		{
			pos = macro_cast(GREEN "O" FG_RESET);
		}
		else
		{
			pos = macro_cast(RED "X" FG_RESET);
		}

	}
	else
		pos = macro_cast(YELLOW "E" FG_RESET);
	(void)tile;
	(void)y;
	(void)line;
}
