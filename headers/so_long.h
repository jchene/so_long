/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:10:56 by jchene            #+#    #+#             */
/*   Updated: 2021/09/16 18:44:38 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
# include "../utils/minilibx-linux/mlx.h"
# include "../utils/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>


typedef struct	s_var	//game related variables
{
    int		steps;		//number of steps from the start
    int		pa_x;		//player actual x position
    int		pa_y;		//player actual y position
}				t_var;

typedef struct	s_map	//map related variables
{
	char	**map;		//array containing the copied map
	int		len;		//length of map
	int		hei;		//height of map
	int		ps_x;		//player starting x position
    int		ps_y;		//player starting y position
}				t_map;

typedef struct	s_mlx	//minilinx related variables
{
	void	*ptr;		//mlx pointer
	void	*win;		//windows pointer
	void	*img;		//image pointer
}				t_mlx;

//map parsing
int		char_diff(const char *charset, char c);
int		charset_diff(const char *charset, char *line);
int		check_line(char *line, t_map *map);
int		parse_map(char *path, t_map *map);
#endif