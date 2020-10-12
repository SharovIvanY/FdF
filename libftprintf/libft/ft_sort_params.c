/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:08:33 by amace-ty          #+#    #+#             */
/*   Updated: 2018/12/05 18:58:01 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sort_params(int a, char **str)
{
	int		i;
	int		j;
	char	*cp;

	i = 1;
	while (i < a)
	{
		j = 1;
		while (str[i + j])
		{
			if (ft_strcmp(str[i], str[i + j]) > 0)
			{
				cp = str[i];
				str[i] = str[i + j];
				str[i + j] = cp;
			}
			j++;
		}
		i++;
	}
}
