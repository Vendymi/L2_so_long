/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_loading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:13:41 by vmichali          #+#    #+#             */
/*   Updated: 2023/10/14 21:13:43 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_image(t_vars *vars, size_t i, size_t j)
{
	if (vars->map[i][j] == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img_gr.img, j * 32, i * 32);
	if (vars->map[i][j] == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img_wa.img, j * 32, i * 32);
	if (vars->map[i][j] == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img_co.img, j * 32, i * 32);
	if (vars->map[i][j] == 3)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img_pl.img, j * 32, i * 32);
	if (vars->map[i][j] == 4)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img_ex.img, j * 32, i * 32);
}

void	load_map(t_vars *vars, size_t i, size_t j)
{
	int	width;
	int	height;

	(void)i;
	(void)j;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 32 * (vars->lngh -1), \
	32 * (vars->line_cnt), "42_SO_LONG");
	vars->img_gr.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->path0, &width, &height);
	vars->img_wa.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->path1, &width, &height);
	vars->img_pl.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->path3, &width, &height);
	vars->img_co.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->path2, &width, &height);
	vars->img_ex.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->path4, &width, &height);
	while (i < vars->line_cnt)
	{
		while (j < vars->lngh -1)
			load_image(vars, i, j++);
		j = 0;
		i++;
	}
}
