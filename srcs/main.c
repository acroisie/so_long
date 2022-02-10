/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:55:24 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/10 15:47:12 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = ft_error_check(argc, argv);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, 640, 480, "so_long");
	mlx_hook(game.mlx_window, 17, 0L, ft_clean_exit, &game);
	mlx_hook(game.mlx_window, 2, 1L << 0, ft_key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
