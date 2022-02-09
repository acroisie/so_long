/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:56:01 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/09 14:13:57 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_item(char **map)
{
	t_item	item;

	item.i = 0;
	item.count_e = 0;
	item.count_c = 0;
	item.count_p = 0;
	while (map[item.i])
	{
		item.j = 0;
		while (map[item.i][item.j])
		{
			if (map[item.i][item.j] == 'E')
				item.count_e++;
			if (map[item.i][item.j] == 'C')
				item.count_c++;
			if (map[item.i][item.j] == 'P')
				item.count_p++;
			item.j++;
		}
		item.i++;
	}
	if (item.count_c < 1 || item.count_e < 1 || item.count_p != 1)
		return (1);
	return (0);
}

int	ft_check_borders(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] != '1')
			{
				if (j == 0 || j == ft_strlen(map.map[i]) - 1)
					return (1);
				if (i == 0 || i == map.line_count - 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_ecp10(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E')
				if (map[i][j] != 'C')
					if (map[i][j] != 'P')
						if (map[i][j] != '1')
							if (map[i][j] != '0')
								return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_rectangular(char **map)
{
	int	i;
	int	ref;

	i = 1;
	ref = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ref)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_map(t_map *map)
{
	if (ft_check_rectangular(map->map))
	{
		ft_free_split(map->map);
		ft_put_error(6);
	}
	if (ft_check_ecp10(map->map))
	{
		ft_free_split(map->map);
		ft_put_error(7);
	}
	if (ft_check_borders(*map))
	{
		ft_free_split(map->map);
		ft_put_error(8);
	}
	if (ft_check_item(map->map))
	{
		ft_free_split(map->map);
		ft_put_error(9);
	}	
}
