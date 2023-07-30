/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:41:29 by hchairi           #+#    #+#             */
/*   Updated: 2022/12/12 11:42:17 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rdjoin(int fd, char *rst)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!(checknew(rst)) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free (buff);
			free (rst);
			return (NULL);
		}
		buff[i] = '\0';
		rst = ft_strjoin(rst, buff);
	}
	free (buff);
	return (rst);
}

char	*get_next_line(int fd)
{
	static char	*rst[OPEN_MAX];
	char		*line;

	if (fd == 1 || fd == 2 || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rst[fd] = ft_rdjoin(fd, rst[fd]);
	if (!rst[fd])
		return (NULL);
	line = ft_line(rst[fd]);
	rst[fd] = ft_rst(rst[fd]);
	return (line);
}
