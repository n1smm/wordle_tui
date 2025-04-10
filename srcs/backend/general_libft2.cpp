/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_libft2.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:13:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/10 10:43:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

int	tokenize(char c);

int	tokenize(char c)
{
	char	token;

	if (c >= 'A' && c <= 'Z')
		token = c - 'A';
	else if (c >= 'a' && c <= 'z')
		token = c - 'a';
	else
		token = 0;
	return ((int)token);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((--n) && (*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
