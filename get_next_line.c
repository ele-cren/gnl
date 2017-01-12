/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:29:53 by ele-cren          #+#    #+#             */
/*   Updated: 2017/01/12 13:56:40 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(const int fd, char **line)
{
	static char	*rest = NULL;
	int			ret;
	char		buff[BUFF_SIZE];
	char		*tmp;

	tmp = NULL;
	if (rest && ft_readrest(&rest, line) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		tmp = ft_strnew(ret);
		ft_memcpy(tmp, buff, ret);
		if (ft_readbuff(tmp, &rest, line) == 1)
			return (1);
		rest = (!rest) ? tmp : ft_freestrjoin(rest, tmp);
	}
	if (rest == NULL)
		return (0);
	*line = rest;
	ft_strdel(&rest);
	return ((ft_strlen(*line) == 0) ? 0 : 1);
}

int		ft_readbuff(char *buff, char **rest, char **line)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_strchr(buff, '\n')))
	{
		*line = ft_strndup(buff, '\n');
		*line = (!*rest) ? *line : ft_freestrjoin(*rest, *line);
		*rest = ft_strdup(tmp + 1);
		free(buff);
		return (1);
	}
	return (0);
}

int		ft_readrest(char **rest, char **line)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_strchr(*rest, '\n')))
	{
		*line = ft_strndup(*rest, '\n');
		*rest = ft_strdup(tmp + 1);
		return (1);
	}
	return (0);
}
