/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:12:47 by vmichali          #+#    #+#             */
/*   Updated: 2023/10/14 21:12:49 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "src/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_data	img;
	t_data	img_gr;
	t_data	img_wa;
	t_data	img_pl;
	t_data	img_co;
	t_data	img_ex;
	int		**map;
	int		**map2;
	int		x;
	int		y;
	int		moves;
	int		collect;
	int		exit;
	int		player;
	char	*path0;
	char	*path1;
	char	*path2;
	char	*path3;
	char	*path4;
	char	*mappath;
	size_t	length;
	size_t	line_cnt;
	size_t	str_cnt;
	int		path_exists;
	int		same_coll;
	size_t	lngh;
	int		fd;
}	t_vars;

void	read_map(t_vars *vars);
void	free_map(t_vars *vars);
void	finish(t_vars *vars, char *str);
void	map_check(t_vars *vars);
void	run_game(t_vars *vars);
void	load_map(t_vars *vars, size_t i, size_t j);
int		close_win(t_vars *vars);
void	put_counts(t_vars *vars, char *str);
void	check_counts(t_vars *vars);
void	map_check(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

#endif
