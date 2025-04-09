/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:07:14 by tjuvan            #+#    #+#             */
/*   Updated: 2023/12/05 13:14:32 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
/* for tests */
/* # include <stdio.h> */
/* # include <string.h> */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_storage;

/* main file */
char				*copy_to_result(t_storage *root);
int					read_to_storage(int fd, t_storage **root);
void				re_start_list(t_storage **root, char *line, int count,
						int file_read);
char				*get_next_line(int fd);
void				*ft_calloc(unsigned long nmemb, unsigned long size);
int					final_free(t_storage **root, char *rest, char *line,
						int file_read);
/* utils file */
t_storage			*ft_lstlast(t_storage *root);
int					count_line(t_storage *root);
void				ft_lstadd_back(char *content, t_storage **root);
void				deallocate(t_storage **root);
int					check_list(t_storage *root);

#endif
