# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 10:04:41 by acroisie          #+#    #+#              #
#    Updated: 2022/02/16 08:44:57 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc 

CC_FLAGS = -Wall -Werror -Wextra

NAME := so_long

SRCS := main.c \
		error_check_args.c \
		error_check_map.c \
		so_long_utils.c	\
		get_next_line.c \
		move_avatar_part_1.c \
		move_avatar_part_2.c \
		move_avatar_part_3.c \
		image_utils.c

OBJS := $(SRCS:.c=.o)

all : libft $(NAME)


$(NAME):		libft mlx $(addprefix objs/, $(OBJS)) Makefile
					$(CC) -o $(NAME) $(addprefix objs/, $(OBJS)) libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit

objs/%.o:		srcs/%.c include/so_long.h include/get_next_line.h libft/libft.a mlx/libmlx.a
					@mkdir -p objs
					$(CC) $(CC_FLAGS) -c $< -o $@

libft :	
		$(MAKE) -C libft

mlx :	
		$(MAKE) -C mlx

clean :
		rm -rf objs
		make clean -C libft
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make fclean -C libft
		make fclean -C mlx

re : fclean all

.PHONY : re clean fclean libft mlx all