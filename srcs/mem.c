/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:44:07 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 15:44:31 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Fills memory zone from 'b' to 'b'+'n' with zeroes
void	ft_bzero(void *b, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (n-- > 0)
		*(ptr++) = 0;
}

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
		printf("Failed to allocate map array\n");
	else if (code == -7)
		printf("Wrong walls in map\n");
	else if (code == -8)
		printf("Error occured in mlx\n");
	return (code);
}

//Adapte la désallocation en fonction 
int	munalloc(int code)
{
	printf("exit with code: %d\n", code);
	if (code < -4 || code == 0)
		free_map();
	if (code < -6 || code == 0)
		free_game();
	if (code < -7 || code == 0)
		free_mlx();
	if (code == 0)
		exit(0);
	return (0);
}
