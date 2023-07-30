/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:26:12 by hchairi           #+#    #+#             */
/*   Updated: 2023/07/05 18:16:11 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rdjoin(int fd, char *rst)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!checknew(rst) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free (buff);
			free(rst);
			return (NULL);
		}
		buff[i] = '\0';
		rst = ft_strjoin(rst, buff);
	}
	free(buff);
	return (rst);
}

char	*get_next_line(int fd)
{
	static char	*rst;
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (0);
	rst = ft_rdjoin(fd, rst);
	if (!rst)
		return (NULL);
	line = ft_line(rst);
	rst = ft_rst(rst);
	return (line);
}	

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
//     int fd;

//     fd = open("test.txt", O_CREAT | O_RDWR);
//     // if (fd == -1)
//     // {
//     //     printf("Error");
//     //     return (1);
//     // }
//     char *line = get_next_line(fd);
//     while (line)
//     {
//         printf("%s", line);
//         line = get_next_line(fd);
//     }
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
// }