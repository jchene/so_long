/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:59:05 by jchene            #+#    #+#             */
/*   Updated: 2021/09/18 17:11:02 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int		err_code(int code)
{
	if (code == -1)
		printf("Wrong number of arguments\n");
	else if (code == -2)
		printf("Failed to allocate map pointer\n");
	else if (code == -3)
		printf("Invalid map\n");
	else if (code == -4)
		printf("Failed to copy map\n");
	else if (code == -5)
		printf("Wrong walls in map\n");
	else if (code == -6)
		printf("Failed to allocate mlx\n");
	else if (code == -7)
		printf("Error occured in mlx\n");
	return (-1);
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->hei)
		free(map->map[i++]);
	i = 0;
	while (i < map->nb_col)
		free(map->col[i++]);
	free(map->map);
	free(map->col);
	free(map->ps);
	free(map->pa);
	free(map->ex);
}

int		munalloc(int code, t_map *map, t_mlx *mlx)
{
	printf("code: %d\n", code);
	if (code <= -6 || code == 0)
		free(mlx);
	if (code <= -5 || code == 0)
		free_map(map);
	if (code <= -3 || code == 0)
		free(map);
	return (0);
}

int		update_img(t_mlx *mlx)
{
	t_imdt	*imdt;

	if (!(imdt = (t_imdt*)malloc(sizeof(t_imdt))))
		return (-1);
	if (init_imdt(imdt, mlx) == -1)
		return (-1);
	/*if (draw_img(imdt, mlx) == -1)
		return (-1);*/
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	free(imdt->bpp);
	free(imdt->ln_size);
	free(imdt->endian);
	free(imdt);
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;

	if (argc != 2)
		return (err_code(-1));
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (err_code(-2));
	if (pre_check_map(argv[1], map) == -1)
		return (err_code(-3) + munalloc(-3, map, mlx));
	if (copy_map(argv[1], map) == -1)
		return (err_code(-4) + munalloc(-4, map, mlx));
	if (check_map(map) == -1)
		return (err_code(-5) + munalloc(-5, map, mlx));
	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (err_code(-6) + munalloc(-6, map, mlx));
	/*if ((start_mlx(map, mlx)) == -1)
		return (err_code(-7) + munalloc(-7, map, mlx));*/
	printf("Well done\n");
	munalloc(0, map, mlx);
	return (0);
}
