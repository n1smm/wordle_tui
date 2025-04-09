/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandlerInput.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:20:03 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 23:05:33 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MatrixHandler.hpp"

/*
   @description: checking user input and interaction with backend
   @called by: main
*/
void		MatrixHandler::wordInput()
{
	bool enter = false;
	_full_word = false;
	_correct_word = false;
	if (g_input_char == ESCAPE)
		g_exit_flag = true;
	else if (g_input_char == BACKSPACE)
	{
		if (_curr_word.size() > 0)
			_curr_word.pop_back();
	}
	else if (g_input_char == '\n')
		enter = true;
	else if (g_input_char != 0 && _curr_word.size() < 5)
		_curr_word.push_back(g_input_char);
	if (_curr_word.size() == 5)
	{
		_full_word = true;
		if (DictCheck(const_cast<char *>(_curr_word.c_str())))
			_correct_word = true;
		else
			_correct_word = false;
	}
	if (enter)
		pushToVector();
	if (_curr_line - 2 == 6 && !_winner)
		_looser = true;

	debugPrint(_curr_word);
}

/*
   @description: handles completed words,
   			pushes to _completed_words vector
			and checks for correct placement of chars
	@called by: wordInput
*/
void		MatrixHandler::pushToVector()
{
	if (_curr_word.size() != 5 || _curr_line -2 > 6 || _correct_word == false)
		return ;

	WordSearch(const_cast<char *>(_curr_word.c_str()));
	if (_backend->valid_input == RIGHT_INPUT)
	{
		for (size_t i = 0; i < 6; i++)
		{
			_completed_words_pos[_curr_line -2][i] = _backend->check_input[i];
		}
	}
	_completed_words[_curr_line - 2] = _curr_word;
	// debugPrint("compword: ",_curr_line -2, ",", _completed_words[_curr_line -2]);
	// debugPrint("inputs:", _backend->check_input[0]);
	_curr_word.clear();
	_curr_line++;
	if (_backend->victory == 1)
		_winner = true;
}
