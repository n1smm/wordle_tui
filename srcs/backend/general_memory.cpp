/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_memory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:58:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 11:49:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

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

void	alloc_word_matrix(char ***word_matrix, int nmemb)
{
	*word_matrix = (char **)ft_calloc(nmemb + 2, sizeof(char *));
	if (!*word_matrix)
		error_backend(E_MALLOC);
}

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
	Always return NULL
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

void	free_and_null(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
