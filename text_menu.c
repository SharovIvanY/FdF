/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:55 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 13:30:41 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_window *win)
{
	mlx_string_put(win->mlx, win->win, 20, 20, 0xC3BFD4,\
			"press TAB to show MENU");
}
