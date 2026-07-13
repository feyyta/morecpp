# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastrat <mcastrat@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/26 15:08:51 by mcastrat          #+#    #+#              #
#    Updated: 2026/04/26 16:10:42 by mcastrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = id
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Base.cpp ft.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
