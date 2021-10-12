/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:44:07 by jchene            #+#    #+#             */
/*   Updated: 2021/10/12 23:39:17 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Affiche le message d'erreur en fonction du code passé en paramètre
int	err_code(int code)
{
	if (code == 0)
		printf("Well done\n");
	else if (code == -1)
		printf("Wrong number of arguments\n");
	else if (code == -2)
		printf("Bad world extension\n");
	else if (code == -3)
		printf("Invalid map\n");
	else if (code == -4)
		printf("Failed to allocate map array\n");
	else if (code == -5)
		printf("Failed to copy map\n");
	else if (code == -6)
		printf("Wrong walls in map\n");
	else if (code == -7)
		printf("Error occured in mlx\n");
	/*else if (code == -3)
		printf("Failed to allocate mlx\n");*/
	return (code);
}

//Free l'intégralité de la structure map
void	free_map(void)
{
	int		i;

	i = 0;
	while (i < map()->hei)
		free(map()->map[i++]);
	i = 0;
	while (i < game()->nb_col)
	{
		free(game()->col[i]);
		i++;
	}
	free(map()->map);
	free(game()->col);
}

//Adapte la désallocation en fonction 
int	munalloc(int code)
{
	printf("code: %d\n", code);
	if (code <= -5 || code == 0)
		free_map();
	if (code <= -4 || code == 0)
		free(map);
	if (code <= -3 || code == 0)
		free(mlx);
	return (0);
}