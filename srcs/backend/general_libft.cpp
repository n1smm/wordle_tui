/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_libft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:55:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 19:48:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

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

size_t	ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while ((s[strlen] && s[strlen] != '\n'))
		++strlen;
	return (strlen);
}

int	ft_isalpha(char *s)
{
	while (*s)
	{
		if (!((*s >= 'a') && (*s <= 'z')) && !((*s >= 'A') && (*s <= 'Z')))
			if (*s != '\n')
				return (0);
		++s;
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		++s;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
