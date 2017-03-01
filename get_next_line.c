/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:15:10 by drecours          #+#    #+#             */
/*   Updated: 2017/03/01 15:59:25 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_stickin(char *buff, char **line, char **piece, int fd)
{
	int		lenght;

	lenght = ft_taille(buff, 0, '\n');
	if (ft_strlen(piece[fd]) != 0)
	{
		*line = ft_strdup(piece[fd]);
		free(*piece);
	}
	if (lenght < BUFF_SIZE)
	{
		piece[fd] = ft_strsub(buff, lenght, (BUFF_SIZE - lenght));
		while (buff[lenght++])
			buff[lenght] = '\0';
		*line = ft_strjoin(*line, buff);
		return (END_OF_LINE);
	}
	*line = ft_strjoin(*line, buff);
	return (IN_LINE);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	int				res;
	char			buff[BUFF_SIZE + 1];
	static char		*piece[321];

	ret = 1;
	res = 0;
	ft_bzero(&buff, BUFF_SIZE + 1);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (ERROR);
	while ((ret = read(fd, buff, BUFF_SIZE)) >= 0)
	{
		if (ft_strlen(piece[fd]) == 0 && ret == 0)
			return (END_OF_FILE);
		res = ft_stickin(buff, line, piece, fd);
		if (res == 0)
			return (E_SUCCESS);
		else if (res == -1)
			return (ERROR);
		ft_bzero(&buff, BUFF_SIZE + 1);
	}
	return (ERROR);
}
