/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:42:12 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 23:05:09 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "externLibs.hpp"
#include "assets.hpp"
#include "colors.hpp"
#include "data.hpp"

// typedef struct Back
// {
// 	char			check_input[6]; 0 - wrong letter, 1 wrong pos, 2 right
// 	char			*rand_word; -
// 	unsigned char	valid_input:3;
// 	unsigned char	victory:2;
// }Back;

class MatrixHandler
{
	public:
		//constructor
		MatrixHandler(Back *backend);

		//drawing utils
		void		draw();
		void		recalculate();
		void		rows();
		void		tile(size_t pos_x, size_t pos_y, int line=0, size_t tile=0, size_t y=0);
		void		wordTiles(std::string &pos, int &line, size_t &tile, size_t &y);
		void		infoTiles(std::string &pos, int &line, size_t &tile, size_t &y);

		//input handling
		void		wordInput();
		void		pushToVector();

	private:
		std::vector<std::vector<std::string>>	_draw_matrix;
		std::vector<std::string>				_completed_words;
		std::vector<std::string>				_completed_words_pos;
		std::string								_curr_word;
		size_t									_curr_line;
		Back									*_backend;
		bool									_full_word;
		bool									_correct_word;
		bool									_winner;
		bool									_looser;
};

std::string	macro_cast(const char *macro);
