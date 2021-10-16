/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:59:20 by jchene            #+#    #+#             */
/*   Updated: 2021/10/16 16:37:57 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Check for collectible at coords 'y' 'x' if so return it's id else return -1
int	get_coll_n(int y, int x)
{
	int		i;

	i = 0;
	while (i < game()->nb_col)
	{
		if ((game()->col[i][0] == y) && (game()->col[i][1] == x))
			return (i);
		i++;
	}
	return (-1);
}

//Return the color of collectible located at parameters
int	get_coll_color(int line, int column, int part)
{
	float	v_rap;
	float	h_rap;
	int		coll_n;

	v_rap = ((float)mlx()->ssizey / (float)map()->hei);
	h_rap = ((float)mlx()->ssizex / (float)map()->len);
	coll_n = get_coll_n((int)(line / v_rap), (int)(column / h_rap));
	if ((coll_n != -1) && (game()->col[coll_n][2] == 0))
		return (color()->coll[part]);
	return (0);
}

//Return color information found with given parameters
int	get_color(int line, int column, int part)
{
	char	c;
	float	v_rap;
	float	h_rap;

	v_rap = ((float)mlx()->ssizey / (float)map()->hei);
	h_rap = ((float)mlx()->ssizex / (float)map()->len);
	c = map()->map[(int)(line / v_rap)][(int)(column / h_rap)];
	if (((int)(line / v_rap) == game()->pa[0]) &&
		((int)(column / h_rap) == game()->pa[1]))
		return (color()->player[part]);
	else if (c == '1')
		return (color()->walls[part]);
	else if (c == '0')
		return (color()->floor[part]);
	else if (c == 'E')
		return (color()->exit[part]);
	else if ((c == 'C'))
		return (get_coll_color(line, column, part));
	else if ((c == 'P') && (game()->steps == 0))
		return (color()->player[part]);
	return (0);
}
