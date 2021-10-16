/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:50:34 by jchene            #+#    #+#             */
/*   Updated: 2021/10/16 16:33:47 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Initialize color data in 'elem' from structure color
void	init_elem_color(int *elem, int blu, int gre, int red)
{
	elem[0] = blu;
	elem[1] = gre;
	elem[2] = red;
	elem[3] = 0;
}

//Initialize 'imdt' structure with image data
int	init_imdt(void)
{
	imdt()->bpp = (int *)malloc(sizeof(int));
	imdt()->ln_size = (int *)malloc(sizeof(int));
	imdt()->endian = (int *)malloc(sizeof(int));
	if (!(imdt()->bpp) || !(imdt()->ln_size) || !(imdt()->endian))
		return (-1);
	(imdt()->start) = mlx_get_data_addr((mlx()->img),
			(imdt()->bpp), (imdt()->ln_size), (imdt()->endian));
	return (0);
}

//Initialize map array
int	init_map_array(void)
{
	int		i;

	i = 0;
	map()->map = (char **)malloc(sizeof(char *) * map()->hei);
	if (!(map()->map))
		return (-1);
	while (i < map()->hei)
	{
		map()->map[i] = (char *)malloc((sizeof(char) * map()->len) + 1);
		if (!(map()->map[i++]))
			return (-1);
	}
	return (0);
}

//Initialize exits array
int	init_exit_arrays(void)
{
	int		i;

	i = 0;
	game()->ex = (int **)malloc(sizeof(int *) * game()->nb_ex);
	if (!(game()->ex))
		return (-1);
	while (i < game()->nb_ex)
	{
		game()->ex[i] = (int *)malloc(sizeof(int) * 2);
		if (!(game()->ex[i]))
			return (-1);
		game()->ex[i][0] = -1;
		game()->ex[i][1] = -1;
		i++;
	}
	return (0);
}

//Initialize collectilbles array and call function to initialize exits array
int	init_game_arrays(void)
{
	int		i;

	i = 0;
	game()->col = (int **)malloc(sizeof(int *) * game()->nb_col);
	if (!(game()->col))
		return (-1);
	while (i < game()->nb_col)
	{
		game()->col[i] = (int *)malloc(sizeof(int) * 3);
		if (!(game()->col))
			return (-1);
		game()->col[i][0] = -1;
		game()->col[i][1] = -1;
		game()->col[i][2] = 0;
		i++;
	}
	return (init_exit_arrays());
}
