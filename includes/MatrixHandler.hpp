/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatrixHandler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:42:12 by thiew             #+#    #+#             */
/*   Updated: 2025/04/09 11:29:31 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "externLibs.hpp"
#include "assets.hpp"
#include "colors.hpp"


class MatrixHandler
{
	public:
		MatrixHandler( void );
		void		draw();
		void		recalculate();
		void		rows();
		void		tile(size_t pos_x, size_t pos_y);

	private:
		std::vector<std::vector<const char *>>	_draw_matrix;


};
