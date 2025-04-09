/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_sort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:42:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 18:46:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

char	*RandomWord(void)
{
	struct timeval	time_values;
	int				random_index;
	t_back_private	*data;

	data = getter_backend(NULL, _NO);
	gettimeofday(&time_values, NULL);
	random_index = time_values.tv_usec % data->dict_size;
	data->back->rand_word = data->dictionary[random_index];
	return (data->dictionary[random_index]);
}
