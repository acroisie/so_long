/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:44:51 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/08 08:35:26 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		line_count;
}t_map;


void	ft_error_check(int argc, char **argv);
void	ft_put_error(int message_id);
int		ft_exstension_check(char *argv);
int		ft_folder_check(char *argv);
int		ft_opening_check(char *argv);
void	ft_check_map(char *map);
void	ft_init_map(char *argv, t_map *map);

#endif