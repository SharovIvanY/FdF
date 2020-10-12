/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:38 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 12:42:40 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_centr(int key, t_window *win)
{
	if (key == SPACE)
	{
		win->cyp->run_x = 0;
		win->cyp->run_y = 0;
		win->cyp->run_z = 0;
		win->cyp->type_iso = 0;
		win->cyp->zoom = win->cyp->save_zoom;
		win->cyp->rot_x = 0;
		win->cyp->rot_y = 0;
		win->cyp->rot_z = 0;
		win->cyp->colour_swap = 0x05FFB7;
		win->cyp->flag_paint = 0;
		televisor(win, 1, win->cyp->flag_paint);
	}
}

void	key_move(int key, t_window *win)
{
	if (key == ARROW_UP)
	{
		win->cyp->run_y += -50;
		televisor(win, 1, win->cyp->flag_paint);
		win->cyp->war = 0;
	}
	if (key == ARROW_DOWN)
	{
		win->cyp->run_y += 50;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == ARROW_LEFT)
	{
		win->cyp->run_x += -50;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == ARROW_RIGHT)
	{
		win->cyp->run_x += 50;
		televisor(win, 1, win->cyp->flag_paint);
	}
}

void	key_z(int key, t_window *win)
{
	if (key == MAIN_PAD_MORE)
	{
		win->cyp->run_z += 1;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == MAIN_PAD_LESS)
	{
		win->cyp->run_z -= 1;
		televisor(win, 1, win->cyp->flag_paint);
	}
}

void	key_zoom(int key, t_window *win)
{
	if (key == MAIN_PAD_PLUS)
	{
		win->cyp->zoom += 5;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == MAIN_PAD_MINUS)
	{
		if (win->cyp->zoom > -49)
			win->cyp->zoom -= 5;
		televisor(win, 1, win->cyp->flag_paint);
	}
}

void	key_rotate(int key, t_window *win)
{
	if (key == S)
	{
		win->cyp->rot_x += 0.1;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == W)
	{
		win->cyp->rot_x -= 0.1;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == A)
	{
		win->cyp->rot_y += 0.1;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == D)
	{
		win->cyp->rot_y -= 0.1;
		televisor(win, 1, win->cyp->flag_paint);
	}
	key_rotate_2(key, win);
}
