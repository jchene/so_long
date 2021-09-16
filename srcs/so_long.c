/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:59:05 by jchene            #+#    #+#             */
/*   Updated: 2021/09/16 18:44:38 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int		err_code(int code)
{
	if (code == -1)
		printf("Wrong number of arguments\n");
	else if (code == -2)
		printf("Failed to open map\n");
	else if (code == -3)
		printf("Failed to malloc map structure\n");
	else if (code == -4)
		printf("Invalid map\n");
	else if (code == -5)
		printf("Failed to copy map\n");
	return (-1);
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->hei)
		free(map->map[i++]);
	free(map->map);
}

int		munalloc(int code, t_map *map)
{
	printf("code: %d\n", code);
	if (code < -4 || code == 0)
		free_map(map);
	if (code < -3 || code == 0)
		free(map);
	return (0);
}

//Malloc 'map' dans la sructure 'map' et y copie la map
int		copy_map(char *path, t_map *map)
{
	int		i;
	int		id;
	char	*line;

	if (!(id = open(path, O_RDONLY)))
		return (-1);
	if (!(map->map = (char **)malloc(sizeof(char *) * map->hei)))
		return (-1);
	i = 0;
	while (i < map->hei)
		if (!(map->map[i++] = (char *)malloc((sizeof(char) * map->len) + 1)))
			return (-1);
	i = 0;
	printf("test\n");
	while (get_next_line(id, &line) || ft_strlen(line) > 0)
	{
		ft_strcpyn(map->map[i++], line);
		printf("copied: '%s'\n", line);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	return (0);
}

int		main(int argc, char **argv)
{
    //t_var	*var;
	t_map	*map;
	//t_mlx	*mlx;

	if (argc != 2)
		return (err_code(-1));

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (err_code(-3));

	if (parse_map(argv[1], map) == -1)
		return (err_code(-4) + munalloc(-4, map));

	if (copy_map(argv[1], map) == -1)
		return (err_code(-5) + munalloc(-5, map));

	printf("Well done\n");
	munalloc(0, map);
	return (0);
}
