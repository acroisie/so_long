/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:55:24 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/09 11:15:34 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	// void	*mlx;
	// void	*mlx_window;

	map = ft_error_check(argc, argv);
	dprintf(1, "\n\033[0;32mProgram continue\033[0m\n\n");    //To delete
	// mlx = mlx_init();
	// mlx_window = mlx_new_window(mlx, 800, 600, "Test_window");
	// mlx_loop(mlx);
	ft_free_split(map.map);
	return (0);
}
