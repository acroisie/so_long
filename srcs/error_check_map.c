/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:56:01 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/08 18:24:14 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_rectangular(char **map)
{
	int	i;
	int	ref;

	i = 1;
	ref = ft_strlen(map[0]);
	while (map[i])
	{
		dprintf(2, "%d\n", ref);
		dprintf(2, "%d\n", ft_strlen(map[i]));
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
}

