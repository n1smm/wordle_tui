/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:35:09 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 16:33:33 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int getRandomNumber(int min, int max)
{
    std::random_device rd; // Seed for random number engine
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(min, max); // Uniform distribution
    return dis(gen);
}


void	cleanup()
{
	setNonCanonicalMode(false);
}

void die(int i)
{
	(void)i;
	g_exit_flag = true;
}
