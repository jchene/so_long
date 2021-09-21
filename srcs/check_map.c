/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:16:01 by jchene            #+#    #+#             */
/*   Updated: 2021/09/22 01:02:16 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Vérifie la longueur et le charset de la ligne
int		check_line(char *line, t_map *map)
{
	int		len;

	len = ft_strlen(line);

	if (len == 0)
		return (-1);

	if (map->hei == 0) //si premiere ligne, stockage de la len
		map->len = len;
	else if (map->len != len) //comparaison de la len de line et de la len enregistrée (excluant premiere ligne)
		return (-1);
	if (charset_diff("01CEP", line) != 0)
		return (-1);
	map->nb_col += count_occur('C', line);
	return (0);
}

//Lis la map et verifie la longueur et le charset ligne par ligne
int		pre_check_map(char *path, t_map *map)
{
	int		id;
	char	*line;

	map->hei = 0;
	map->nb_col = 0;
	if (!(id = open(path, O_RDONLY)))
		return (-1);
	
	while (get_next_line(id, &line) || ft_strlen(line) > 0)
	{
		if ((check_line(line, map)) != 0)
		{
			free(line);
			return (-1);
		}
		map->hei++;
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	close(id);
	return (0);
}

//Malloc tout les pointeurs de 'map'
int		init_map(t_map *map)
{
	int 	i;

	i = 0;
	if (!(map->map = (char **)malloc(sizeof(char *) * map->hei)))
		return (-1);
	while (i < map->hei)
		if (!(map->map[i++] = (char *)malloc((sizeof(char) * map->len) + 1)))
			return (-1);
	if (!(map->ps = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	map->ps[0] = -1;
	map->ps[1] = -1;
	if (!(map->pa = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	map->pa[0] = -1;
	map->pa[1] = -1;
	if (!(map->ex = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	map->ex[0] = -1;
	map->ex[1] = -1;
	if (!(map->col = (int **)malloc(sizeof(int *) * map->nb_col)))
		return (-1);
	i = 0;
	while (i < map->nb_col)
	{
		if (!(map->col[i] = (int *)malloc(sizeof(int) * 3)))
			return (-1);
		map->col[i][0] = -1;
		map->col[i][1] = -1;
		map->col[i][2] = 0;
		i++;
	}
	map->col_id = 0;
	return (0);
}

//Malloc la sructure 'map' et y copie la map
int		copy_map(char *path, t_map *map)
{
	int		i;
	int		id;
	char	*line;

	if (!(id = open(path, O_RDONLY)))
		return (-1);
	i = 0;
	if (init_map(map) == -1)
		return (-1);
	while (get_next_line(id, &line) || ft_strlen(line) > 0)
	{
		ft_strcpyn(map->map[i++], line);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	close(id);
	return (0);
}

int		verif_char(t_map *map, int *ptr, char c, int i, int j)
{
	if (map->map[i][j] == c)
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

//Verification et recuperation des positions player, exit, collectibles
int		verif_utils(t_map *map, int i)
{
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(map->map[i]);
	while (j < len)		//Verification caractère par caractère de la ligne
	{
		if (verif_char(map, map->ps, 'P', i, j) == -1)
			return (-1);
		if (verif_char(map, map->ex, 'E', i, j) == -1)
			return (-1);
		if (map->col_id < map->nb_col)
			if (verif_char(map, map->col[map->col_id], 'C', i, j) == -1)
				return (-1);
		if (map->map[i][j] == 'C')
			map->col_id++;
		j++;
	}
	return (0);
}

//Vérifie les murs et récupère les informations utiles sur la map
int		check_map(t_map *map)
{
	int		i;
	int		len;

	if (charset_diff("1", map->map[0]) != 0)
			return (-1);	//Verification du mur haut
	if (charset_diff("1", map->map[map->hei - 1]) != 0)
			return (-1);	//Verification du mur bas
	i = 0;
	while (i < map->hei)	//Verification ligne par ligne, i est le numero de ligne
	{
		len = ft_strlen(map->map[i]);
		if ((map->map[i][0] != '1') || (map->map[i][len - 1] != '1'))
			return (-1);	//Verification des murs gauche et droit
		if (verif_utils(map, i) == -1)
			return (-1);	//Verification et recuperation des positions player, exit, collectibles
		i++;
	}
	return (0);
}