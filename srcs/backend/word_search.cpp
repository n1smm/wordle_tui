/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_search.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:55:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/10 16:12:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

static int	check_guess(Back *back, char *input);
static Back	*set_error(Back *back, int error);

/*
//REVIEW - WordSearch

@description: 	Update the back struct, so:
				valid_input is: 
					set to 0 if RIGHT_INPUT,
					set to 1 if WRONG_LEN,
					set to 2 if WRONG_CHAR,
					set to 3 if NOT_IN_DICTIONARY.
				
				check_input is a 5 len array.
				Every member of the array represents the color that
				must be used to color the word given by user.
					0 means WRONG_LETTER (no color);
					1 means WRONG_POSITION (yellow);
					2 means RIGHT_LETTER (green).  

@returns: Back struct ptr (no need to catch it. It updates it anyway.)
@params: 	1)	Input;

@calls: getter_backend, ft_strlen, set_error, DictCheck
@called by: Main.cpp
*/
Back	*WordSearch(char *input)
{
	t_back_private	*data;

	data = getter_backend(NULL, _NO);
	if (ft_strlen(input) != 5)
		return (set_error(data->back, WRONG_LEN));
	if (!ft_isalpha(input))
		return (set_error(data->back, WRONG_CHAR));
	if (check_guess(data->back, input))
		return (set_error(data->back, RIGHT_INPUT));
	DictCheck(input);
	return (data->back);
}

/*
//REVIEW - DictCheck

@description: 	Checks if word is in dictionary

@returns: 1 if _YES, 0 if _NO
@params: 	1)	Input;

@calls: getter_backend, tokenize, ft_strncmp, set_error
@called by: Main.cpp, WordSearch
*/
bool	DictCheck(char *input)
{
	int				first_l;
	int				second_l;
	int				i;
	t_back_private	*data;

	data = getter_backend(NULL, _NO);
	first_l = tokenize(input[0]);
	second_l = tokenize(input[1]);
	if (!data->words[first_l][second_l].num)
		return (set_error(data->back, NOT_IN_DICTIONARY), _NO);
	i = -1;
	while (data->words[first_l][second_l].num[++i])
	{
		if (!ft_strncmp(input, data->words[first_l][second_l].num[i], 5))
			return (set_error(data->back, RIGHT_INPUT), _YES);
	}
	return (set_error(data->back, NOT_IN_DICTIONARY), _NO);
}

/*
//REVIEW - check_guess

@description: 	Utils of WordSearch. Updates victory to 1 if everything
				is right.

@returns: victory bool
@params: 	1)	Back ptr;
			2)	input.

@calls: ft_strchr
@called by: DictCheck
*/
static int	check_guess(Back *back, char *input)
{
	int	i;
	int	victory;

	i = 0;
	victory = 0;
	while (i != 5)
	{
		if (input[i] == back->rand_word[i])
		{
			back->check_input[i] = 2;
			victory += 1;
		}
		else if (ft_strchr(back->rand_word, input[i]))
			back->check_input[i] = 1;
		else
			back->check_input[i] = 0;
		++i;
	}
	if (victory == 5)
		back->victory = _YES;
	else
		back->victory = _NO;
	return (back->victory);
}

static Back	*set_error(Back *back, int error)
{
	back->valid_input = error;
	return (back);
}
