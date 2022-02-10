# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 10:04:41 by acroisie          #+#    #+#              #
#    Updated: 2022/02/10 15:43:44 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC := gcc 

CC_FLAGS := -Wall -Werror -Wextra 

NAME := so_long

SRCS := main.c \
		error_check_args.c \
		error_check_map.c \
		so_long_utils.c	\
		get_next_line.c \
		move_avatar.c

OBJS := $(SRCS:.c=.o)

all : libft $(NAME)


$(NAME):		libft mlx $(addprefix objs/, $(OBJS))
					@$(CC) -o $(NAME) $(addprefix objs/, $(OBJS)) srcs/libft/libft.a srcs/mlx/libmlx.a -framework OpenGL -framework AppKit

objs/%.o:srcs/%.c include/so_long.h include/get_next_line.h srcs/libft/libft.a srcs/mlx/libmlx.a
					@mkdir -p objs
					$(CC) $(CC_FLAGS) -c $< -o $@

libft :	
		$(MAKE) -C srcs/libft

mlx :	
		$(MAKE) -C srcs/mlx

clean :
		rm -rf objs
		make clean -C srcs/libft

fclean : clean
		rm -f $(NAME)
		make fclean -C srcs/libft
		make clean -C srcs/mlx

re : fclean all

.PHONY : re clean fclean libft mlx all