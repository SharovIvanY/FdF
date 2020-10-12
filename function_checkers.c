/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:40:33 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 14:05:27 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					check_colour(char *str, int *i)
{
	char			*src;
	int				x;

	src = "0x123456789abcdef";
	x = 0;
	while (str[x])
	{
		if (!ft_strchr(src, str[x]))
			return (1);
		x++;
	}
	*i = x;
	return (0);
}

void				check_map_two(t_check_map *var, char *file)
{
	var->i = 0;
	MALLOCHECK(var->split_d = ft_strsplit(var->split_x[var->x], ',',
			&var->err3));
	while (var->split_d[0][var->i])
	{
		if (!ft_isdigit(var->split_d[0][var->i]) &&
				var->split_d[0][var->i] != '-')
		{
			ft_printf("Invalid map: \"%s\"\nInvalid simbol: \"%c\"\n",\
				file, var->split_d[0][var->i]);
			exit(0);
		}
		ft_atoi_with_err(var->split_d[0] + var->i, &var->z);
		if (var->z == 1)
		{
			ft_printf("Invalid map: \"%s\"\nInvalid simbol: \"%c\"\n",\
				file, var->split_d[0][var->i]);
			exit(0);
		}
		var->i++;
	}
}

void				check_map_one(t_check_map *var, char *file)
{
	MALLOCHECK(var->split_x = ft_strsplit(var->split_y[var->y], ' ',
			&var->err2));
	while (var->x <= var->err2)
	{
		check_map_two(var, file);
		if (var->err3 > 1)
		{
			var->i = 0;
			if (check_colour(var->split_d[1], &var->i) || var->i < 2\
					|| var->i > 8 || var->split_d[1][0] != '0' ||\
					var->split_d[1][1] != 'x')
			{
				ft_printf("Invalid map: \"%s\"\nInvalid colour: \"%s\"\n",\
					file, var->split_d[1]);
				ft_putchar('\n');
				exit(0);
			}
		}
		while (var->err3 >= 0)
			free(var->split_d[var->err3--]);
		free(var->split_d);
		var->x++;
	}
}

void				map_check_mini(const char *map, char *file)
{
	int x;
	int flag;

	flag = 0;
	x = 0;
	while (map[x])
	{
		if (map[x] != '\n' && (ft_isdigit(map[x]) || map[x] == '-'))
			flag = 0;
		else if (flag == 1)
		{
			flag = 0;
			break ;
		}
		if (map[x] == '\n')
			flag = 1;
		x++;
	}
	if (flag != 1)
	{
		ft_printf("Invalid map: \"%s\"\nno or more: \"\\n\"\n", file);
		exit(0);
	}
}

int					map_check(char *map, char *file)
{
	t_check_map		*var;

	map_check_mini(map, file);
	var = create_check_map();
	MALLOCHECK(var->split_y = ft_strsplit(map, '\n', &var->err));
	while (var->y <= var->err)
	{
		check_map_one(var, file);
		while (var->err2 >= 0)
			free(var->split_x[var->err2--]);
		free(var->split_x);
		var->x = 0;
		var->y++;
	}
	while (var->err >= 0)
		free(var->split_y[var->err--]);
	free(var->split_y);
	free(var);
	return (0);
}
