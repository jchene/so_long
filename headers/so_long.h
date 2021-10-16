/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:10:56 by jchene            #+#    #+#             */
/*   Updated: 2021/10/16 16:37:34 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../utils/minilibx-linux/mlx.h"
# include "../utils/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_color
{
	int		player[4];
	int		walls[4];
	int		coll[4];
	int		exit[4];
	int		floor[4];
	int		init;
}				t_color;

typedef struct s_map
{
	char	**map;
	int		len;
	int		hei;
	int		init;
}				t_map;

typedef struct s_game
{
	int		nb_col;
	int		nb_ex;
	int		col_id;
	int		ex_id;
	int		**col;
	int		**ex;
	int		ps[2];
	int		pa[2];
	int		steps;
	int		init;
}				t_game;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	int		ssizey;
	int		ssizex;
	int		init;
}				t_mlx;

typedef struct s_imdt
{
	int		*bpp;
	int		*ln_size;
	int		*endian;
	char	*start;
	int		init;
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
char	*ft_strcpyn(char *dest, char *src);
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