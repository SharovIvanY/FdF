/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:40:18 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 17:00:08 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "libftprintf/ft_printf.h"
# include "keycode.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# define SIZEX 2000
# define SIZEY 1000
# define INT_MIN (2147483648)
# define INT_MAX (2147483647)
# define MALLOCHECK(x) if (!(x)) exit (0);

typedef struct				s_create_start_position
{
	int						max_y;
	int						min_y;
	int						max_x;
	int						min_x;
	int						x;
	int						y;
}							t_create_start_position;

typedef struct				s_create_map
{
	char					**mas;
	char					**mas2;
	int						height;
	int						width;
	int						y;
	int						x;
}							t_create_map;

typedef struct				s_check_map
{
	char					**split_y;
	char					**split_x;
	char					**split_d;
	int						i;
	int						z;
	int						err;
	int						err2;
	int						err3;
	int						x;
	int						y;
}							t_check_map;

typedef struct				s_pos
{
	int						x;
	int						y;
	int						z;
	int						flag;
	int						colour;
}							t_pos;

typedef struct				s_base
{
	int						width;
	int						height;
	int						depth;
	int						start_x;
	int						start_y;
	int						step;
	int						flag_null;
}							t_base;

typedef struct				s_cyp
{
	int						type_iso;
	int						run_x;
	int						run_y;
	int						run_z;
	int						zoom;
	int						save_zoom;
	double					rot_x;
	double					rot_y;
	double					rot_z;
	int						colour_swap;
	int						colour_black;
	int						flag_paint;
	int						war;
}							t_cyp;

typedef struct				s_window
{
	void					*mlx;
	void					*win;
	int						width;
	int						height;
	t_pos					***map;
	t_pos					***copy_map;
	t_base					*base;
	t_cyp					*cyp;
}							t_window;

t_create_map				*create_var_map(void);
t_cyp						*create_cyp(void);
t_base						*create_base(char *map);
t_check_map					*create_check_map(void);
t_window					*inicialization_win(void);
void						create_map_two(t_window *win, t_create_map *var,
		t_pos ***map);
t_pos						***create_map(t_window *win, char *str);
int							create_height(const char *map);
int							create_width(const char *map);
int							check_colour(char *str, int *i);
void						check_map_two(t_check_map *var, char *file);
void						check_map_one(t_check_map *var, char *file);
void						map_check_mini(const char *map, char *file);
int							map_check(char *map, char *file);
void						restart_map(t_window *win, int flag_colour);
t_pos						***copy_map(t_window *win);
void						televisor(t_window *win, int flag_draw,\
									int flag_colour);
void						run(t_window *win);
void						zoom(t_window *win);
void						iso_map(t_window *win);
void						iso(t_pos *map);
void						iso2(t_pos *map);
void						iso3(t_pos *map);
void						iso4(t_pos *map);
char						*ft_parser(int fd, ssize_t x);
char						*ft_preparser(char *file);
void						rotate_map(t_window *win);
void						rotate_x(t_pos *map, t_window *win);
void						rotate_y(t_pos *map, t_window *win);
void						mister_brezent(t_window *win, t_pos dot1,
		t_pos dot2);
t_create_start_position		*create_start_position(void);
void						start_position_two(t_window *win,
		t_create_start_position *var);
void						start_position(t_window *win);
void						while_line(t_window *win);
int							ft_atoi_with_err(const char *str, int *err);
int							ft_atoi_hex(const char *str);
void						fdf(t_window *win);
int							main(int argc, char **argv);
void						controls(t_window *win);
void						key_menu(int key, t_window *win);
int							key_press(int key, void *fdf);
int							expose(void *param);
void						key_colour_two(int key, t_window *win);
void						key_iso1(int key, t_window *win);
void						key_iso2(int key, t_window *win);
void						key_iso3(int key, t_window *win);
void						key_iso4(int key, t_window *win);
void						key_colour(int key, t_window *win);
void						key_centr(int key, t_window *win);
void						key_move(int key, t_window *win);
void						key_z(int key, t_window *win);
void						key_zoom(int key, t_window *win);
void						key_rotate(int key, t_window *win);
void						key_rotate_2(int key, t_window *win);
int							get_colour(t_pos current, t_pos start,\
									t_pos end, t_pos delta);
void						menu(t_window *win);

#endif
