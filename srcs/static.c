/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:48:55 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 15:27:03 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_color	*color(void)
{
	static t_color	s_color;

	if (s_color.init == 0)
	{
		ft_bzero(&s_color, sizeof(t_color));
		init_elem_color(s_color.walls, 0, 0, 250);
		init_elem_color(s_color.coll, 0, 250, 250);
		init_elem_color(s_color.player, 250, 100, 100);
		init_elem_color(s_color.exit, 0, 250, 0);
		init_elem_color(s_color.floor, 0, 0, 0);
		s_color.init = 1;
	}
	return (&s_color);
}

t_map	*map(void)
{
	static t_map	s_map;

	if (s_map.init == 0)
	{
		ft_bzero(&s_map, sizeof(t_map));
		s_map.init = 1;
	}
	return (&s_map);
}

t_game	*game(void)
{
	static t_game	s_game;

	if (s_game.init == 0)
	{
		ft_bzero(&s_game, sizeof(t_game));
		s_game.ps[0] = -1;
		s_game.ps[1] = -1;
		s_game.pa[0] = -1;
		s_game.pa[1] = -1;
		s_game.nb_col = 0;
		s_game.col_id = 0;
		s_game.nb_ex = 0;
		s_game.ex_id = 0;
		s_game.steps = 0;
		s_game.init = 1;
	}
	return (&s_game);
}

t_mlx	*mlx(void)
{
	static t_mlx	s_mlx;

	if (s_mlx.init == 0)
	{
		ft_bzero(&s_mlx, sizeof(t_mlx));
		s_mlx.ssizex = 250;
		s_mlx.ssizey = 100;
		s_mlx.init = 1;
	}
	return (&s_mlx);
}

t_imdt	*imdt(void)
{
	static t_imdt	s_imdt;

	if (s_imdt.init == 0)
	{
		ft_bzero(&s_imdt, sizeof(t_imdt));
		s_imdt.init = 1;
	}
	return (&s_imdt);
}
