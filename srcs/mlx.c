/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:13:32 by jchene            #+#    #+#             */
/*   Updated: 2021/09/22 01:37:20 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Gère les inputs du clavier et modifie les variables en conséquence
int		handle_keys(int key, t_mlx *mlx)
{
	int		coll_n;

	if (key == 65307)
	{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(0);
	}
	if (key == 122)
		if (mlx->map->map[mlx->map->pa[0] - 1][mlx->map->pa[1]] != '1')
		{
			mlx->map->pa[0]--;
			mlx->map->steps++;
		}
	if (key == 113)
		if (mlx->map->map[mlx->map->pa[0]][mlx->map->pa[1] - 1] != '1')
		{
			mlx->map->pa[1]--;
			mlx->map->steps++;
		}
	if (key == 115)
		if (mlx->map->map[mlx->map->pa[0] + 1][mlx->map->pa[1]] != '1')
		{
			mlx->map->pa[0]++;
			mlx->map->steps++;
		}
	if (key == 100)
		if (mlx->map->map[mlx->map->pa[0]][mlx->map->pa[1] + 1] != '1')
		{
			mlx->map->pa[1]++;
			mlx->map->steps++;
		}
	if (key == 122 || key == 113 || key == 115 || key == 100)
	{
		printf("exit:[%d][%d], player:[%d][%d], col:%d\n", mlx->map->ex[0], mlx->map->ex[1], mlx->map->pa[0], mlx->map->pa[1], mlx->map->col_id);
		coll_n = get_coll_n(mlx->map->pa[0], mlx->map->pa[1], mlx);
		if (coll_n != -1 && mlx->map->col[coll_n][2] != 1)
		{
			mlx->map->col[coll_n][2] = 1;
			mlx->map->col_id--;
		}
		if ((mlx->map->col_id == 0) && (mlx->map->pa[0] == mlx->map->ex[0]) && (mlx->map->pa[1] == mlx->map->ex[1]))
		{
			mlx_destroy_image(mlx->ptr, mlx->img);
			mlx_destroy_window(mlx->ptr, mlx->win);
			exit(0);
		}
		printf("Number of steps: %d\n", mlx->map->steps);
	}
	return (0);
}

//Initialise la structure 'imdt' contenant les donnees relatives a l'image
int		init_imdt(t_imdt *imdt, t_mlx *mlx)
{
	if (!(imdt->bpp = (int *)malloc(sizeof(int))))
		return (-1);
	if (!(imdt->ln_size = (int *)malloc(sizeof(int))))
		return (-1);
	if (!(imdt->endian = (int *)malloc(sizeof(int))))
		return (-1);
	imdt->start = mlx_get_data_addr(mlx->img, imdt->bpp,
		imdt->ln_size, imdt->endian);
	return (0);
}

//Dessine l'image grace aux informations utiles
int		draw_img(t_imdt *imdt, t_mlx *mlx)
{
	int		line;
	int		column;
	int		pixel;
	int		part;
	

	line = 0;
	column = 0;
	part = 0;
	while (line < *(mlx->ssizey))
	{
		column = 0;
		while (column < *(mlx->ssizex))
		{
			part = 0;
			pixel = (line * *(imdt->ln_size)) + (column * 4);
			while (part < 4)
			{
				imdt->start[pixel + part] = get_color(line, column, part, mlx);
				part++;
			}
			column++;
		}
		line++;
	}
	return (0);
}

//Mets à jour l'image affichée
int		update_img(t_mlx *mlx)
{
	t_imdt	*imdt;

	if (!(imdt = (t_imdt *)malloc(sizeof(t_imdt))))
		return (-1);
	if (init_imdt(imdt, mlx) == -1)
		return (-1);
	if (draw_img(imdt, mlx) == -1)
		return (-1);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	free(imdt->bpp);
	free(imdt->ln_size);
	free(imdt->endian);
	free(imdt);
	return (0);
}

//Démarrage et boucle de la mlx
int		start_mlx(t_map *map, t_mlx *mlx)
{
	t_color		*color;

	map->steps = 0;
	mlx->map = map;
	if (!(mlx->ssizey = (int *)malloc(sizeof(int))))
		return (-1);
	if (!(mlx->ssizex = (int *)malloc(sizeof(int))))
		return (-1);
	*(mlx->ssizex) = 1280;
	*(mlx->ssizey) = 720;
	mlx->map->pa[0] = mlx->map->ps[0];
	mlx->map->pa[1] = mlx->map->ps[1];
	if (!(color = (t_color *)malloc(sizeof(t_color))))
		return (-1);
	if (init_color(color, mlx) == -1)
		return (-1);
	if ((mlx->ptr = mlx_init()) == NULL)
		return (-1);
	mlx->win = mlx_new_window(mlx->ptr, *(mlx->ssizex), *(mlx->ssizey), "so_long");
	mlx->img = mlx_new_image(mlx->ptr, *(mlx->ssizex), *(mlx->ssizey));
	mlx_key_hook(mlx->win, handle_keys, mlx);
	mlx_loop_hook(mlx->ptr, update_img, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}