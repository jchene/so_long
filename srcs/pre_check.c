/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:37:58 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 15:39:22 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Check map size and charset and count collectibles and exits line by line
int	check_line(char *line)
{
	int		len;

	len = ft_strlen(line);
	if (len == 0)
		return (-1);
	if (map()->hei == 0)
		map()->len = len;
	else if (map()->len != len)
		return (-1);
	if (charset_diff("01CEP", line) != 0)
		return (-1);
	(game()->nb_col) += count_occur('C', line);
	(game()->nb_ex) += count_occur('E', line);
	return (0);
}

//Check map size and charset and count collectibles and exits
int	pre_check_map(char *path)
{
	int		id;
	char	*line;

	map()->hei = 0;
	id = open(path, O_RDONLY);
	if (!(id))
		return (-1);
	while (get_next_line(id, &line) || ft_strlen(line) > 0)
	{
		if ((check_line(line)) != 0)
		{
			free(line);
			return (-1);
		}
		map()->hei++;
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	close(id);
	return (0);
}

//Malloc 'map' structure and stores map in it
int	copy_map(char *path)
{
	int		i;
	int		id;
	char	*line;

	id = open(path, O_RDONLY);
	if (!(id))
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
