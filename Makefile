# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 19:16:59 by bnidia            #+#    #+#              #
#    Updated: 2021/10/26 16:05:02 by bnidia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a

SRCS	= ft_printf.c ft_printf_utils.c
OBJ		= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	cc -Wall -Werror -Wextra -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
