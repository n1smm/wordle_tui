# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 15:16:55 by alerusso          #+#    #+#              #
#    Updated: 2025/04/08 15:55:35 by alerusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = g++
CFLAGS = -Wall -Wextra -Werror --std=c++17 -g
INC_DIR = includes
SRC_DIR = ./
OBJ_DIR = objs
HEADERS = $(wildcard $(INC_DIR)/*.hpp)
SRC = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
NAME = wordle

all : $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all