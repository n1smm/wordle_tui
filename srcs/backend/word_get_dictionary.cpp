/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_get_dictionary.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:47:56 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/10 15:46:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.hpp"

static void	realloc_dictionary(char ***dict, int dict_size);

/*
//REVIEW - insert_one

@description: 	Insert one word from the dictionary, if:
				Len is == 5;
				Is in the english alphabet.

@returns: none
@params: 	1)	Matrix of words;
			2)	Line taken from DICTIONARY_NAME file;
			3)	Matrix of words in the dictionary;
			4)	Ptr to the size of the dictionary.
@calls: getter_backend, error_backend, ft_calloc
		alloc_back_struct, alloc_word_matrix, get_dictionary
@called by: Main.cpp
*/
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

/*
//REVIEW - get_dictionary

@description: 	Get data from DICTIONARY_NAME. Puts data in a general
				matrix and in matrixes for every initial of letters (a-a, a-b)

@returns: none
@params: none
@calls: getter_backend, error_backend, open, get_next_line, insert_one, close
@called by: BackendInit
*/
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

/*
//REVIEW - realloc_dictionary

@description: 	Double the size of the general dictionary

@returns: none
@params: 	1)	Ptr of the general dictionary;
			2)	Current dictionary size.

@calls: alloc_word_matrix, free
@called by: get_dictionary
*/
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
