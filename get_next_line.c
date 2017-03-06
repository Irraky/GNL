/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:15:10 by drecours          #+#    #+#             */
/*   Updated: 2017/03/06 19:13:17 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_stick(char *buff, char **line, char **piece, int ret)
{
	if (!(*piece))
		*piece = ft_strdup(buff);
	else
		*piece = ft_joinfree(*piece, buff, 1);
	if (!(ft_strchr(*piece, '\n')) && ret != 0)
		return (IN_LINE);
	*line = ft_strsub(*piece, 0, ft_taille(*piece, 0, '\n'));
	*piece = ft_strsub(*piece, ft_taille(*piece, 0, '\n') + 1, ft_strlen(*piece)
			- ft_taille(*piece, 0, '\n'));
	if (ret == 0 && !(ft_strchr(*piece, '\n')))
		free(*line);
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
	while ((ret = read(fd, buff, BUFF_SIZE)) >= 0)
	{
		if (ret == 0 && !piece[fd][0])
			return (END_OF_FILE);
		res = ft_stick(buff, line, &piece[fd], ret);
		if (res == 0)
			return (E_SUCCESS);
		if (res == -1)
			return (ERROR);
		ft_bzero(&buff, BUFF_SIZE + 1);
	}
	return (ERROR);
}
