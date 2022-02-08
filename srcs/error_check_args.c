/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:34:02 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/08 09:57:24 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_exstension_check(char *argv)
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
	exit (1);
}

void	ft_error_check(int argc, char **argv)
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
	// ft_check_map(map);
}
