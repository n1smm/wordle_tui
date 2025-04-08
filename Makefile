# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thiew <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 01:25:37 by thiew             #+#    #+#              #
#    Updated: 2025/04/08 11:58:49 by thiew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = g++
CFLAGS = -Wall -Wextra -Werror --std=c++17 -g
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs
HEADERS = $(wildcard $(INC_DIR)/*.hpp) 
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
NAME = wordle

all : $(NAME)

$(NAME): $(HEADERS) $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir	-p $(dir $@)
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
