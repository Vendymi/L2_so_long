/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:52:02 by vmichali          #+#    #+#             */
/*   Updated: 2023/10/14 20:52:04 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_counts(t_vars *vars, char *str)
{
	while (*str)
	{
		if (*str == 'C')
			vars->same_coll++;
		if (*str == 'P')
			vars->player++;
		if (*str == 'E')
			vars->exit++;
		str++;
	}
}

void	line_read(t_vars *vars)
{
	char	*toprint;

	toprint = get_next_line(vars->fd);
	vars->lngh = ft_strlen(toprint);
	while (toprint)
	{
		vars->length = ft_strlen(toprint);
		if (vars->length != vars->lngh)
			finish(vars, "Map is not rectangular");
		vars->line_cnt++;
		put_counts(vars, toprint);
		free(toprint);
		toprint = get_next_line(vars->fd);
	}
	free(toprint);
	if (vars->player != 1)
		finish(vars, "Wrong amount of players");
	if (vars->same_coll < 1)
		finish(vars, "At least 1 collectible [C] is needed.");
	if (vars->exit != 1)
		finish(vars, "Wrong amount of exits");
	vars->exit = 0;
}

void	fill_line(t_vars *vars, int *line, int len)
{
	char	*toprint;
	int		i;

	i = 0;
	toprint = get_next_line(vars->fd);
	if (!toprint)
		return ;
	while (i < len - 1)
	{
		if (toprint[i] == '0')
			line[i] = 0;
		else if (toprint[i] == '1')
			line[i] = 1;
		else if (toprint[i] == 'C')
			line[i] = 2;
		else if (toprint[i] == 'P')
			line[i] = 3;
		else if (toprint[i] == 'E')
			line[i] = 4;
		if (line[i++] == 3)
			vars->x = i -1;
	}
	free(toprint);
	line[i] = '\0';
}

void	read_map(t_vars *vars)
{
	int	i;

	i = 0;
	vars->fd = open(vars->mappath, O_RDONLY);
	if (vars->fd == -1)
		finish(vars, "Error opening map file");
	line_read(vars);
	close(vars->fd);
	vars->fd = open(vars->mappath, O_RDONLY);
	if (vars->fd == -1)
		finish(vars, "Error opening map file");
	vars->map2 = malloc(sizeof(int *) * (vars->line_cnt +1));
	vars->length = vars->line_cnt;
	while (vars->length > 0)
		vars->map2[--vars->length] = malloc(sizeof(int *) * (vars->lngh));
	while ((size_t)i < vars->line_cnt)
	{
		if (vars->x == 0)
			vars->y = i;
		fill_line(vars, vars->map2[i++], vars->lngh);
	}
	close(vars->fd);
}

void	free_map(t_vars *vars)
{
	while (vars->line_cnt && vars->map2 != NULL && vars->map != NULL)
	{
		free(vars->map2[-1 + vars->line_cnt]);
		free(vars->map[-1 + vars->line_cnt--]);
	}
	free(vars->map2);
	free(vars->map);
}
