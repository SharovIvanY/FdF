/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_for_iso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:39:44 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 12:39:53 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_iso1(int key, t_window *win)
{
	if (key == MAIN_PAD_2)
	{
		if (win->cyp->type_iso == 1)
		{
			win->cyp->type_iso = 0;
			televisor(win, 1, win->cyp->flag_paint);
		}
		else
		{
			win->cyp->type_iso = 1;
			televisor(win, 1, win->cyp->flag_paint);
		}
	}
}

void	key_iso2(int key, t_window *win)
{
	if (key == MAIN_PAD_3)
	{
		if (win->cyp->type_iso == 2)
		{
			win->cyp->type_iso = 0;
			televisor(win, 1, win->cyp->flag_paint);
		}
		else
		{
			win->cyp->type_iso = 2;
			televisor(win, 1, win->cyp->flag_paint);
		}
	}
}

void	key_iso3(int key, t_window *win)
{
	if (key == MAIN_PAD_4)
	{
		if (win->cyp->type_iso == 3)
		{
			win->cyp->type_iso = 0;
			televisor(win, 1, win->cyp->flag_paint);
		}
		else
		{
			win->cyp->type_iso = 3;
			televisor(win, 1, win->cyp->flag_paint);
		}
	}
}

void	key_iso4(int key, t_window *win)
{
	if (key == MAIN_PAD_5)
	{
		if (win->cyp->type_iso == 4)
		{
			win->cyp->type_iso = 0;
			televisor(win, 1, win->cyp->flag_paint);
		}
		else
		{
			win->cyp->type_iso = 4;
			televisor(win, 1, win->cyp->flag_paint);
		}
	}
}

void	key_colour(int key, t_window *win)
{
	if (key == Z)
	{
		if (win->cyp->colour_swap == win->cyp->colour_black)
			win->cyp->colour_swap = 0x05FFB7;
		else
			win->cyp->colour_swap = win->cyp->colour_black;
		win->cyp->flag_paint = 1;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == X)
	{
		if (win->cyp->colour_swap == win->cyp->colour_black)
			win->cyp->colour_swap = 0x440887;
		else
			win->cyp->colour_swap = win->cyp->colour_black;
		win->cyp->flag_paint = 1;
		televisor(win, 1, win->cyp->flag_paint);
		win->cyp->war = 0;
	}
	key_colour_two(key, win);
}
