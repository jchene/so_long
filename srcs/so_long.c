/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:59:05 by jchene            #+#    #+#             */
/*   Updated: 2021/10/12 23:39:15 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	start_static(void)
{
	color();
	game();
	map();
	mlx();
}

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
	if (argc != 2)
		return (err_code(-1));
	/*if (check_ext(".ber", argv[1]) == -1)
		return (err_code(-2));*/
	start_static();
	if (pre_check_map(argv[1]) == -1)
		return (err_code(-3));
	if (init_map_array() == -1)
		return (-4);
	if (copy_map(argv[1]) == -1)
		return (munalloc(-5));
	if (check_map() == -1)//adapter pour sorties multiples
		return (munalloc(-6));
	
	//print_map(map);
	//print_infos(map);
	if ((start_mlx(map, mlx)) == -1)
		return (munalloc(-7));
	return (munalloc(0));
}
