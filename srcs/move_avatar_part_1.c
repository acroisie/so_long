/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_avatar_part_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:48:34 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/15 16:15:12 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_leaving_tile(t_game *game)
{
	if (game->map.map[game->map.pos_p_y][game->map.pos_p_x] != 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image.floor, (game->map.pos_p_x * 32),
			(game->map.pos_p_y * 32));
	else
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image.closed_exit, (game->map.pos_p_x * 32),
			(game->map.pos_p_y * 32));
}

void	ft_find_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
				break ;
			j++;
		}
		if (game->map.map[i][j] == 'P')
			break ;
		i++;
	}
	game->map.pos_p_x = j;
	game->map.pos_p_y = i;
}

int	ft_check_impossible_move(int move_id, t_game *game)
{
	if (move_id == 1)
		if (game->map.map[game->map.pos_p_y - 1][game->map.pos_p_x] != '1')
			return (0);
	if (move_id == 2)
		if (game->map.map[game->map.pos_p_y][game->map.pos_p_x - 1] != '1')
			return (0);
	if (move_id == 3)
		if (game->map.map[game->map.pos_p_y + 1][game->map.pos_p_x] != '1')
			return (0);
	if (move_id == 4)
		if (game->map.map[game->map.pos_p_y][game->map.pos_p_x + 1] != '1')
			return (0);
	return (1);
}

void	ft_map_update(int move_id, t_game *game)
{
	ft_check_end_of_game(game);
	if (move_id == 1)
	{
		if (game->map.map[game->map.pos_p_y][game->map.pos_p_x] == 'C')
			ft_display_floor_tile(game);
		ft_display_char_up(game);
	}
	if (move_id == 2)
	{
		if (game->map.map[game->map.pos_p_y][game->map.pos_p_x] == 'C')
			ft_display_floor_tile(game);
		ft_display_char_left(game);
	}
	if (move_id == 3)
	{
		if (game->map.map[game->map.pos_p_y][game->map.pos_p_x] == 'C')
			ft_display_floor_tile(game);
		ft_display_char_down(game);
	}
	if (move_id == 4)
	{
		if (game->map.map[game->map.pos_p_y][game->map.pos_p_x] == 'C')
			ft_display_floor_tile(game);
		ft_display_char_right(game);
	}
}

int	ft_move_avatar(int move_id, t_game *game)
{
	static int	m_count;

	if (m_count == 0)
	{
		ft_find_position(game);
		game->map.key_count = 0;
	}
	if (!ft_check_impossible_move(move_id, game))
	{
		ft_leaving_tile(game);
		if (move_id == 1)
			game->map.pos_p_y -= 1;
		if (move_id == 2)
			game->map.pos_p_x -= 1;
		if (move_id == 3)
			game->map.pos_p_y += 1;
		if (move_id == 4)
			game->map.pos_p_x += 1;
		ft_map_update(move_id, game);
		m_count++;
		printf("Amount of moves: %d\n", m_count);
	}
	if (game->map.key_count == game->map.c_count)
		ft_display_open_doors(*game);
	return (0);
}
