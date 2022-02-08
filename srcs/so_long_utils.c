/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:13:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/08 09:56:45 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(char *argv, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	map->line_count = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->line_count++;
	}
	free(line);
	close(fd);
	map = ft_calloc(map->line_count, (sizeof (char *)));
	fd = open(argv, O_RDONLY);
	map->map = get_next_line(fd);
	while (map->map)
		map->map = get_next_line(fd);
	close(fd);
}
