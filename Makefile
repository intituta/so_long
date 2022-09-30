# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 17:42:33 by kferterb          #+#    #+#              #
#    Updated: 2021/11/28 18:21:30 by kferterb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
#
SOURSE		=	so_long.c\
				putnbr.c\
				key_hook.c\
				gnl.c\
				errors.c\
				draw_map.c\
				check_string.c\
				check_objects.c
# 
CFLAGS		= -Wall -Werror -Wextra -I $(HEADER)
HEADER		= so_long.h
OBJ = $(SOURSE:%.c=%.o)
CC = gcc
#
.PHONY : all clean fclean re bonus
#
all : $(NAME)
#
$(NAME) : $(OBJ) $(HEADER) $(HEADER_2)
	$(CC) $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SOURSE) -o $(NAME)
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	@rm -f $(OBJ)
#
fclean : clean
	@rm -f $(NAME)
#
re : fclean all