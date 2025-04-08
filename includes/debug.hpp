/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:24:21 by tjuvan            #+#    #+#             */
/*   Updated: 2025/04/01 09:17:40 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "externLibs.hpp"

template<typename... Args>
void	debugPrint(Args... args)
{
	std::ofstream debugFile("debug.log", std::ios::app);
	if (debugFile.is_open())
	{
		((debugFile << args << " "), ...) << std::endl;
		debugFile.close();
	}
	else
		std::cerr << "failed to open debug.log" << std::endl;
}


