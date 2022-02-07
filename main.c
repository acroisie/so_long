/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:55:24 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/05 17:36:47 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	int		i;
	t_data	img;

	i = 5;
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 800, 600, "Test_window");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i < 100)
	{		
		ft_pixel_put(&img, i, 5, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
