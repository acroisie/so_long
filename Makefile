# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 10:04:41 by acroisie          #+#    #+#              #
#    Updated: 2022/02/08 10:34:03 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC := gcc 

CC_FLAGS := -Wall -Werror -Wextra -framework OpenGL -framework AppKit

NAME := so_long

SRCS := main.c \
		error_check_args.c \
		error_check_map.c \
		so_long_utils.c

OBJS := $(SRCS:.c=.o)

all : libft $(NAME)

objs/%.o:	srcs/%.c includes/so_long.h srcs/libft/libft.a
					@mkdir -p objs
					$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME):		libft $(addprefix objs/, $(OBJS)) libmlx $(addprefix objs/, $(OBJS))
					@$(CC) -o $(NAME) $(addprefix objs/, $(OBJS)) srcs/libft/libft.a srcs/mlx/libmlx.a

libft :	
		$(MAKE) -C srcs/libft

mlx :	
		$(MAKE) -C srcs/mlx

clean :
		rm -rf objs
		make clean -C srcs/libft
		make clean -C srcs/mlx

fclean : clean
		 rm -f $(NAME)
		 make fclean -C srcs/libft
		 make fclean -C srcs/mlx

re : fclean all

.PHONY : re clean fclean libft libmlx all