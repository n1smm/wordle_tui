/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_memory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:58:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/10 15:13:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

/*
//REVIEW - alloc_back_struct

@description: 	Alloc the struct used for backend
@returns: Token
@params: 
		1)	ptr to struct
		2)	number of valid characters (ALPHABET_SIZE)

@calls: ft_calloc, error_backend
@called by: BackendInit
*/
void	alloc_back_struct(t_words ***word_struct, int nmemb)
{
	int	i;

	*word_struct = (t_words **)ft_calloc(nmemb + 2, sizeof(t_words *));
	if (!*word_struct)
		error_backend(E_MALLOC);
	i = 0;
	while (i != nmemb)
	{
		(*word_struct)[i] = (t_words *)ft_calloc(nmemb + 2, sizeof(t_words));
		if (!(*word_struct)[i])
			error_backend(E_MALLOC);
		++i;
	}
}

/*
//REVIEW - alloc_word_matrix

@description: 	Alloc the struct used for combination of letter
				Every initials of letters (a-a, a-b, a-c ... z-z)
				has its own matrix.
				This function allocates it.
@returns: none
@params: 
		1)	ptr to struct
		2)	number of words that can be put into matrix (initially, zero).

@calls: ft_calloc, error_backend
@called by: BackendInit
*/
void	alloc_word_matrix(char ***word_matrix, int nmemb)
{
	*word_matrix = (char **)ft_calloc(nmemb + 2, sizeof(char *));
	if (!*word_matrix)
		error_backend(E_MALLOC);
}

/*
//REVIEW - realloc_word_matrix

@description: 	Alloc the struct used for combination of letter
				Every initials of letters (a-a, a-b, a-c ... z-z)
				has its own matrix.
				This function allocates it.
@returns: none
@params: 
		1)	Address of word matrix

@calls: alloc_word_matrix, free
@called by: get_dictionary
*/
void	realloc_word_matrix(t_words *words)
{
	char	**new_matrix;
	int		i;

	words->size *= 2;
	alloc_word_matrix(&new_matrix, words->size);
	i = 0;
	while (words->num[i])
	{
		new_matrix[i] = words->num[i];
		++i;
	}
	free(words->num);
	words->num = new_matrix;
}

/*
//REVIEW - free_matrix

@description: 	Free a generic matrix
@returns: NULL
@params: 
		1)	Address of matrix

@calls: free
@called by: BackendQuit
*/
void	*free_matrix(void ***matrix)
{
	int	index;

	index = 0;
	if (!*matrix)
		return (NULL);
	while ((*matrix)[index])
	{
		if ((*matrix)[index])
			free((*matrix)[index]);
		(*matrix)[index] = NULL;
		++index;
	}
	free(*matrix);
	return (NULL);
}

/*
//REVIEW - free_matrix

@description: 	Free and set to NULL
@returns: none
@params: 
		1)	Address of memory heap ptr

@calls: free
@called by: BackendQuit
*/
void	free_and_null(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
