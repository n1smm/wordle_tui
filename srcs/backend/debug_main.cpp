/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:16:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 15:27:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

int	main()
{
	char	guess[6];

	BackendInit();
	printf("Random word:\t%s\n", RandomWord());
	printf("Try to guess.\n");
	read(0, guess, 5);
	BackendQuit();
	return (0);
}