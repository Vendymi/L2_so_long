/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:59:04 by vmichali          #+#    #+#             */
/*   Updated: 2023/10/14 20:59:05 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy_map(t_vars *vars, size_t i, size_t j)
{
	vars->map = malloc(sizeof(int *) * (vars->line_cnt));
	vars->length = vars->line_cnt;
	while (vars->length > 0)
		vars->map[--vars->length] = malloc(sizeof(int *) * (vars->lngh));
	while (i < vars->line_cnt)
	{
		while (j < vars->lngh -1)
		{
			vars->map[i][j] = vars->map2[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

void	peri_check(t_vars *vars)
{
	int	i;

	i = 0;
	while ((size_t)i < vars->lngh - 1)
	{
		if (vars->map2[0][i] != 1)
			finish(vars, "Map perimeter is not intact.");
		else if (vars->map2[vars->line_cnt - 1][i] != 1)
			finish(vars, "Map perimeter is not intact.");
		i++;
	}
	i = 0;
	while ((size_t)i < vars->line_cnt -1)
	{
		if (vars->map2[i][0] != 1)
			finish(vars, "Map perimeter is not intact.");
		else if (vars->map2[i][vars->lngh -2] != 1)
			finish(vars, "Map perimeter is not intact.");
		i++;
	}
}

void	walk_map(t_vars *vars, int line, int column)
{
	if (vars->map2[line][column] == 2)
		vars->collect++;
	if (vars->map2[line][column] == 4)
		vars->path_exists = 1;
	vars->map2[line][column] = 1;
	if (vars->map2[line + 1][column] != 1)
		walk_map(vars, line + 1, column);
	if (vars->map2[line - 1][column] != 1)
		walk_map(vars, line - 1, column);
	if (vars->map2[line][column + 1] != 1)
		walk_map(vars, line, column + 1);
	if (vars->map2[line][column - 1] != 1)
		walk_map(vars, line, column - 1);
}

void	map_check(t_vars *vars)
{
	peri_check(vars);
	copy_map(vars, 0, 0);
	walk_map(vars, vars->y, vars->x);
	if (vars->path_exists == 0 || vars->collect != vars->same_coll)
		finish(vars, "Map is not valid.");
}
