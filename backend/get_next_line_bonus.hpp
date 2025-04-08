/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/08 13:51:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Static memory used ---> BUFFER_SIZE * 4000
#ifndef GET_NEXT_LINE_BONUS_HPP
# define GET_NEXT_LINE_BONUS_HPP
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif
// Define for debug purposes
# define COUNTER 100000000
# define FORCE_READ_ONE_TEXT 0
// Defines used in program
# define MALLOC 1
# define REALLOC 2
# define FREE 3
# define CALLOC 4
# define MEMCPY 5
# define FULL_MEMORY -1
# define SUCCESS 1
# define NO_NEWLINE_FOUND 0
# define EOF_OR_NEWLINE_FOUND 1
# define EOF_OR_NEWLINE_NOT_FOUND -1
# define EMPTY_BUFFER 0
# define END_OR_CORRUPTION -1
// Libraries
# include <unistd.h>
# include <stdio.h>
# include <malloc.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*get_next_line_main_function(int fd, char buffer[BUFFER_SIZE + 1]);
char	*get(char **store_bytes, char buffer[BUFFER_SIZE + 1], int nl, int fd);
int		go_read(int fd, char buffer[BUFFER_SIZE + 1], char **new_line);
int		loop_read(char **new_line, int *control_read, size_t *end, int fd);
int		alloc_ft(void **content, void *new_content, size_t start, int mode);
int		find_end_line(size_t *start, char *string);
void	*calloc_memcpy(int size, char *dest, char *src, int ft);
void	trim_readbytes(char *buffer);
char	*_ft_strjoin(char *s1, char *s2);

#endif