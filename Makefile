# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 16:37:05 by hshawand          #+#    #+#              #
#    Updated: 2019/09/17 15:14:34 by hshawand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECTS = srcs/libft/ft_memset.o \
srcs/libft/ft_bzero.o \
srcs/libft/ft_memcpy.o \
srcs/libft/ft_memccpy.o \
srcs/libft/ft_memmove.o \
srcs/libft/ft_memchr.o \
srcs/libft/ft_memcmp.o \
srcs/libft/ft_strlen.o \
srcs/libft/ft_strdup.o \
srcs/libft/ft_strcpy.o \
srcs/libft/ft_strncpy.o \
srcs/libft/ft_strcat.o \
srcs/libft/ft_strncat.o \
srcs/libft/ft_strlcat.o \
srcs/libft/ft_strchr.o \
srcs/libft/ft_strrchr.o \
srcs/libft/ft_strstr.o \
srcs/libft/ft_strnstr.o \
srcs/libft/ft_strcmp.o \
srcs/libft/ft_strncmp.o \
srcs/libft/ft_atoi.o \
srcs/libft/ft_isalpha.o \
srcs/libft/ft_isalnum.o \
srcs/libft/ft_isascii.o \
srcs/libft/ft_isdigit.o \
srcs/libft/ft_isprint.o \
srcs/libft/ft_tolower.o \
srcs/libft/ft_toupper.o \
srcs/libft/ft_itoa.o \
srcs/libft/ft_memalloc.o \
srcs/libft/ft_memdel.o \
srcs/libft/ft_putchar_fd.o \
srcs/libft/ft_putchar.o \
srcs/libft/ft_putendl_fd.o \
srcs/libft/ft_putendl.o \
srcs/libft/ft_putnbr.o \
srcs/libft/ft_putstr_fd.o \
srcs/libft/ft_putstr.o \
srcs/libft/ft_strclr.o \
srcs/libft/ft_strdel.o \
srcs/libft/ft_strequ.o \
srcs/libft/ft_striter.o \
srcs/libft/ft_striteri.o \
srcs/libft/ft_strjoin.o \
srcs/libft/ft_strmap.o \
srcs/libft/ft_strmapi.o \
srcs/libft/ft_strnequ.o \
srcs/libft/ft_strnew.o \
srcs/libft/ft_strsplit.o \
srcs/libft/ft_strsub.o \
srcs/libft/ft_strtrim.o \
srcs/libft/ft_putnbr_fd.o \
srcs/libft/ft_lstadd.o \
srcs/libft/ft_lstdel.o \
srcs/libft/ft_lstdelone.o \
srcs/libft/ft_lstiter.o \
srcs/libft/ft_lstmap.o \
srcs/libft/ft_lstnew.o \
srcs/libft/ft_stroffcat.o

SRCS = srcs/main.c \
srcs/path.c \
srcs/lists.c \
srcs/sort.c \
srcs/print.c \

LIB_NAME = libft.a
NAME = ft_ls

all: $(LIB_NAME)

$(LIB_NAME): $(OBJECTS)
	ar rc $@ $(OBJECTS)
	gcc -Wall -Wextra -Werror $(SRCS) $@ -Iincludes -o $(NAME)

$(OBJECTS): %.o: %.c
	gcc -c -Wall -Wextra -Werror $< -o $@ -Iincludes

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(LIB_NAME)
	rm -f $(NAME)
re: fclean all
