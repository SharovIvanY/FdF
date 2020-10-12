/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:40:09 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 12:40:12 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf(t_window *win)
{
	win->win = mlx_new_window(win->mlx, win->width, win->height,
	"OUTSTANDING PROJECT");
	win->copy_map = copy_map(win);
	restart_map(win, 0);
	televisor(win, 0, 0);
	while (win->map[0][0]->x < 0 || win->map[0][0]->y < 0)
	{
		win->cyp->zoom -= 5;
		televisor(win, 0, 0);
	}
	win->cyp->save_zoom = win->cyp->zoom;
	televisor(win, 1, 0);
	controls(win);
	mlx_loop(win->mlx);
}

int				main(int argc, char **argv)
{
	t_window	*win;
	char		*read;

	if (argc == 2)
	{
		win = inicialization_win();
		read = ft_preparser(argv[1]);
		map_check(read, argv[1]);
		win->base = create_base(read);
		win->cyp = create_cyp();
		win->map = create_map(win, read);
		free(read);
		fdf(win);
	}
	else
		ft_putstr("usage: ./fdf map_name\n");
	return (0);
}
