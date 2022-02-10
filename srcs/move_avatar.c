/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_avatar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:48:34 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/10 17:13:10 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_find_position(int *i, int *j, t_game game)
{
	*i = 0;
	while (game.map.map[*i])
	{
		*j = 0;
		while (game.map.map[*i][*j])
		{
			if (game.map.map[*i][*j] == 'P')
				break ;
			*j += 1;
		}
		if (game.map.map[*i][*j] == 'P')
			break ;
		*i += 1;
	}
}

int	ft_check_impossible_move(int move_id, t_game game)
{
	int	i;
	int	j;

	ft_find_position(&i, &j, game);
	// int	i;
	// int	j;

	// i = 0;
	// while (game.map.map[i])
	// {
	// 	j = 0;
	// 	while (game.map.map[i][j])
	// 	{
	// 		if (game.map.map[i][j] == 'P')
	// 			break ;
	// 		j++;
	// 	}
	// 	if (game.map.map[i][j] == 'P')
	// 		break ;
	// 	i++;
	// }
	if (move_id == 1)
		if (game.map.map[i - 1][j] != '1')
			return (0);
	if (move_id == 2)
		if (game.map.map[i][j - 1] != '1')
			return (0);
	if (move_id == 3)
		if (game.map.map[i + 1][j] != '1')
			return (0);
	if (move_id == 4)
		if (game.map.map[i][j + 1] != '1')
			return (0);
	return (1);
}

int	ft_move_avatar(int move_id, t_game *game)
{
	static int	count;

	if (!ft_check_impossible_move(move_id, *game))
	{
		// ft_map_update(move_id, game);
		count++;
		printf("Amount of moves: %d\n", count);
	}
	return (0);
}
