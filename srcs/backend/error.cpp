/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:33:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 19:48:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

/*
//REVIEW - backend debug main

@description: 	If something goes REALLY bad in backend execution, kills the
				process, freeing backend data.

@returns: 0 (exit)
@params: A enum with the error

@calls: debugPrint, BackendPrint, 
		exit
@called by: 
			[E_MALLOC]
			alloc_back_struct, alloc_word_matrix, BackendInit
			[E_OPEN]
			get_dictionary
*/
int	error_backend(int error_type)
{
	if (error_type == E_MALLOC)
		debugPrint("Backend:\tmalloc failure\n");
	else if (error_type == E_OPEN)
		debugPrint("Backend:\nopen failure\n");
	BackendQuit();
	exit(1);
	return (0);
}
