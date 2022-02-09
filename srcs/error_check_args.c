/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:34:02 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/09 14:34:42 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_opening_check(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (1);
	return (0);
}

int	ft_folder_check(char *argv)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
	close(fd);
	if (fd > 0)
		return (1);
	return (0);
}

int	ft_extension_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.')
			break ;
		i++;
	}
	if (argv[i] == '\0')
		return (1);
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4))
		return (1);
	return (0);
}

void	ft_put_error(int message_id)
{
	ft_putendl_fd("Error", 2);
	if (message_id == 1)
		ft_putendl_fd("Too few arguments", 2);
	if (message_id == 2)
		ft_putendl_fd("Too many arguments", 2);
	if (message_id == 3)
		ft_putendl_fd("Wrong map exstension, you must provide a .ber", 2);
	if (message_id == 4)
		ft_putendl_fd("You must provide a file, not a folder", 2);
	if (message_id == 5)
		ft_putendl_fd("Cannot open the file", 2);
	if (message_id == 6)
		ft_putendl_fd("Map not rectangular", 2);
	if (message_id == 7)
		ft_putendl_fd("Wrong character used, you must use \"E,C,P,1,0\"", 2);
	if (message_id == 8)
		ft_putendl_fd("Map is not closed", 2);
	if (message_id == 9)
		ft_putendl_fd("Wrong number of items, put 1*P & at least 1*C, 1*E", 2);
	exit (1);
}

t_map	ft_error_check(int argc, char **argv)
{
	t_map	map;

	if (argc < 2)
		ft_put_error(1);
	else if (argc > 2)
		ft_put_error(2);
	else if (ft_extension_check(argv[1]))
		ft_put_error(3);
	else if (ft_folder_check(argv[1]))
		ft_put_error(4);
	else if (ft_opening_check(argv[1]))
		ft_put_error(5);
	ft_init_map(argv[1], &map);
	ft_check_map(&map);
	return (map);
}
