/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 19:51:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.hpp"

/*
int	main()
{
	char	*new_line;
	int		fd;
	int		max_fd;
	size_t	counter;
	size_t	initial_counter;

	//fd = 3;
	fd = open("updated_pokedex.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	//fd = 4;
	fd = open("tagliatelledinonnapinalyrics.txt", O_RDONLY);
	if (fd == -1)
	{
		fd = 3;
		while (fd != 2)
		{
			close(fd--);
		}
		return (1);
	}
	//fd = 5;
	fd = open("lore_di_bloodborne.txt", O_RDONLY);
	if (fd == -1)
	{
		fd = 4;
		while (fd != 2)
		{
			close(fd--);
		}
		return (1);
	}
	//fd = 6;
	fd = open("empty.txt", O_CREAT);
	if (fd == -1)
	{
		fd = 5;
		while (fd != 2)
		{
			close(fd--);
		}
		return (1);
	}
	max_fd = fd;
	fd = 3;
	counter = COUNTER;
	if (FORCE_READ_ONE_TEXT)
		fd = FORCE_READ_ONE_TEXT;
	initial_counter = counter;
	while (fd < max_fd + 1)
	{
		while (counter--)
		{
			new_line = get_next_line(fd);
			printf("\nNEXT LINE(%zu): \\\\\"%s\"\\\\", \
			initial_counter - counter, new_line);
			if (!new_line)
				break ;
			if (new_line)
				free(new_line);
		}
		if (FORCE_READ_ONE_TEXT)
			break ;
		if (fd != max_fd)
		{
			printf("\n\n\n---------\n\\\\GO TO NEXT TEXT\\\\\n---------\n\n");
		}
		
		counter = initial_counter;
		++fd;
	}
	printf("\n\n\\\\END OF READING\\\\\n\n");
	while (fd != 3)
	{
		close(fd--);
	}
	return (0);
}
*/

char	*get_next_line(int fd)
{
	static char	buffer[1048][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	return (get_next_line_main_function(fd, buffer[fd]));
}

char	*get_next_line_main_function(int fd, char buffer[BUFFER_SIZE + 1])
{
	char	*new_line;
	int		check_newline;
	char	*store_readbytes;

	new_line = NULL;
	check_newline = 0;
	while (buffer[check_newline] && buffer[check_newline] != '\n')
		++check_newline;
	if ((buffer[check_newline] == EMPTY_BUFFER) && (check_newline == 0))
	{
		if (go_read(fd, buffer, &new_line) == END_OR_CORRUPTION)
			return (NULL);
	}
	else
	{
		new_line = get(&store_readbytes, buffer, check_newline, fd);
		if (!new_line)
			return (NULL);
	}
	return (new_line);
}

char	*get(char **store_bytes, char buffer[BUFFER_SIZE + 1], int nl, int fd)
{
	char	*new_line;

	new_line = NULL;
	if (buffer[nl] == NO_NEWLINE_FOUND)
	{
		if (alloc_ft((void **)store_bytes, NULL, nl + 1, MALLOC) == FULL_MEMORY)
			return (NULL);
		calloc_memcpy(nl, *store_bytes, buffer, MEMCPY);
		if (go_read(fd, buffer, &new_line) == END_OR_CORRUPTION)
		{
			trim_readbytes(buffer);
			return (*store_bytes);
		}
		new_line = _ft_strjoin(*store_bytes, new_line);
		if (!new_line)
			return (NULL);
	}
	else if (buffer[nl] != NO_NEWLINE_FOUND)
	{
		if (alloc_ft((void **)&new_line, NULL, nl + 1, MALLOC) == FULL_MEMORY)
			return (NULL);
		calloc_memcpy(nl + 1, new_line, buffer, MEMCPY);
		trim_readbytes(buffer);
	}
	return (new_line);
}

int	go_read(int fd, char buffer[BUFFER_SIZE + 1], char **new_line)
{
	int		control_read;
	size_t	end;
	size_t	size;

	end = 0;
	size = BUFFER_SIZE;
	if (alloc_ft((void **)new_line, NULL, size, MALLOC) == FULL_MEMORY)
		return (alloc_ft((void **)new_line, NULL, 0, FREE));
	if (loop_read(new_line, &control_read, &end, fd) == END_OR_CORRUPTION)
		return (END_OR_CORRUPTION);
	calloc_memcpy(control_read - end - 1, buffer, *new_line + end + 1, MEMCPY);
	if (alloc_ft((void **)new_line, (void *)*new_line, end, REALLOC) == \
	FULL_MEMORY)
		return (alloc_ft((void **)new_line, 0, 0, FREE));
	return (SUCCESS);
}

int	loop_read(char **new_line, int *control_read, size_t *end, int fd)
{
	size_t	size;

	size = BUFFER_SIZE;
	while ("I loop until I find the first occurence of \n or \0 after start:)")
	{
		*control_read = read(fd, (*new_line) + (*end), BUFFER_SIZE);
		if ((*control_read == -1) || ((*control_read == 0) && (*end == 0)))
			return (alloc_ft((void **)new_line, 0, 0, FREE));
		if (*control_read == 0)
			break ;
		*end += *control_read;
		if (*end >= size)
		{
			size *= 2;
			if (alloc_ft((void **)new_line, (void *)*new_line, size + 2, \
			REALLOC) == FULL_MEMORY)
				return (alloc_ft((void **)new_line, 0, 0, FREE));
		}
		(*new_line)[(*end)] = 0;
		*control_read = *end;
		if (find_end_line(end, *new_line) == EOF_OR_NEWLINE_FOUND)
			break ;
	}
	return (SUCCESS);
}
