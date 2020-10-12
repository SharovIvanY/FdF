/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter_pack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:49 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 12:42:50 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void						mister_brezent(t_window *win, t_pos dot1,
		t_pos dot2)
{
	t_pos					delta;
	t_pos					sign;
	t_pos					cur;
	int						error[2];

	delta.x = abs(dot2.x - dot1.x);
	delta.y = abs(dot2.y - dot1.y);
	sign.x = dot1.x < dot2.x ? 1 : -1;
	sign.y = dot1.y < dot2.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = dot1;
	while (cur.x != dot2.x || cur.y != dot2.y)
	{
		mlx_pixel_put(win->mlx, win->win, cur.x, cur.y,\
			get_colour(cur, dot1, dot2, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		error[0] += (error[1] < delta.x ? delta.x : 0);
		cur.y += (error[1] < delta.x ? sign.y : 0);
	}
}

t_create_start_position		*create_start_position(void)
{
	t_create_start_position	*var;

	MALLOCHECK(var = (t_create_start_position*)\
		malloc(sizeof(t_create_start_position)));
	var->max_x = 0;
	var->min_x = 0;
	var->max_y = 0;
	var->min_y = 0;
	var->y = 0;
	var->x = 0;
	return (var);
}

void						start_position_two(t_window *win,
		t_create_start_position *var)
{
	var->x = 0;
	var->y = 0;
	var->max_y = win->map[var->x][var->y]->y;
	var->min_y = win->map[var->x][var->y]->y;
	var->max_x = win->map[var->x][var->y]->x;
	var->min_x = win->map[var->x][var->y]->x;
	while (var->y < win->base->height)
	{
		while (var->x < win->base->width)
		{
			if (win->map[var->y][var->x]->y > var->max_y)
				var->max_y = win->map[var->y][var->x]->y;
			if (win->map[var->y][var->x]->y < var->min_y)
				var->min_y = win->map[var->y][var->x]->y;
			if (win->map[var->y][var->x]->x > var->max_x)
				var->max_x = win->map[var->y][var->x]->x;
			if (win->map[var->y][var->x]->x < var->min_x)
				var->min_x = win->map[var->y][var->x]->x;
			var->x++;
		}
		var->x = 0;
		var->y++;
	}
}

void						start_position(t_window *win)
{
	t_create_start_position	*var;

	var = create_start_position();
	start_position_two(win, var);
	win->base->start_x = win->width / 2;
	win->base->start_y = win->height / 2;
	var->x = 0;
	var->y = 0;
	while (var->y < win->base->height)
	{
		while (var->x < win->base->width)
		{
			win->map[var->y][var->x]->y -= var->min_y -
					(win->height - (var->max_y - var->min_y)) / 2;
			win->map[var->y][var->x]->x += win->base->start_x - var->min_x -
					(var->max_x - var->min_x) / 2;
			var->x++;
		}
		var->y++;
		var->x = 0;
	}
	free(var);
}

void						while_line(t_window *win)
{
	int						x;
	int						y;

	x = 0;
	y = 0;
	while (y < win->base->height)
	{
		while (x < win->base->width)
		{
			if (y + 1 < win->base->height && win->map[y + 1][x]->flag &&
					win->map[y][x]->flag)
				mister_brezent(win, *win->map[y][x], *win->map[y + 1][x]);
			if (x + 1 < win->base->width && win->map[y][x + 1]->flag &&
					win->map[y][x]->flag)
				mister_brezent(win, *win->map[y][x], *win->map[y][x + 1]);
			x++;
		}
		x = 0;
		y++;
	}
}
