/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:50:34 by jchene            #+#    #+#             */
/*   Updated: 2021/10/13 19:19:53 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Initialise la structure 'game' relative aux variables du jeu
void	init_s_game(void)
{
	int 	i;
	t_game	*s_game;

	s_game = game();
	s_game->ps[0] = -1;
	s_game->ps[1] = -1;
	s_game->pa[0] = -1;
	s_game->pa[1] = -1;
	s_game->ex[0] = -1;
	s_game->ex[1] = -1;
	s_game->nb_col = 0;
	s_game->col_id = 0;
	s_game->nb_ex = 0;
}

int	init_map_array(void)
{
	int		i;
	t_map	*s_map;

	i = 0;
	s_map = map();
	if (!(s_map->map = (char **)malloc(sizeof(char *) * s_map->hei)))
		return (-1);
	while (i < s_map->hei)
		if (!(s_map->map[i++] = (char *)malloc(sizeof(char) * s_map->len)))
			return (-1);
	return (0);
}

int	init_game_array(void)
{
	int		i;
	t_game	*s_game;

	i = 0;
	s_game = game();
	if (!(s_game->col = (int **)malloc(sizeof(int *) * s_game->nb_col)))
		return (-1);
	while (i < s_game->nb_col)
	{
		if (!(s_game->col[i] = (int *)malloc(sizeof(int) * 3)))
			return (-1);
		s_game->col[i][0] = -1;
		s_game->col[i][1] = -1;
		s_game->col[i][2] = 0;
		i++;
	}
	i = 0;
	if (!(s_game->ex = (int **)malloc(sizeof(int *) * s_game->nb_ex)))
		return (-1);
	while (i < s_game->nb_ex)
	{
		if (!(s_game->ex[i] = (int *)malloc(sizeof(int) * 3)))
			return (-1);
		s_game->col[i][0] = -1;
		s_game->col[i][1] = -1;
		s_game->col[i][2] = 0;
		i++;
	}
	return (0);
}