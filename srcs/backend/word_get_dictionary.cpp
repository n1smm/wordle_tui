/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_get_dictionary.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:47:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 19:51:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

static void	realloc_dictionary(char ***dict, int dict_size);

void	insert_one(t_words **words, char *line, char **dict, int *index)
{
	int	first_l;
	int	second_l;
	int	i;

	if (ft_strlen(line) != 5)
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
	dict[(*index)++] = words[first_l][second_l].num[i];
	words[first_l][second_l].last += 1;
}

void	get_dictionary(t_back_private *data)
{
	int		fd;
	int		max_size;
	char	*line;

	fd = open(DICTIONARY_NAME, O_RDONLY, 0666);
	if (fd < 0)
		error_backend(E_OPEN);
	line = get_next_line(fd);
	max_size = 1;
	while (line)
	{
		if (data->dict_size == max_size - 1)
		{
			realloc_dictionary(&data->dictionary, data->dict_size);
			max_size *= 2;
		}
		insert_one(data->words, line, data->dictionary, &data->dict_size);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	realloc_dictionary(char ***dict, int dict_size)
{
	char	**new_dict;
	int		i;

	alloc_word_matrix(&new_dict, dict_size * 2);
	i = 0;
	if (!*dict || !(*dict)[0])
	{
		*dict = new_dict;
		return ;
	}
	while ((*dict)[i])
	{
		new_dict[i] = (*dict)[i];
		++i;
	}
	free(*dict);
	*dict = new_dict;
}
