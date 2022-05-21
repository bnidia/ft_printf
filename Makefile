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

# Manual for Makefile
# https://www.gnu.org/software/make/manual/html_node/index.html
NAME 	= libftprintf.a

SRCDIR = ./
OBJDIR = ./obj/

SRC	= ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_p.c ft_printf_s.c
SRC	+= ft_printf_u.c ft_printf_x.c ft_print_out.c reset_width_precision.c
SRC += ft_itoa_base.c ft_printf_common_functions.c
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
D_FILES = $(addprefix $(OBJDIR), $(notdir$(SRC:.c=.d)))
HEADER = ft_printf.h

CC = gcc -Werror -Wall -Wextra
DEBUG_SWITCH = TRUE
ifeq ($(DEBUG_SWITCH), TRUE)
	DEBUG = -g
else
	OPTIMIZATION = -O1
endif

all: $(NAME)

# translation of assembly language code into machine code
# -c, stops after assembly stage
# -MD lists both system header files and user header files, dependencies
# -MMD lists only user header files, dependencies
# $< the first prerequisite (usually a source file) main.c (dependency %.c)
# $@ is the name of the target being generated main.o (target %.o)
$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER) | obj
	$(CC) $(DEBUG) $(OPTIMIZATION) -c $< -o $@ -MMD

# arc stage
$(NAME): $(OBJ)
	make -C ./libraries/libft/
	cp ./libraries/libft/libft.a $(NAME)
	ar rcs $@ $^

obj:
	mkdir -p $(OBJDIR)

include $(wildcard $(D_FILES))

bonus: all

norm:
	norminette $(SRC) $(HEADER)

test:
	make all
	gcc -g main.c libftprintf.a -o test #&& ./test | cat -e

test1:
	echo "paulo-santana/ft_printf_tester"
	git clone https://github.com/rustem-spb/ft_printf_tester.git
#	git clone https://github.com/paulo-santana/ft_printf_tester.git
	bash -c "cd ft_printf_tester && sh test"
	rm -rf ft_printf_tester
test11:
	bash -c "cd ft_printf_tester && sh test"

test2:
	echo "Tripouille/printfTester"
	git clone https://github.com/Tripouille/printfTester.git
	make a -C ./printfTester/
	rm -rf printfTester

# rule for the cleaning
clean:
	make clean -C ./libraries/libft/
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C ./libraries/libft/
	rm -rf $(OBJDIR) $(NAME)

# rule for rebuild a project
re: fclean all

# directory exceptions
.PHONY: all clean fclean norm re bonus test test1 test2
