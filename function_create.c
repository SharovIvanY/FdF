/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:40:51 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 12:40:54 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					create_height(const char *map)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (map[x])
	{
		if (map[x] == '\n')
			y++;
		x++;
	}
	return (y);
}

int					create_width(const char *map)
{
	int				x;
	int				y;
	int				num;

	x = 0;
	y = 0;
	num = 0;
	while (map[x])
	{
		if (ft_isdigit(map[x]) || map[x] == '-')
		{
			num++;
			while (map[x] != ' ' && map[x] != '\n')
				x++;
		}
		if (map[x] == '\n')
		{
			if (num >= y)
				y = num;
			num = 0;
		}
		x++;
	}
	return (y);
}

void				create_map_two(t_window *win, t_create_map *var,
		t_pos ***map)
{
	while (var->x < var->width + 1)
	{
		MALLOCHECK(map[var->y][var->x] = (t_pos*)malloc(sizeof(t_pos)));
		map[var->y][var->x]->x = var->x;
		map[var->y][var->x]->y = var->y;
		map[var->y][var->x]->z = ft_atoi(var->mas2[var->x]);
		map[var->y][var->x]->flag = 1;
		map[var->y][var->x]->colour = win->cyp->colour_swap;
		if (ft_strchr(var->mas2[var->x], ','))
			map[var->y][var->x]->colour =
			ft_atoi_hex(ft_strchr(var->mas2[var->x], ',') + 3);
		var->x++;
	}
	while (var->x < win->base->width)
	{
		MALLOCHECK(map[var->y][var->x] = (t_pos *)malloc(sizeof(t_pos)));
		map[var->y][var->x]->x = var->x;
		map[var->y][var->x]->y = var->y;
		map[var->y][var->x]->z = 0;
		map[var->y][var->x]->flag = 0;
		map[var->y][var->x]->colour = 0xFFFF00;
		var->x++;
	}
}

t_pos				***create_map(t_window *win, char *str)
{
	t_pos			***map;
	t_create_map	*var;

	var = create_var_map();
	MALLOCHECK(map = (t_pos***)malloc(sizeof(t_pos**) * win->base->height));
	MALLOCHECK(var->mas = ft_strsplit(str, '\n', &var->height));
	while (var->y < win->base->height)
	{
		MALLOCHECK(map[var->y] = (t_pos**)malloc(sizeof(t_pos*)
			* win->base->width + 1));
		MALLOCHECK(var->mas2 = ft_strsplit(var->mas[var->y], ' ', &var->width));
		var->x = 0;
		create_map_two(win, var, map);
		while (var->width >= 0)
			free(var->mas2[var->width--]);
		free(var->mas2);
		var->y++;
	}
	while (var->height >= 0)
		free(var->mas[var->height--]);
	free(var->mas);
	free(var);
	return (map);
}
