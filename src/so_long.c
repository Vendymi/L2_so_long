/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:51:31 by vmichali          #+#    #+#             */
/*   Updated: 2023/10/14 20:51:34 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(t_vars *vars)
{
	if (vars->map[vars->y][vars->x] == 4 && vars->collect == 0)
	{
		ft_printf("\n// You won this game - CONGRATULATIONS \\\\\n");
		ft_printf("// So Long, and Thanks for All the Fish \\\\\n");
	}
	ft_printf("\nYou exit the game\n\n");
	mlx_destroy_window(vars->mlx, vars->win);
	free_map(vars);
	exit (0);
}

void	vars_init(t_vars *vars, char *argv)
{
	vars->map = NULL;
	vars->map2 = NULL;
	vars->str_cnt = 0;
	vars->line_cnt = 0;
	vars->x = 0;
	vars->y = 0;
	vars->collect = 0;
	vars->moves = 0;
	vars->exit = 0;
	vars->path2 = "img/collectible.xpm";
	vars->path0 = "img/path.xpm";
	vars->path4 = "img/exit.xpm";
	vars->path3 = "img/player.xpm";
	vars->path1 = "img/wall.xpm";
	vars->length = 0;
	vars->path_exists = 0;
	vars->same_coll = 0;
	vars->lngh = 0;
	vars->mappath = argv;
	vars->player = 0;
}

void	finish(t_vars *vars, char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	free_map(vars);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		finish(&vars, "Incorrect number of arguments");
	vars_init(&vars, argv[1]);
	read_map(&vars);
	map_check(&vars);
	vars.collect = vars.same_coll;
	load_map(&vars, 0, 0);
	mlx_hook(vars.win, 17, 1L << 17, close_win, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
