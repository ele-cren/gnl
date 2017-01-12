/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:19:13 by ele-cren          #+#    #+#             */
/*   Updated: 2017/01/12 14:46:28 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "includes/libft.h"

char	*ft_freestrjoin(const char *s1, const char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 && s2)
	{
		new = NULL;
		i = 0;
		j = 0;
		new = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + \
					ft_strlen((char *)s2) + 1));
		if (!new)
			return (NULL);
		while (s1[i])
			new[j++] = s1[i++];
		free((char *)s1);
		i = 0;
		while (s2[i])
			new[j++] = s2[i++];
		free((char *)s2);
		new[j] = '\0';
		return (new);
	}
	return (NULL);
}
