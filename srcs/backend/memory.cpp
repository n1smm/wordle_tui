/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:04:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/08 17:22:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

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
	int				i;

	if (getter_backend(NULL, _NO))
		return ;
	mem = (t_back_private *)ft_calloc(1, sizeof(t_back_private));
	if (!mem)
		error_backend(E_MALLOC);
	getter_backend(mem, _YES);
	mem->back = (Back *)ft_calloc(1, sizeof(Back));
	if (!mem->back)
		error_backend(E_MALLOC);
	mem->words = (t_words **)ft_calloc(LETTERS_NUM, sizeof(t_words *));
	if (!mem->words)
		error_backend(E_MALLOC);
	i = 0;
	while (i != 104)
	{
		mem->words[i] = (t_words *)ft_calloc(LETTERS_NUM, sizeof(t_words));
		if (!mem->words[i])
			error_backend(E_MALLOC);
		++i;
	}
}

void	BackendQuit(void)
{
	t_back_private	*memory;

	memory = getter_backend(NULL, _NO);
	if (!memory)
		return ;
	
}