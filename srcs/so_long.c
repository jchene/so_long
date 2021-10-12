/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:59:05 by jchene            #+#    #+#             */
/*   Updated: 2021/09/23 21:49:23 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->hei)
		printf("%s\n", map->map[i++]);
}

void	print_infos(t_map *map)
{
	int		i;

	i = 0;
	printf("Player starting pos: y:%d x:%d\n", map->ps[0], map->ps[1]);
	printf("Exit pos: y:%d x:%d\n", map->ex[0], map->ex[1]);
	printf("Nb collectibles:%d\n", map->nb_col);
	while (i < map->nb_col)
	{
		printf("C[%d]: y:%d x:%d\n", i, map->col[i][0], map->col[i][1]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;

	if (argc != 2)
		return (err_code(-1));
	/*if (check_ext(".ber", argv[1]) == -1)
		return (err_code(-8));*/
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (err_code(-2));
	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (err_code(-3) + munalloc(-3, map, mlx));
	if (pre_check_map(argv[1], map) == -1)
		return (err_code(-4) + munalloc(-4, map, mlx));
	if (copy_map(argv[1], map) == -1)
		return (err_code(-5) + munalloc(-5, map, mlx));
	if (check_map(map) == -1)
		return (err_code(-6) + munalloc(-6, map, mlx));
	//print_map(map);
	//print_infos(map);
	if ((start_mlx(map, mlx)) == -1)
		return (err_code(-7) + munalloc(-7, map, mlx));
	return (err_code(0) + munalloc(0, map, mlx));
}
