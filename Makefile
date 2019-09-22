# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 12:58:07 by hshawand          #+#    #+#              #
#    Updated: 2019/09/22 13:29:38 by hshawand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = srcs/buffer.o \
	   srcs/lists.o \
	   srcs/main.o \
	   srcs/path.o \
	   srcs/print.o \
	   srcs/sort.o \
	   srcs/utils.o 

LIB_NAME = srcs/libft/libft.a
NAME = ft_ls

all: $(NAME) 
	
$(NAME): $(OBJS)
	make -C srcs/libft
	gcc -Wall -Wextra -Werror $(OBJS) $(LIB_NAME) -o $@

$(OBJS): %.o: %.c
	gcc -c -Wall -Wextra -Werror $< -o $@ -I./includes -I./srcs/libft

clean:
	make -C srcs/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C srcs/libft fclean
	rm -f $(NAME)

re: fclean all
