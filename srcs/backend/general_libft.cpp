/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_libft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:55:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/10 14:52:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

/*
//REVIEW - ft_memset

@description: set memory to c for n bytes
@returns: s ptr
@params: 
		1)	The s ptr;
		2)	The c char to set in the memory;
		3)	The n bytes to set.

@calls: none
@called by: ft_calloc
*/
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

/*
//REVIEW - ft_calloc

@description: Alloc memory, setting it to 0 (pointers become NULL)
@returns: void ptr
@params: 
		1)	The number of elements to alloc;
		2)	The size of every member (sizeof(int), sizeof(char)...);

@calls: malloc, ft_memset
@called by: alloc_back_struct, alloc_word_matrix, BackendInit
*/
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

/*
//REVIEW - ft_strlen

@description: Counts lenght of string until \0 \n
@returns: size
@params: 
		1)	String

@calls: none
@called by: get_dictionary, WordSearch
*/
size_t	ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while ((s[strlen] && s[strlen] != '\n'))
		++strlen;
	return (strlen);
}

/*
//REVIEW - ft_isalpha

@description: Returns 0 if string is NOT alphabetic, 1 if it is 
@returns: size
@params: 
		1)	String

@calls: none
@called by: get_dictionary, WordSearch
*/
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

/*
//REVIEW - ft_strchr

@description: Returns 0 if string is NOT alphabetic, 1 if it is 
@returns: size
@params: 
		1)	String

@calls: none
@called by: check_guess
*/
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
