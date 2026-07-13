# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/24 16:09:19 by mcastrat          #+#    #+#              #
#    Updated: 2026/04/26 15:08:02 by mcastrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Serializer.cpp
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
