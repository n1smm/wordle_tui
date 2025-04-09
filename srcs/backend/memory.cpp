/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:04:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 19:51:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

t_back_private	*getter_backend(t_back_private *data, char update);

t_back_private	*getter_backend(t_back_private *data, char update)
{
	static t_back_private	*store;

	if (update)
		store = data;
	return (store);
}

Back	*BackendInit(void)
{
	t_back_private	*mem;
	static int		i;
	int				j;

	if (getter_backend(NULL, _NO))
		return (NULL);
	mem = (t_back_private *)ft_calloc(1, sizeof(t_back_private));
	if (!mem)
		error_backend(E_MALLOC);
	getter_backend(mem, _YES);
	mem->back = (Back *)ft_calloc(1, sizeof(Back));
	if (!mem->back)
		error_backend(E_MALLOC);
	alloc_back_struct(&mem->words, ALPHABET_SIZE);
	while (i != ALPHABET_SIZE)
	{
		j = -1;
		while (++j != ALPHABET_SIZE)
		{
			alloc_word_matrix(&mem->words[i][j].num, 0);
			mem->words[i][j].size = 1;
		}
		++i;
	}
	return (get_dictionary(mem), mem->back);
}

void	*BackendQuit(void)
{
	t_back_private	*mem;
	int				i;
	int				j;

	mem = getter_backend(NULL, _NO);
	if (!mem)
		return (NULL);
	free_and_null((void **)&mem->back);
	if (!mem->words)
		return (NULL);
	i = -1;
	while (++i != ALPHABET_SIZE)
	{
		j = -1;
		while (++j != ALPHABET_SIZE)
			free_matrix((void ***)&mem->words[i][j].num);
	}
	free_matrix((void ***)&mem->words);
	free_and_null((void **)&mem->dictionary);
	free_and_null((void **)&mem);
	getter_backend(NULL, _YES);
	return (NULL);
}