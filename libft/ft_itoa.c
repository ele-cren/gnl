/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:48:44 by ele-cren          #+#    #+#             */
/*   Updated: 2016/11/18 16:03:39 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"
#include <string.h>

static char		*ft_write(char *str, int n, int neg)
{
	int					i;
	int					j;
	unsigned int		nb;

	i = 0;
	j = ft_count(n);
	nb = n;
	if (neg == 1)
	{
		str[i] = '-';
		n = -n;
		i++;
	}
	while (i < ft_count(nb) + neg)
	{
		str[i] = n / (ft_powten(j)) + '0';
		n = n - (n / (ft_powten(j)) * ft_powten(j));
		i++;
		j--;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(*str) * (ft_count(n) + 1 + neg));
	if (str == NULL)
		return (NULL);
	str = ft_write(str, n, neg);
	return (str);
}
