/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:41:16 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 17:00:28 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_pos *map, t_window *win)
{
	double	previous_y;
	double	previous_z;

	previous_y = map->y;
	previous_z = map->z;
	map->y = previous_y * cos(win->cyp->rot_x) + previous_z *
			sin(win->cyp->rot_x);
	map->z = -previous_y * sin(win->cyp->rot_x) + previous_z *
			cos(win->cyp->rot_x);
}

void		rotate_y(t_pos *map, t_window *win)
{
	double	previous_x;
	double	previous_y;
	double	previous_z;

	previous_x = map->x;
	previous_y = map->x;
	previous_z = map->z;
	map->x = previous_x * cos(win->cyp->rot_y) + previous_z *
			sin(win->cyp->rot_y);
	map->z = -previous_y * sin(win->cyp->rot_y) + previous_z *
			cos(win->cyp->rot_y);
}

void		rotate_z(t_pos *map, t_window *win)
{
	double	previous_y;
	double	previous_x;

	previous_y = map->y;
	previous_x = map->x;
	map->x = previous_x * cos(win->cyp->rot_z) - previous_y *
			sin(win->cyp->rot_z);
	map->y = previous_x * sin(win->cyp->rot_z) + previous_y *
			cos(win->cyp->rot_z);
}

void		rotate_map(t_window *win)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < win->base->height)
	{
		while (x < win->base->width)
		{
			rotate_x(win->map[y][x], win);
			rotate_y(win->map[y][x], win);
			rotate_z(win->map[y][x], win);
			x++;
		}
		y++;
		x = 0;
	}
}

void		key_rotate_2(int key, t_window *win)
{
	if (key == Q)
	{
		win->cyp->rot_z += 0.1;
		televisor(win, 1, win->cyp->flag_paint);
	}
	if (key == E)
	{
		win->cyp->rot_z -= 0.1;
		televisor(win, 1, win->cyp->flag_paint);
	}
}
