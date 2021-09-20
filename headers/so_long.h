/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:10:56 by jchene            #+#    #+#             */
/*   Updated: 2021/09/20 17:10:59 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
# include "../utils/minilibx-linux/mlx.h"
# include "../utils/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_map	//map related variables - malloc main
{
	char	**map;		//array containing the copied map - malloc copy map
	int		len;		//length of map
	int		hei;		//height of map
	int		nb_col;		//number of collectibles in map
	int		col_id;		//id of collectible program is working on
	int		*ps;		//player starting position y:[0] x:[1] - malloc copy map
    int		*pa;		//player actual position y:[0] x:[1] - malloc copy map
	int		*ex;		//exit position y:[0] x:[1] - malloc copy map
	int		**col;		//collectibles positions y:[][0] x:[][1] - malloc copy map
	int		steps;		//number of steps from the start
}				t_map;

typedef struct	s_mlx	//minilibx related variables - malloc main
{
	void	*ptr;		//mlx pointer - start mlx
	void	*win;		//windows pointer - start mlx
	void	*img;		//image pointer - start mlx
	int		*ssizey;	//y size of game window
	int		*ssizex;	//x size of game window
	t_map	*map;		//map structure pointer
}				t_mlx;

typedef struct	s_imdt	//image data - update img
{
	int		*bpp;		//bytes per pixel - update img
	int		*ln_size;	//line size - update img
	int		*endian;	//endian - update img
	char	*start;		//start of img pointer - update img
}				t_imdt;


//multi-usage functions
int		char_diff(const char *charset, char c);
int		charset_diff(const char *charset, char *line);
int		count_occur(const char c, char *line);

//map parsing functions
int		check_line(char *line, t_map *map);
int		pre_check_map(char *path, t_map *map);
int		copy_map(char *path, t_map *map);
int		init_map(t_map *map);
int		verif_char(t_map *map, int *ptr, char c, int i, int j);
int		verif_utils(t_map *map, int i);
int		check_map(t_map *map);

//memory and error functions
int		err_code(int code);
void	free_map(t_map *map);
int		munalloc(int code, t_map *map, t_mlx *mlx);

//mlx functions
int		handle_keys(int key, t_mlx *mlx);
int		init_imdt(t_imdt *imdt, t_mlx *mlx);
//int		draw_img(t_imdt *imdt, t_mlx *mlx);
int		update_img(t_mlx *mlx);
int		start_mlx(t_map *map, t_mlx *mlx);
#endif