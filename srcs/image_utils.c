/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:48:37 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/14 16:43:43 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_link_images(t_game *game)
{
	int	width;
	int	height;

	game->image.char_down = mlx_xpm_file_to_image(game->mlx,
			"./srcs/sl_asset/char_down.xpm", &width, &height);
	game->image.char_left = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/char_left.xpm", &width, &height);
	game->image.char_right = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/char_right.xpm", &width, &height);
	game->image.char_up = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/char_up.xpm", &width, &height);
	game->image.closed_exit = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/closed_exit.xpm", &width, &height);
	game->image.floor = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/floor.xpm", &width, &height);
	game->image.key = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/key.xpm", &width, &height);
	game->image.obstacle = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/obstacle.xpm", &width, &height);
	game->image.opened_exit = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/opened_exit.xpm", &width, &height);
	// game->image.char_down = mlx_xpm_file_to_image(game->mlx, "./srcs/sl_asset/char_down.xpm", &a, &b);
}

void	ft_display_map(t_game game)
{
	dprintf(2, "ïci\n");
	mlx_put_image_to_window(game.mlx, game.mlx_window, game.image.char_down, 10, 10);
	dprintf(2, "la\n");
}
