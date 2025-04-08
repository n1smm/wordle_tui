/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:33:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/08 17:14:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

int	error_backend(int error_type)
{
	if (error_type == E_MALLOC)
		debugPrint("Backend:\tmalloc failure\n");
	BackendQuit();
	exit(1);
}