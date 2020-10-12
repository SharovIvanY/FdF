/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:25 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:20 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			controls(t_window *win)
{
	mlx_hook(win->win, 2, 0, key_press, win);
	mlx_hook(win->win, 17, 0, close, win);
	mlx_hook(win->win, 17, 0, expose, win);
}

void			key_menu(int key, t_window *win)
{
	if (key == 48)
	{
		if (win->cyp->war == 0)
		{
			win->cyp->war = 1;
			mlx_string_put(win->mlx, win->win,\
					20, 50, 0x7291F3, "space - map reset");
			mlx_string_put(win->mlx, win->win,\
					20, 70, 0x7291F3, "2,3,4,5 - isometry");
			mlx_string_put(win->mlx, win->win,\
					20, 90, 0x7291F3, "-,+ - zoom");
			mlx_string_put(win->mlx, win->win,\
					20, 110, 0x7291F3, "up,down,left,right - move map");
			mlx_string_put(win->mlx, win->win,\
					20, 130, 0x7291F3, "<,> - depth z");
			mlx_string_put(win->mlx, win->win,\
					20, 150, 0x7291F3, "w,a,s,d - rotate");
			mlx_string_put(win->mlx, win->win,\
					20, 170, 0x7291F3, "z,x,c - change colour");
			mlx_string_put(win->mlx, win->win,\
					20, 190, 0x7291F3, "esc - exit program");
		}
	}
}

int				key_press(int key, void *fdf)
{
	t_window	*win;

	win = fdf;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key != 48)
	{
		win->cyp->war = 0;
		televisor(win, 1, win->cyp->flag_paint);
	}
	key_iso1(key, win);
	key_iso2(key, win);
	key_iso3(key, win);
	key_iso4(key, win);
	key_move(key, win);
	key_centr(key, win);
	key_z(key, win);
	key_zoom(key, win);
	key_rotate(key, win);
	key_colour(key, win);
	key_menu(key, win);
	return (0);
}

int				expose(void *param)
{
	t_window	*win;

	win = param;
	exit(0);
}

void			key_colour_two(int key, t_window *win)
{
	if (key == C)
	{
		if (win->cyp->colour_swap == win->cyp->colour_black)
			win->cyp->colour_swap = 0x940805;
		else
			win->cyp->colour_swap = win->cyp->colour_black;
		win->cyp->flag_paint = 1;
		televisor(win, 1, win->cyp->flag_paint);
	}
}
