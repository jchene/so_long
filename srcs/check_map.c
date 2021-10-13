/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:16:01 by jchene            #+#    #+#             */
/*   Updated: 2021/10/13 19:19:55 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Vérifie la longueur, le charset et compte les collectibles et les sorties
int	check_line(char *line)
{
	int		len;
	t_map	*s_map;

	s_map = map();
	len = ft_strlen(line);
	if (len == 0)
		return (-1);
	if (s_map->hei == 0) //si premiere ligne, stockage de la len
		s_map->len = len;
	else if (s_map->len != len) //comparaison de la len de line et de la len enregistrée (excluant premiere ligne)
		return (-1);
	if (charset_diff("01CEP", line) != 0)
		return (-1);
	game()->nb_col += count_occur('C', line);
	game()->nb_ex += count_occur('E', line);
	return (0);
}

//Lis la map et verifie la longueur, le charset et compte les collectibles et les sorties
int	pre_check_map(char *path)
{
	int		id;
	char	*line;
	t_map	*s_map;

	s_map = map();
	s_map->hei = 0;
	if (!(id = open(path, O_RDONLY)))
		return (-1);
	while (get_next_line(id, &line) || ft_strlen(line) > 0)
	{
		if ((check_line(line)) != 0)
		{
			free(line);
			return (-1);
		}
		s_map->hei++;
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	close(id);
	return (0);
}



//Malloc la sructure 'map' et y copie la map
int	copy_map(char *path)
{
	int		i;
	int		id;
	char	*line;

	if (!(id = open(path, O_RDONLY)))
		return (-1);
	i = 0;
	while (get_next_line(id, &line) || ft_strlen(line) > 0)
	{
		ft_strcpyn(map()->map[i++], line);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	close(id);
	return (0);
}

//adapter pour sorties multiples

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

//Verification et recuperation des positions player, exit, collectibles

//adapter pour sorties multiples

int	verif_utils(int i)
{
	int		j;
	int		len;
	t_map	*s_map;
	t_game	*s_game;

	j = 0;
	s_map = map();
	s_game = game();
	len = ft_strlen(s_map->map[i]);
	while (j < len)		//Verification caractère par caractère de la ligne
	{
		if (verif_char(s_game->ps, 'P', i, j) == -1)
			return (-1);
		if (verif_char(s_game->ex, 'E', i, j) == -1)
			return (-1);
		if (s_game->col_id < s_game->nb_col)
			if (verif_char(s_game->col[s_game->col_id], 'C', i, j) == -1)
				return (-1);
		if (s_map->map[i][j] == 'C')
			s_game->col_id++;
		j++;
	}
	return (0);
}

//Vérifie les murs et récupère les informations utiles sur la map

//adapter pour sorties multiples

int	check_map(void)
{
	int		i;
	int		len;
	t_map	*s_map;

	s_map = map();
	if (charset_diff("1", s_map->map[0]) != 0)
			return (-1);	//Verification du mur haut
	if (charset_diff("1", s_map->map[s_map->hei - 1]) != 0)
			return (-1);	//Verification du mur bas
	i = 0;
	while (i < s_map->hei)	//Verification ligne par ligne, i est le numero de ligne
	{
		len = ft_strlen(s_map->map[i]);
		if ((s_map->map[i][0] != '1') || (s_map->map[i][len - 1] != '1'))
			return (-1);	//Verification des murs gauche et droit
		if (verif_utils(i) == -1)
			return (-1);	//Verification et recuperation des positions player, exit, collectibles
		i++;
	}
	return (0);
}