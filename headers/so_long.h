/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:10:56 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 15:47:56 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../utils/minilibx-linux/mlx.h"
# include "../utils/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_color	//colors B:[0] G:[1] R:[2] T:[3] - malloc start mlx
{
	int		player[4];	//player colors - malloc init color
	int		walls[4];	//wall colors - malloc init color
	int		coll[4];	//collectibles color - malloc init color
	int		exit[4];	//exit color - malloc init color
	int		floor[4];	//floor color - malloc init color
	int		init;		//init of structure
}				t_color;

typedef struct	s_map	//map related variables - malloc main
{
	char	**map;		//array containing the copied map - malloc copy map
	int		len;		//length of map - init check line
	int		hei;		//height of map - init pre check map
	int		init;		//init of structure
}				t_map;

typedef struct	s_game
{
	int		nb_col;		//number of collectibles in map
	int		nb_ex;		//number of exits in map
	int		col_id;		//id of collectible program is working on
	int		ex_id;		//id of exit program is working on
	int		**col;		//collectibles positions y:[][0] x:[][1] eaten:[][2] - malloc copy map
	int		**ex;		//exits positions y:[][0] x:[][1] eaten:[][2] - malloc copy map
	int		ps[2];		//player starting position y:[0] x:[1] - malloc copy map
    int		pa[2];		//player actual position y:[0] x:[1] - malloc copy map
	int		steps;		//number of steps from the start
	int		init;		//init of structure
}				t_game;

typedef struct	s_mlx	//minilibx related variables - malloc main
{
	void	*ptr;		//mlx pointer - start mlx
	void	*win;		//windows pointer - start mlx
	void	*img;		//image pointer - start mlx
	int		ssizey;		//y size of game window
	int		ssizex;		//x size of game window
	int		init;		//init of structure
}				t_mlx;

typedef struct	s_imdt	//image data - update img
{
	int		*bpp;		//bits per pixel - update img
	int		*ln_size;	//line size - update img
	int		*endian;	//endian - update img
	char	*start;		//start of img pointer - update img
	int		init;		//init of structure
}				t_imdt;

//multi-usage functions
int		char_diff(const char *charset, char c);
int		charset_diff(const char *charset, char *line);
int		count_occur(const char c, char *line);
int		extdif(const char *ext, char *dot);
int		check_ext(const char *ext, char *filename);

//structure address functions
t_color	*color(void);
t_map	*map(void);
t_game	*game(void);
t_mlx	*mlx(void);
t_imdt	*imdt(void);

//structures initialisation functions
void	init_elem_color(int *elem, int blu, int gre, int red);
int		init_imdt(void);
int		init_map_array(void);
int		init_game_arrays(void);

//map pre-checking functions
int		check_line(char *line);
int		pre_check_map(char *path);
int		copy_map(char *path);

//map checking functions
int		verif_char(int *ptr, char c, int i, int j);
int		verif_utils(int i);
int		check_map(void);

//memory and error functions
void	ft_bzero(void *b, size_t n);
int		err_code(int code);
int		munalloc(int code);

//memory freeing functions
void	free_map(void);
void	free_game(void);
void	free_imdt(void);
void	free_mlx(void);

//color functions
void	init_color(void);
int		get_color(int line, int column, int part);
int		get_coll_n(int y, int x);

//mlx functions
void	encounters(int key);
int		handle_keys(int key, int null);
int		draw_img(void);
int		update_img(int null);
int		start_mlx(void);
#endif