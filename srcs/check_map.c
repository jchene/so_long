/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:16:01 by jchene            #+#    #+#             */
/*   Updated: 2021/09/16 20:03:43 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/*Retourne 0 si 'c' est charset, -1 sinon*/
int		char_diff(const char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i])
		if (charset[i++] == c)
			return (0);
	return (-1);
}

/*Retourne 0 si tout les caracteres de 'string' sont charset, -1 sinon*/
int		charset_diff(const char *charset, char *line)
{
	int		i;

	i = 0;
	while (line[i])
		if (char_diff(charset, line[i++]) == -1)
			return (-1);
	return (0);
}

/*Vérifie la longueur et le charset de la ligne*/
int		check_line(char *line, t_map *map)
{
	int		len;
	int		open_walls;

	open_walls = 0;
	len = ft_strlen(line);

	if (len == 0)
		return (-1);
	else if ((map->hei > 0) && (open_walls == 0)) //si ligne non vide et murs fermes alors erreur (excluant premiere ligne)
		return (-1);

	if (map->hei == 0) //si premiere ligne stockage de la len et verification des murs
	{
		map->len = len;
		if (charset_diff("1", line) != 0)
			return (-1);
		open_walls = 1;
	}
	else if (map->len != len) //comparaison de la len de line et de la len enregistrée (excluant premiere ligne)
		return (-1);


	if (charset_diff("01CEP", line) != 0)
		return (-1);
	return (0);
}

/*Lis la map et verifie la longueur, charset et les murs ligne par ligne*/
int		parse_map(char *path, t_map *map)
{
	int		id;
	char	*line;

	map->hei = 0;
	if (!(id = open(path, O_RDONLY)))
		return (-1);
	while (get_next_line(id, &line) || ft_strlen(line) > 0)
	{
		printf("Checking line:'%s'\n", line);
		if (check_line(line, map) == -1)
		{
			free(line);
			return (-1);
		}
		map->hei++;
		free(line);
		line = NULL;
	}
	printf("line: '%s'\n", line);
	printf("hei: %d\n", map->hei);
	if (line)
		free(line);
	close(id);
	return (0);
}