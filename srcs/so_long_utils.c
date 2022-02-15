/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:13:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/15 15:23:39 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_supress_line_break(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

int	ft_count_line(char *argv)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(argv, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}

void	ft_init_map(char *argv, t_map *map)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	i = 0;
	map->line_count = ft_count_line(argv);
	map->map = ft_calloc((map->line_count + 1), (sizeof (char *)));
	fd = open(argv, O_RDONLY);
	while (i < map->line_count)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
		{
			ft_free_split(map->map);
			close(fd);
			exit (1);
		}
		ft_supress_line_break(map->map[i]);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}

int	ft_clean_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image.char_down);
	mlx_destroy_image(game->mlx, game->image.char_left);
	mlx_destroy_image(game->mlx, game->image.char_right);
	mlx_destroy_image(game->mlx, game->image.char_up);
	mlx_destroy_image(game->mlx, game->image.closed_exit);
	mlx_destroy_image(game->mlx, game->image.floor);
	mlx_destroy_image(game->mlx, game->image.key);
	mlx_destroy_image(game->mlx, game->image.obstacle);
	mlx_destroy_image(game->mlx, game->image.opened_exit);
	mlx_destroy_window(game->mlx, game->mlx_window);
	ft_free_split(game->map.map);
	exit (0);
}

int	ft_key_hook(int key_code, t_game *game)
{
	if (key_code == 53)
		ft_clean_exit(game);
	if (key_code == 13 || key_code == 126)
		ft_move_avatar(1, game);
	if (key_code == 0 || key_code == 123)
		ft_move_avatar(2, game);
	if (key_code == 1 || key_code == 125)
		ft_move_avatar(3, game);
	if (key_code == 2 || key_code == 124)
		ft_move_avatar(4, game);
	return (0);
}
