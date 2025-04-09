/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:23:34 by tjuvan            #+#    #+#             */
/*   Updated: 2025/04/09 20:51:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.hpp"

char	*copy_to_result(t_storage *root)
{
	char		*result;
	t_storage	*curr;
	int			count_node;
	int			count_full;

	count_full = 0;
	result = (char *)malloc(count_line(root) + 1);
	if (!result || ft_lstlast(root) == NULL)
		return (NULL);
	curr = root;
	while (curr != NULL)
	{
		count_node = 0;
		while (curr->content[count_node] != 0
			&& curr->content[count_node] != '\n')
			result[count_full++] = curr->content[count_node++];
		curr = curr->next;
	}
	curr = ft_lstlast(root);
	if (curr->content[count_node] == '\n')
		result[count_full++] = '\n';
	result[count_full] = 0;
	return (result);
}

int	read_to_storage(int fd, t_storage **root)
{
	char	*buff;
	int		len;

	len = 0;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	len = read(fd, buff, BUFFER_SIZE);
	if (len <= 0)
		buff[0] = 0;
	else
		buff[len] = 0;
	ft_lstadd_back(buff, root);
	if (ft_lstlast(*root) == NULL)
		return (0);
	if (len < 0)
		return (-1);
	return (len);
}

int	final_free(t_storage **root, char *rest, char *line, int file_read)
{
	int	no_more;

	no_more = 0;
	if (!rest || !line)
	{
		deallocate(root);
		if (!line)
			free(rest);
		else if (!rest)
			free(line);
		no_more = 1;
	}
	if (file_read == 0 || file_read == -1)
	{
		rest = NULL;
		if (no_more == 1)
		{
			free(line);
			line = NULL;
		}
		return (0);
	}
	else
		return (1);
}

void	re_start_list(t_storage **root, char *line, int count, int file_read)
{
	char		*rest;
	int			count_rest;
	t_storage	*curr;
	t_storage	*new_ptr;

	count_rest = 0;
	rest = (char *)malloc(BUFFER_SIZE + 1);
	if (file_read <= 0 && check_list(*root) == 1)
	{
		deallocate(root);
		free(rest);
		return ;
	}
	if (final_free(root, rest, line, file_read) == 0)
		return ;
	new_ptr = NULL;
	curr = ft_lstlast(*root);
	while (curr->content[count] != 0 && curr->content[count] != '\n')
		count++;
	while (curr->content[count++] != 0)
		rest[count_rest++] = curr->content[count];
	rest[count_rest] = 0;
	deallocate(root);
	ft_lstadd_back(rest, &new_ptr);
	*root = new_ptr;
}

char	*get_next_line(int fd)
{
	static t_storage	*full_buffer[1024];
	char				*line;
	int					file_read;

	file_read = -2;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else if (check_list(full_buffer[fd]) != 0)
	{
		while (file_read > 0 || file_read == -2)
		{
			file_read = read_to_storage(fd, &full_buffer[fd]);
			if (check_list(full_buffer[fd]) == 0
				|| ft_lstlast(full_buffer[fd]) == NULL)
				break ;
		}
	}
	line = copy_to_result(full_buffer[fd]);
	re_start_list(&full_buffer[fd], line, 0, file_read);
	if (line == NULL || line[0] == 0 || file_read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*result;
	int		i;

	i = 0;
	fd = open("/dev/pts/1", O_RDONLY);
	while (i < 5)
	{
		result = get_next_line(fd);
		printf("line %i: %s", i + 1, result);
		if (result != NULL)
			free(result);
		i++;
	}
	close(fd);
	result = get_next_line(fd);
	printf("line %i: %s", i + 1, result);
	if (result != NULL)
		free(result);

}*/
