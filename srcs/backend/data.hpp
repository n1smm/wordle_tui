/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:32:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/09 13:07:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <sys/time.h>
# include "get_next_line_bonus.hpp"
# include "../../includes/externLibs.hpp"

/*NOTE - 

backend functions:
- random word
- user input
- check if valid word - returns enums with error codes
- check valid positions - returns std::vector with codes in right positions
- sth used chars - returns std::vector with codes in right positions

//TODO - 
1)	Random word generator;		//TODO - 
2)	Tree struct to find word;	//TODO -
3)	Check user input;			//TODO -
4)	Study vectors.				//TODO - 
*/

/*
//REVIEW - struct s_back

	@rand_word:	 	The word to guess
	@user_input: 	The word chosen by user
	@check_input: 	String (or vector if I am able) that stores what colors to
					print;
	@valid_input:	Data that store errors in input validation;
	@victory:		Bool data that store if the user has won.
*/
typedef struct Back
{
	char	*rand_word;
	char	*user_input;
	char	*check_input;
	char	valid_input:2;
	char	victory:1;
}Back;

typedef struct s_words
{
	char	**num;
	int		size;
	int		last;
}t_words;

typedef struct s_back_private
{
	t_words	**words;
	char	*debug[30000];
	int		index;
	Back	*back;
}t_back_private;

enum	Alphabet
{
	LETTER_A,
	LETTER_B,
	LETTER_C,
	LETTER_D,
	LETTER_E,
	LETTER_F,
	LETTER_G,
	LETTER_H,
	LETTER_I,
	LETTER_J,
	LETTER_K,
	LETTER_L,
	LETTER_M,
	LETTER_N,
	LETTER_O,
	LETTER_P,
	LETTER_Q,
	LETTER_R,
	LETTER_S,
	LETTER_T,
	LETTER_U,
	LETTER_V,
	LETTER_W,
	LETTER_X,
	LETTER_Y,
	LETTER_Z,
	ALPHABET_SIZE,
};

enum CheckInput
{
	WRONG_LETTER,
	WRONG_POSITION,
	RIGHT_LETTER,
};

enum e_bools
{
	_NO,
	_YES,
};

enum e_errors
{
	E_MALLOC,
};

//NOTE - Includes functions (../../includes)

//NOTE - Private functions internal for backend

t_back_private	*getter_backend(t_back_private *data, char update);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_strlen(const char *s);
int				ft_isalpha(char *s);
int				tokenize(char c);
int				error_backend(int error_type);
void			alloc_back_struct(t_words ***word_struct, int nmemb);
void			alloc_word_matrix(char ***word_matrix, int nmemb);
void			realloc_word_matrix(t_words *words);
void			*free_matrix(void ***matrix);
void			free_and_null(void **ptr);
void			get_dictionary(t_back_private *data);

//NOTE - Public functions to use in frontend

Back	*BackendInit(void);
void	*BackendQuit(void);

#endif