/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:38:09 by thiew             #+#    #+#             */
/*   Updated: 2025/04/08 20:42:02 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "keys.hpp"
#include "assets.hpp"
#include "colors.hpp"

struct winInfo
{
	size_t	width;
	size_t	height;
	size_t field_w;
	size_t field_h;
	size_t 	field_left;
	size_t	field_up;
	size_t	tile_h;
	size_t	tile_w;
};
