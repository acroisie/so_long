/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_avatar_part_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:35:34 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/15 16:09:09 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_display_floor_tile(t_game *game)
{
	game->map.map[game->map.pos_p_y][game->map.pos_p_x] = '0';
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image.floor, (game->map.pos_p_x * 32),
		(game->map.pos_p_y * 32));
	game->map.key_count++;
}

void	ft_display_char_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image.char_up, (game->map.pos_p_x * 32),
		(game->map.pos_p_y * 32));
}

void	ft_display_char_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image.char_left, (game->map.pos_p_x * 32),
		(game->map.pos_p_y * 32));
}

void	ft_display_char_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image.char_down, (game->map.pos_p_x * 32),
		(game->map.pos_p_y * 32));
}

void	ft_display_char_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image.char_right, (game->map.pos_p_x * 32),
		(game->map.pos_p_y * 32));
}
