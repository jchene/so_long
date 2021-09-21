/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:59:20 by jchene            #+#    #+#             */
/*   Updated: 2021/09/22 01:08:04 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int		init_color(t_color *color, t_mlx *mlx)
{	
	if (!(color->walls = (int *)malloc(sizeof(int) * 4)))
		return (-1);
	if (!(color->coll = (int *)malloc(sizeof(int) * 4)))
		return (-1);
	if (!(color->player = (int *)malloc(sizeof(int) * 4)))
		return (-1);
	if (!(color->exit = (int *)malloc(sizeof(int) * 4)))
		return (-1);
	if (!(color->floor = (int *)malloc(sizeof(int) * 4)))
		return (-1);
	color->walls[0] = 0;
	color->walls[1] = 0;
	color->walls[2] = 250;
	color->walls[3] = 0;
	color->coll[0] = 0;
	color->coll[1] = 250;
	color->coll[2] = 250;
	color->coll[3] = 0;
	color->player[0] = 250;
	color->player[1] = 100;
	color->player[2] = 100;
	color->player[3] = 0;
	color->exit[0] = 0;
	color->exit[1] = 250;
	color->exit[2] = 0;
	color->exit[3] = 0;
	color->floor[0] = 0;
	color->floor[1] = 0;
	color->floor[2] = 0;
	color->floor[3] = 0;
	mlx->color = color;
	return (0);
}

int		get_coll_n(int y, int x, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->map->nb_col)
	{
		if ((mlx->map->col[i][0] == y) && (mlx->map->col[i][1] == x))
			return (i);
		i++;
	}
	return (-1);
}

int		get_color(int line, int column, int part, t_mlx *mlx)
{
	char	c;
	float	v_rap;
	float	h_rap;
	int		coll_n;

	v_rap = ((float)*(mlx->ssizey) / (float)mlx->map->hei);
	h_rap = ((float)*(mlx->ssizex) / (float)mlx->map->len);
	c = mlx->map->map[(int)(line / v_rap)][(int)(column / h_rap)];
	
	//printf("c: %c - line: %d - column: %d - v_rap: %f - h_rap: %f\n", c, line, column, v_rap, h_rap);
	if (((int)(line / v_rap) == mlx->map->pa[0]) && ((int)(column / h_rap) == mlx->map->pa[1]))
		return (mlx->color->player[part]);
	else if (c == '1')
		return (mlx->color->walls[part]);
	else if (c == '0')
		return (mlx->color->floor[part]);
	else if (c == 'E')
		return (mlx->color->exit[part]);
	else if ((c == 'C'))
	{
		coll_n = get_coll_n((int)(line / v_rap), (int)(column / h_rap), mlx);
		if ((coll_n != -1) && (mlx->map->col[coll_n][2] == 0))
			return (mlx->color->coll[part]);
	}
	else if ((c == 'P') && (mlx->map->steps == 0))
		return (mlx->color->player[part]);
	return (0);
}