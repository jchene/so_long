/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:16:01 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 15:39:23 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Check if char in map at y:i x:j is equal to c, if so then set coords in ptr
int	verif_char(int *ptr, char c, int i, int j)
{
	if (map()->map[i][j] == c)
	{
		if (ptr[0] == -1)
		{
			ptr[0] = i;
			ptr[1] = j;
		}
		else
			return (-1);
	}
	return (0);
}

//Get player, collectibles and exits coordinates in map at line 'i'
int	verif_utils(int i)
{
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(map()->map[i]);
	while (j < len)
	{
		if (verif_char(game()->ps, 'P', i, j) == -1)
			return (-1);
		if (game()->col_id < game()->nb_col)
			if (verif_char(game()->col[game()->col_id], 'C', i, j) == -1)
				return (-1);
		if (map()->map[i][j] == 'C')
			game()->col_id++;
		if (game()->ex_id < game()->nb_ex)
			if (verif_char(game()->ex[game()->ex_id], 'E', i, j) == -1)
				return (-1);
		if (map()->map[i][j] == 'E')
			game()->ex_id++;
		j++;
	}
	return (0);
}

//Check walls and get usefull information from map
int	check_map(void)
{
	int		i;
	int		len;
	t_map	*s_map;

	s_map = map();
	if (charset_diff("1", s_map->map[0]) != 0)
		return (-1);
	if (charset_diff("1", s_map->map[s_map->hei - 1]) != 0)
		return (-1);
	i = 0;
	while (i < s_map->hei)
	{
		len = ft_strlen(s_map->map[i]);
		if ((s_map->map[i][0] != '1') || (s_map->map[i][len - 1] != '1'))
			return (-1);
		if (verif_utils(i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
