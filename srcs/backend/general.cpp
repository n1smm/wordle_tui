/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:13:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 11:27:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

int	tokenize(char c);

int	tokenize(char c)
{
	char	token;

	if (c <= 'Z')
		token = c - 'A';
	else
		token = c - 'a';
	return ((int)token);
}