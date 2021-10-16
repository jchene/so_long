/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:59:05 by jchene            #+#    #+#             */
/*   Updated: 2021/10/16 16:28:17 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (munalloc(-1));
	if (check_ext(".ber", argv[1]) == -1)
		return (munalloc(-2));
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
	if ((start_mlx()) == -1)
		return (munalloc(-8));
	return (munalloc(0));
}
