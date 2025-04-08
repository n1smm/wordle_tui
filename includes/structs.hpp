/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:38:09 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 11:57:18 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "keys.hpp"
#include "assets.hpp"
#include "colors.hpp"

struct winInfo
{
	ssize_t	width;
	ssize_t	height;
	ssize_t field_w;
	ssize_t field_h;
	size_t 	field_left;
	size_t	field_up;
};
