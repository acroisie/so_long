/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:48:37 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/14 22:16:27 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_object_to_display(t_game game, char c, int x, int y)
{
	if (c == 'E')
		mlx_put_image_to_window(game.mlx, game.mlx_window,
			game.image.closed_exit, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game.mlx, game.mlx_window,
			game.image.key, x, y);
	if (c == 'P')
		mlx_put_image_to_window(game.mlx, game.mlx_window,
			game.image.char_down, x, y);
	if (c == '1')
		mlx_put_image_to_window(game.mlx, game.mlx_window,
			game.image.obstacle, x, y);

}

void	ft_display_floor(t_game game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < game.map.line_count)
	{
		j = 0;
		x = 0;
		while (j < game.map.column_count)
		{
			mlx_put_image_to_window(game.mlx, game.mlx_window,
				game.image.floor, x, y);
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}

void	ft_display_objects(t_game game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < game.map.line_count)
	{
		j = 0;
		x = 0;
		while (j < game.map.column_count)
		{
			ft_object_to_display(game, game.map.map[i][j], x, y);
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}

void	ft_link_images(t_game *game)
{
	int	width;
	int	height;

	game->image.char_down = mlx_xpm_file_to_image(game->mlx,
			"sl_asset/char_down.xpm", &width, &height);
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
}

void	ft_display_map(t_game *game)
{
	ft_link_images(game);
	ft_display_floor(*game);
	ft_display_objects(*game);
}
