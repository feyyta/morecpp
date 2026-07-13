# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/24 15:13:52 by mcastrat          #+#    #+#              #
#    Updated: 2026/04/24 16:09:35 by mcastrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = converter
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp ScalarConverter.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
