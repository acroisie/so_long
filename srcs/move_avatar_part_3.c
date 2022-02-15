/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_avatar_part_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:54:59 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/15 16:17:48 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_display_open_doors(t_game game)
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
			if (game.map.map[i][j] == 'E')
				mlx_put_image_to_window(game.mlx, game.mlx_window,
					game.image.opened_exit, x, y);
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}

void	ft_check_end_of_game(t_game *game)
{
	if (game->map.map[game->map.pos_p_y][game->map.pos_p_x] == 'E' &&
		game->map.key_count == game->map.c_count)
		ft_clean_exit(game);
}
