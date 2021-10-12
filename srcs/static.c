/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:48:55 by jchene            #+#    #+#             */
/*   Updated: 2021/10/12 22:41:30 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_color	*color(void)
{
	static t_color	s_color;

	if (s_color.init == 0)
	{
		ft_bzero(&s_color, sizeof(t_color));
		init_color();
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
		init_s_game();
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
		s_mlx.init = 1;
	}
	return (&s_mlx);
}