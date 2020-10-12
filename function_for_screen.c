/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:41:28 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 12:41:29 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		restart_map(t_window *win, int flag_colour)
{
	int		y;
	int		x;

	y = 0;
	while (y < win->base->height)
	{
		x = 0;
		while (x < win->base->width)
		{
			win->map[y][x]->x = win->copy_map[y][x]->x;
			win->map[y][x]->y = win->copy_map[y][x]->y;
			win->map[y][x]->z = win->copy_map[y][x]->z;
			win->map[y][x]->flag = win->copy_map[y][x]->flag;
			if (win->map[y][x]->z == 0 && flag_colour == 1)
				win->map[y][x]->colour = win->cyp->colour_swap;
			else
				win->map[y][x]->colour = win->copy_map[y][x]->colour;
			x++;
		}
		y++;
	}
}

t_pos		***copy_map(t_window *win)
{
	t_pos	***map;
	int		y;
	int		x;

	y = 0;
	MALLOCHECK(map = (t_pos***)malloc(sizeof(t_pos**) * win->base->height));
	while (y < win->base->height)
	{
		x = 0;
		MALLOCHECK(map[y] = (t_pos**)malloc(sizeof(t_pos*) * win->base->width));
		while (x < win->base->width)
		{
			MALLOCHECK(map[y][x] = (t_pos *)malloc(sizeof(t_pos)));
			map[y][x]->x = win->map[y][x]->x;
			map[y][x]->y = win->map[y][x]->y;
			map[y][x]->z = win->map[y][x]->z;
			map[y][x]->flag = win->map[y][x]->flag;
			map[y][x]->colour = win->map[y][x]->colour;
			x++;
		}
		y++;
	}
	return (map);
}

void		zoom(t_window *win)
{
	int		x;
	int		y;

	y = 0;
	while (y < win->base->height)
	{
		x = 0;
		while (x < win->base->width)
		{
			win->map[y][x]->x *= win->base->step + win->cyp->zoom;
			win->map[y][x]->y *= win->base->step + win->cyp->zoom;
			if (win->map[y][x]->z != 0)
				win->map[y][x]->z = win->map[y][x]->z * win->base->depth *
						win->cyp->run_z;
			x++;
		}
		y++;
	}
}

void		run(t_window *win)
{
	int		x;
	int		y;

	y = 0;
	while (y < win->base->height)
	{
		x = 0;
		while (x < win->base->width)
		{
			win->map[y][x]->x += win->cyp->run_x;
			win->map[y][x]->y += win->cyp->run_y;
			if (win->map[y][x]->z != 0)
				win->map[y][x]->z += win->cyp->run_z;
			x++;
		}
		y++;
	}
}

void		televisor(t_window *win, int flag_draw, int flag_colour)
{
	restart_map(win, flag_colour);
	zoom(win);
	iso_map(win);
	rotate_map(win);
	start_position(win);
	run(win);
	if (flag_draw == 1)
	{
		mlx_clear_window(win->mlx, win->win);
		while_line(win);
		menu(win);
	}
}
