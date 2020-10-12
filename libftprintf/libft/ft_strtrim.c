/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 06:44:44 by amace-ty          #+#    #+#             */
/*   Updated: 2018/11/30 18:21:27 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*trim;
	size_t	lenght;

	if (!s)
		return (NULL);
	i = 0;
	lenght = ft_strlen(s);
	while (s[lenght - 1] == ' ' || s[lenght - 1] == '\t'
			|| s[lenght - 1] == '\n')
		lenght--;
	if (lenght)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			i++;
			lenght--;
		}
	}
	trim = (char*)malloc(sizeof(char) * (lenght + 1));
	if (!trim)
		return (NULL);
	ft_strncpy(trim, s + i, lenght);
	trim[lenght] = '\0';
	return (trim);
}
