/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:40:26 by jchene            #+#    #+#             */
/*   Updated: 2021/10/16 16:34:29 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Free map array
void	free_map(void)
{
	int		i;

	i = 0;
	while (i < map()->hei)
		free(map()->map[i++]);
	free(map()->map);
}

//Free collectibles and exits arrays
void	free_game(void)
{
	int		i;

	i = 0;
	while (i < game()->nb_col)
		free(game()->col[i++]);
	free(game()->col);
	i = 0;
	while (i < game()->nb_ex)
		free(game()->ex[i++]);
	free(game()->ex);
}

//Free image data structure
void	free_imdt(void)
{
	free(imdt()->bpp);
	free(imdt()->endian);
	free(imdt()->ln_size);
}

//Free mlx related pointers
void	free_mlx(void)
{
	mlx_destroy_image(mlx()->ptr, mlx()->img);
	mlx_destroy_window(mlx()->ptr, mlx()->win);
	mlx_destroy_display(mlx()->ptr);
	free(mlx()->ptr);
}
