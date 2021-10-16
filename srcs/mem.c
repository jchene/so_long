/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:44:07 by jchene            #+#    #+#             */
/*   Updated: 2021/10/16 16:36:53 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Copy string 'src' to 'dest' with '\0' at end of copy
char	*ft_strcpyn(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//Display error message according to 'code'
int	err_code(int code)
{
	if (code != 0)
		printf("Error\n");
	if (code == -1)
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
		printf("Failed to allocate game array\n");
	else if (code == -7)
		printf("Wrong walls in map\n");
	else if (code == -8)
		printf("Error occured in mlx\n");
	return (code);
}

//Adapt unallocation using 'code'
int	munalloc(int code)
{
	err_code(code);
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
