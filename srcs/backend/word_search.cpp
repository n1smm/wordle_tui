/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_search.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:55:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 17:04:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

static int	check_guess(Back *back, char *input);
static Back	*set_error(Back *back, int error);

Back	*WordSearch(char *input)
{
	int				first_l;
	int				second_l;
	int				i;
	t_back_private	*data;

	data = getter_backend(NULL, _NO);
	if (ft_strlen(input) != 5)
		return (set_error(data->back, WRONG_LEN));
	if (!ft_isalpha(input))
		return (set_error(data->back, WRONG_CHAR));
	if (check_guess(data->back, input))
		return (set_error(data->back, RIGHT_INPUT));
	first_l = tokenize(input[0]);
	second_l = tokenize(input[1]);
	if (!data->words[first_l][second_l].num)
		return (set_error(data->back, NOT_IN_DICTIONARY));
	i = -1;
	while (data->words[first_l][second_l].num[++i])
	{
		if (!ft_strncmp(input, data->words[first_l][second_l].num[i], 5))
			return (set_error(data->back, RIGHT_INPUT));
	}
	return (set_error(data->back, NOT_IN_DICTIONARY));
}
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
