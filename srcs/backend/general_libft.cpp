/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_libft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:55:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/08 16:56:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*string_pointer;

	string_pointer = (unsigned char *)s;
	while (n--)
	{
		*string_pointer++ = (unsigned char)c;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	pointer = NULL;
	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	total_size = (nmemb * size);
	if (total_size / nmemb != size)
		return (NULL);
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	ft_memset(pointer, 0, total_size);
	return (pointer);
}
