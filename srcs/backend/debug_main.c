/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:16:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 18:28:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

/*
//REVIEW - test

@description: frontend demo
@returns: 0 if wrong input, 1 if right input
@params: 
		1)	The string read from user

@calls: getter_backend
		printf
@called by: main
*/
static int	test(char *guess)
{
	t_back_private	*data;
	int				i;

	data = getter_backend(NULL, _NO);
	if (data->back->valid_input == WRONG_LEN)
		printf("Word must be five letters.\n");
	else if (data->back->valid_input == WRONG_CHAR)
		printf("Word must be in the english alphabet, upper/lower case.\n");
	else if (data->back->valid_input == NOT_IN_DICTIONARY)
		printf("Your word is not in the given dictionary.\n");
	if (!data->back->valid_input == RIGHT_INPUT)
		return (0);
	i = 0;
	while (i != 5)
	{
		if (data->back->check_input[i] == RIGHT_LETTER)
			printf("\033[32m%c", guess[i]);
		else if (data->back->check_input[i] == WRONG_POSITION)
			printf("\033[33m%c", guess[i]);
		else if (data->back->check_input[i] == WRONG_LETTER)
			printf("%c", guess[i]);
		printf("\033[0m");
		++i;
	}
	printf("\n");
	return (data->back->victory);
}
/*
//REVIEW - backend debug main

@description: show how to use the functions
@returns: 0
@params: void
@calls: BackendInit, RandomWord, WordSearch, BackendQuit
		printf, read, test
@called by: none
*/
int	main()
{
	char	guess[7];

	guess[5] = '\0';
	guess[6] = '\0';
	BackendInit();
	printf("Random word:\t%s\n", RandomWord());
	printf("Try to guess.\n");
	while (1)
	{
		read(0, guess, 6);
		WordSearch(guess);
		if (test(guess) == 1)
			break ;
	}
	BackendQuit();
	return (0);
}