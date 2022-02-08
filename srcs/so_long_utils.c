/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:13:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/08 18:26:47 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		dprintf(2, "%d\n", ft_strlen(map->map[i]));
		if (!map->map[i])
		{
			ft_free_split(map->map);
			exit (1);
		}
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}
