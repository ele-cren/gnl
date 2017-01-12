/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:27:43 by ele-cren          #+#    #+#             */
/*   Updated: 2017/01/12 13:37:47 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strndup(char *str, int c)
{
	unsigned char	cc;
	int				i;
	char			*new;

	if (str && c)
	{
		cc = (unsigned char)c;
		i = 0;
		while (str[i] != cc && str[i])
			i++;
		new = ft_strnew(i + 1);
		i = -1;
		while (str[++i] != cc && str[i])
			new[i] = str[i];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
