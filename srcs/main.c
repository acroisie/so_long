/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:55:24 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/08 08:31:06 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_window;
	int		i;

	i = 5;
	ft_error_check(argc, argv);
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 800, 600, "Test_window");
	mlx_loop(mlx);
	return (0);
}
