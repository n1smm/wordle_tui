/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_get_dictionary.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:47:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 12:42:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

void	insert_one(t_words **words, char *line, char *debug[30000], int *index)
{
	int	first_l;
	int	second_l;
	int	i;

	if (ft_strlen(line) != 6)
		return (free(line));
	line[5] = 0;
	if (!ft_isalpha(line))
		return (free(line));
	first_l = tokenize(line[0]);
	second_l = tokenize(line[1]);
	if (words[first_l][second_l].size == words[first_l][second_l].last)
		realloc_word_matrix(&words[first_l][second_l]);
	i = 0;
	while (words[first_l][second_l].num[i])
		++i;
	words[first_l][second_l].num[i] = line;
	debug[(*index)++] = words[first_l][second_l].num[i];
	words[first_l][second_l].last += 1;
}

void	get_dictionary(t_back_private *data)
{
	int		fd;
	char	*line;

	fd = open("words.txt", O_RDONLY, 0666);
	line = get_next_line(fd);
	while (line)
	{
		insert_one(data->words, line, data->debug, &data->index);
		line = get_next_line(fd);
	}
	close(fd);
}
