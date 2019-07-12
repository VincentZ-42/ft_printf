# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 16:14:51 by vzhao             #+#    #+#              #
#    Updated: 2019/06/07 15:04:01 by jiliu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = libft.h
FILES =	ft_tolower.c ft_toupper.c \
		ft_isdigit.c ft_isalpha.c ft_isalnum.c \
		ft_isprint.c ft_isascii.c \
		ft_atoi.c ft_strcmp.c ft_strlen.c ft_strncmp.c\
		ft_strchr.c ft_strrchr.c \
		ft_strstr.c ft_strnstr.c \
		ft_strdup.c ft_strncpy.c \
		ft_strcat.c ft_strncat.c ft_strlcat.c \
		ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c \
		ft_strcpy.c \
		\
		ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c \
		ft_strsub.c ft_strtrim.c \
		ft_strjoin.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		\
		ft_is_whitesp.c \
		ft_countwords.c \
		ft_storeword.c \
		ft_int_len.c \
		ft_lstadd_end.c \
		\
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstcount.c \
		ft_freelist.c

SRCS = $(FILES)
OBJS = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -I $(HEAD) -c $(SRCS) 
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
