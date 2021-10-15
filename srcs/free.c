/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:40:26 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 15:44:21 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Free l'intégralité de la structure map
void	free_map(void)
{
	int		i;

	i = 0;
	while (i < map()->hei)
		free(map()->map[i++]);
	free(map()->map);
}

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

void	free_imdt(void)
{
	free(imdt()->bpp);
	free(imdt()->endian);
	free(imdt()->ln_size);
}

void	free_mlx(void)
{
	mlx_destroy_image(mlx()->ptr, mlx()->img);
	mlx_destroy_window(mlx()->ptr, mlx()->win);
	mlx_destroy_display(mlx()->ptr);
	free(mlx()->ptr);
}
