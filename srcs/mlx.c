/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:13:32 by jchene            #+#    #+#             */
/*   Updated: 2021/10/16 16:37:14 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Handle encounters the player can have
void	encounters(int key)
{
	int		coll_n;

	if (key == 122 || key == 113 || key == 115 || key == 100)
	{
		game()->steps++;
		coll_n = get_coll_n(game()->pa[0], game()->pa[1]);
		if (coll_n != -1 && game()->col[coll_n][2] != 1)
		{
			game()->col[coll_n][2] = 1;
			game()->col_id--;
		}
		if ((game()->col_id == 0)
			&& (map()->map[game()->pa[0]][game()->pa[1]] == 'E'))
			munalloc(0);
		printf("%d\n", game()->steps);
		update_img(0);
	}
}

//Handle keyboard inputs
int	handle_keys(int key, int null)
{
	(void)null;
	if (key == 65307)
		munalloc(0);
	if (key == 122)
		if (map()->map[game()->pa[0] - 1][game()->pa[1]] != '1')
			game()->pa[0]--;
	if (key == 113)
		if (map()->map[game()->pa[0]][game()->pa[1] - 1] != '1')
			game()->pa[1]--;
	if (key == 115)
		if (map()->map[game()->pa[0] + 1][game()->pa[1]] != '1')
			game()->pa[0]++;
	if (key == 100)
		if (map()->map[game()->pa[0]][game()->pa[1] + 1] != '1')
			game()->pa[1]++;
	encounters(key);
	return (0);
}

//Draw image using screen size and color
int	draw_img(void)
{
	int		line;
	int		column;
	int		pixel;
	int		part;

	line = 0;
	column = 0;
	part = 0;
	while (line < mlx()->ssizey)
	{
		column = 0;
		while (column < mlx()->ssizex)
		{
			part = 0;
			pixel = (line * *(imdt()->ln_size)) + (column * 4);
			while (part < 4)
			{
				(imdt()->start[pixel + part]) = get_color(line, column, part);
				part++;
			}
			column++;
		}
		line++;
	}
	return (0);
}

//Update displayed image
int	update_img(int null)
{
	(void)null;
	if (init_imdt() == -1)
		return (-1);
	if (draw_img() == -1)
		return (-1);
	mlx_put_image_to_window(mlx()->ptr, mlx()->win, mlx()->img, 0, 0);
	free_imdt();
	return (0);
}

//Setup mlx and begin loop
int	start_mlx(void)
{
	game()->pa[0] = game()->ps[0];
	game()->pa[1] = game()->ps[1];
	mlx()->ptr = mlx_init();
	if ((mlx()->ptr) == NULL)
		return (-1);
	(mlx()->win) = mlx_new_window((mlx()->ptr),
			(mlx()->ssizex), (mlx()->ssizey), "so_long");
	(mlx()->img) = mlx_new_image(mlx()->ptr, mlx()->ssizex, mlx()->ssizey);
	update_img(0);
	mlx_key_hook(mlx()->win, handle_keys, NULL);
	mlx_loop(mlx()->ptr);
	return (0);
}
