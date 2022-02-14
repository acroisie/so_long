/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:44:51 by acroisie          #+#    #+#             */
/*   Updated: 2022/02/14 22:03:32 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		line_count;
	int		column_count;
}t_map;

typedef struct s_image
{
	void	*char_down;
	void	*char_left;
	void	*char_right;
	void	*char_up;
	void	*closed_exit;
	void	*floor;
	void	*key;
	void	*obstacle;
	void	*opened_exit;
}t_image;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_window;
	t_map	map;
	t_image	image;
}t_game;

typedef struct s_item
{
	int	i;
	int	j;
	int	count_e;
	int	count_c;
	int	count_p;
}t_item;

t_map	ft_error_check(int argc, char **argv);
void	ft_put_error(int message_id);
int		ft_exstension_check(char *argv);
int		ft_folder_check(char *argv);
int		ft_opening_check(char *argv);
void	ft_init_map(char *argv, t_map *map);
void	ft_check_map(t_map *map);
int		ft_clean_exit(t_game *game);
int		ft_key_hook(int key_code, t_game *game);
int		ft_move_avatar(int move_id, t_game *game);
void	ft_display_map(t_game *game);

#endif