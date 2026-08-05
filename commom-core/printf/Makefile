# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/30 22:04:19 by vneves-c          #+#    #+#              #
#    Updated: 2026/07/30 22:04:19 by vneves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= printf.a

CC		= cc
CCFLAGS = -Wall -Wextra -Werror

SRC		= ft_printf.c ft_print_char.c ft_print_string.c ft_print_decimal.c \
			ft_print_hexa.c ft_print_pointer.c ft_print_unsigned.c \
			ft_check_symbol.c

OBJ		= $(SRC:.c=.o)

all: ${NAME}

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
