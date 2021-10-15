/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:59:05 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 15:37:20 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_map(void)
{
	int		i;

	i = 0;
	while (i < map()->hei)
		printf("%s\n", map()->map[i++]);
}

void	print_infos(void)
{
	int		i;

	i = 0;
	printf("Player starting pos: y:%d x:%d\n", game()->ps[0], game()->ps[1]);
	printf("Nb exits:%d\n", game()->nb_ex);
	printf("Nb collectibles:%d\n", game()->nb_col);
	while (i < game()->nb_col)
	{
		printf("C[%d]: y:%d x:%d\n", i, game()->col[i][0], game()->col[i][1]);
		i++;
	}
	i = 0;
	while (i < game()->nb_ex)
	{
		printf("E[%d]: y:%d x:%d\n", i, game()->ex[i][0], game()->ex[i][1]);
		i++;
	}
}

/*if (check_ext(".ber", argv[1]) == -1) X return (err_code(-2));*/
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (err_code(-1));
	map();
	game();
	color();
	mlx();
	if (pre_check_map(argv[1]) == -1)
		return (munalloc(-3));
	if (init_map_array() == -1)
		return (munalloc(-4));
	if (copy_map(argv[1]) == -1)
		return (munalloc(-5));
	if (init_game_arrays() == -1)
		return (munalloc(-6));
	if (check_map() == -1)
		return (munalloc(-7));
	print_infos();
	if ((start_mlx()) == -1)
		return (munalloc(-8));
	return (munalloc(0));
}
