/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:15:10 by drecours          #+#    #+#             */
/*   Updated: 2017/03/03 06:35:18 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_stickin(char *buff, char **line, char **piece, int fd)
{
	int		lenght;
	int		flag;

	flag = 0;
	lenght = ft_taille(buff, 0, '\n');
	if (piece[fd] && piece[fd][0] != '\0')
	{
		*line = ft_strdup(piece[fd]);
		ft_bzero(piece[fd], ft_strlen(piece[fd]));
	}
	if (lenght < BUFF_SIZE && BUFF_SIZE != 1)
	{
		flag = 1;
		piece[fd] = ft_strsub(buff, lenght + 1, (BUFF_SIZE - lenght));
		buff[lenght] = '\0';
	}
	if (!*line)
		*line = ft_strdup(buff);
	else
		*line = ft_strjoin(*line, buff);
	if (flag == 1 || (BUFF_SIZE == 1 && buff[0] == '\n'))
		return (END_OF_LINE);
	return (IN_LINE);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	int				res;
	char			buff[BUFF_SIZE + 1];
	static char		*piece[321];

	ret = 1;
	res = -2;
	ft_bzero(&buff, BUFF_SIZE + 1);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (ERROR);
	while ((ret = read(fd, buff, BUFF_SIZE)) >= 0)
	{
		//*(buff + ret) = '\0';
		if (ret == 0 && !*line)
		{
			*line = ft_strsub("\0", 0, 1);
			return (END_OF_FILE);
		}
		res = ft_stickin(buff, line, piece, fd);
		if (res == 0)
			return (E_SUCCESS);
		else if (res == -1)
			return (ERROR);
		ft_bzero(&buff, BUFF_SIZE + 1);
	}
	return (ERROR);
}
