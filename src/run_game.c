/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:14:03 by vmichali          #+#    #+#             */
/*   Updated: 2023/10/14 21:14:06 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_vars *vars)
{
	if (((vars->map)[vars->y][(vars->x + 1)]) != 1)
	{
		if (((vars->map)[vars->y][(vars->x)]) != 4)
		{
			vars->map[vars->y][vars->x] = 0;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_gr.img, \
			(vars->x) * 32, (vars->y) * 32);
		}
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ex.img, \
			(vars->x) * 32, (vars->y) * 32);
		vars->x += 1;
		vars->moves++;
		ft_printf("Current moves count = [%d]\n", vars->moves);
	}
}

void	move_up(t_vars *vars)
{
	if (((vars->map)[vars->y - 1][(vars->x)]) != 1)
	{
		if (((vars->map)[vars->y][(vars->x)]) != 4)
		{
			vars->map[vars->y][vars->x] = 0;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_gr.img, \
			(vars->x) * 32, (vars->y) * 32);
		}
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ex.img, \
			(vars->x) * 32, (vars->y) * 32);
		vars->y -= 1;
		vars->moves++;
		ft_printf("Current moves count = [%d]\n", vars->moves);
	}
}

void	move_down(t_vars *vars)
{
	if (((vars->map)[vars->y + 1][(vars->x)]) != 1)
	{
		if (((vars->map)[vars->y][(vars->x)]) != 4)
		{
			vars->map[vars->y][vars->x] = 0;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_gr.img, \
			(vars->x) * 32, (vars->y) * 32);
		}
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ex.img, \
			(vars->x) * 32, (vars->y) * 32);
		vars->y += 1;
		vars->moves++;
		ft_printf("Current moves count = [%d]\n", vars->moves);
	}
}

void	move_left(t_vars *vars)
{
	if (((vars->map)[vars->y][(vars->x - 1)]) != 1)
	{
		if (((vars->map)[vars->y][(vars->x)]) != 4)
		{
			vars->map[vars->y][vars->x] = 0;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_gr.img, \
			(vars->x) * 32, (vars->y) * 32);
		}
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ex.img, \
			(vars->x) * 32, (vars->y) * 32);
		vars->x -= 1;
		vars->moves++;
		ft_printf("Current moves count = [%d]\n", vars->moves);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	if (keycode == 65363)
		move_right(vars);
	if (keycode == 65362)
		move_up(vars);
	if (keycode == 65364)
		move_down(vars);
	if (keycode == 65361)
		move_left(vars);
	if (((vars->map)[vars->y][vars->x]) == 2)
		vars->collect--;
	if (vars->map[vars->y][vars->x] == 4 && vars->collect == 0)
		close_win(vars);
	if (vars->map[vars->y][vars->x] == 4)
	{
		ft_printf("Collect all collectibles before heading to exit\n");
		ft_printf("Still [%d] of remaining collectibles\n", vars->collect);
	}
	else
		vars->map[vars->y][vars->x] = 3;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_pl.img, \
	vars->x * 32, vars->y * 32);
	return (0);
}
