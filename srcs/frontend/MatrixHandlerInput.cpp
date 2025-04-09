/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandlerInput.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:20:03 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 18:41:49 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/MatrixHandler.hpp"


void		MatrixHandler::wordInput()
{
	if (g_input_char == ESCAPE)
		g_exit_flag = true;
	else if (g_input_char == BACKSPACE)
	{
		if (_curr_word.size() > 0)
			_curr_word.pop_back();
	}
	else if (g_input_char == '\n')
		pushToVector();
	else if (g_input_char != 0 && _curr_word.size() < 5)
		_curr_word.push_back(g_input_char);
	debugPrint(_curr_word);
}

void		MatrixHandler::pushToVector()
{
	if (_curr_word.size() != 5 || _curr_line -2 > 6)
		return ;

	_completed_words[_curr_line - 2] = _curr_word;
	debugPrint("compword: ",_curr_line -2, ",", _completed_words[_curr_line -2]);
	_curr_word.clear();
	_curr_line++;
}
