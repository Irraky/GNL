/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:15:10 by drecours          #+#    #+#             */
/*   Updated: 2017/03/04 18:17:41 by drecours         ###   ########.fr       */
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
		*line = ft_strsub(piece[fd], 0, ft_taille(piece[fd] + 1, 0, '\n'));
		piece[fd] = ft_strsub(piece[fd], ft_taille(piece[fd], 0, '\n') - 1, strlen(piece[fd]) - ft_taille(piece[fd], 0, '\n'));
		if (piece[fd][0] == '\n')
			return (END_OF_LINE);
	}
	if (buff[BUFF_SIZE] == '\n' || (lenght < BUFF_SIZE && BUFF_SIZE != 1))
	{
		flag = 1;
	//	if (buff[BUFF_SIZE] == '\n')
	//		piece[fd] = strdup("\n");
	//	else
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

int		ft_stick(char *buff, char **line, char **piece)
{
	char	*tmp;

	write(1, "1", 1);
	if (!(*piece))
		*piece = strdup(buff);
	else
		*piece = ft_strjoin(*piece, buff);
	write(1, "1", 1);
	//printf("%s\n", *piece);
	if (ft_taille(*piece, 0, '\n') == (int)strlen(*piece) && (*piece)[strlen(*piece)] != '\n')
	{
		if (!*line)
			*line = strdup(*piece);
		else
			*line = ft_strjoin(*line, *piece);
		free(*piece);
		return (IN_LINE);
	}
	tmp = ft_strsub(*piece, 0, ft_taille(*piece, 0, '\n'));
	if (!*line)
		*line = strdup(tmp);
	else
		*line = ft_strjoin(*line, tmp);
	*piece = ft_strsub(*piece, ft_taille(*piece, 0, '\n'), strlen(*piece) - ft_taille(*piece, 0, '\n'));
	return (END_OF_LINE);
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
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 || piece[fd][0] != '\0')
	{
		//*(buff + ret) = '\0';
		res = ft_stick(buff, line, piece + fd);
		if (res == 0)
			return (E_SUCCESS);
		else if (res == -1)
			return (ERROR);
		ft_bzero(&buff, BUFF_SIZE + 1);
	}
	if (ret == 0)
		return(END_OF_FILE);
	return (ERROR);
}
