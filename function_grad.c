/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_grad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:41:37 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 12:41:39 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_colour(t_pos current, t_pos start, t_pos end, t_pos delta)
{
	int			red;
	int			green;
	int			blue;
	double		percentage;

	if (current.colour == end.colour)
		return (current.colour);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.colour >> 16) & 0xFF, (end.colour >> 16) & 0xFF,
			percentage);
	green = get_light((start.colour >> 8) & 0xFF, (end.colour >> 8) & 0xFF,
			percentage);
	blue = get_light(start.colour & 0xFF, end.colour & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
