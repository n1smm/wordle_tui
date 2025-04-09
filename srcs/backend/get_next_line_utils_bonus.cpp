/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:22 by tjuvan            #+#    #+#             */
/*   Updated: 2025/04/09 20:51:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.hpp"

t_storage	*ft_lstlast(t_storage *root)
{
	if (!root)
		return (NULL);
	while (root->next != NULL)
		root = root->next;
	return (root);
}

void	deallocate(t_storage **root)
{
	t_storage	*tmp;
	t_storage	*curr;

	curr = *root;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		if (tmp->content != NULL)
			free(tmp->content);
		free(tmp);
	}
	*root = NULL;
}

void	ft_lstadd_back(char *content, t_storage **root)
{
	t_storage	*curr;
	t_storage	*new_ptr;

	new_ptr = (t_storage *)malloc(sizeof(t_storage));
	if (!new_ptr || !content)
		return ;
	new_ptr->content = content;
	new_ptr->next = NULL;
	if (*root == NULL)
	{
		*root = new_ptr;
		return ;
	}
	curr = ft_lstlast(*root);
	curr->next = new_ptr;
}

int	count_line(t_storage *root)
{
	t_storage	*curr;
	int			count;
	int			count_len;

	curr = root;
	count_len = 0;
	while (curr != NULL)
	{
		count = 0;
		while (curr->content[count] != 0)
		{
			if (curr->content[count] == '\n')
				return (count_len + 1);
			count++;
			count_len++;
		}
		curr = curr->next;
	}
	return (count_len);
}

int	check_list(t_storage *root)
{
	t_storage	*curr;
	int			count;

	curr = ft_lstlast(root);
	if (curr == NULL)
		return (-1);
	while (curr != NULL)
	{
		count = 0;
		while (curr->content[count] != 0)
		{
			if (curr->content[count] == '\n')
				return (0);
			count++;
		}
		curr = curr->next;
	}
	return (1);
}
