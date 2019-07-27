# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 12:47:02 by vzhao             #+#    #+#              #
#    Updated: 2019/07/27 09:42:27 by vzhao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft
INC = srcs
FILES = ft_printf.c \
		get_info.c \
		check_is.c \
		cspdif_func.c \
		uoxmod_func.c \
		handle.c \
		apply.c \
		apply_extra.c \
		f_apply.c
SRCS = $(patsubst %,$(INC)/%,$(FILES))
LIBOBJS = $(LIB)/*.o
OBJS = $(FILES:%.c=%.o)
FLAGS = -Wall -Wextra -Werror -I $(INC)

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS) $(LIBOBJS)
	@ranlib $(NAME)
	@gcc $(FLAGS) -I $(LIB) -L. -lftprintf -o test_ftprintf main.c

clean:
	@/bin/rm -f $(OBJS)
	@make clean -C $(LIB)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB)
	@/bin/rm -f test_ftprintf

re: fclean all

test: re
	@echo "-----------------------------------------------------------------"
	@./test_ftprintf
	@echo "-----------------------------------------------------------------"

.PHONY: clean fclean re all
