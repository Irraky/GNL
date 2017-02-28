/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:15:10 by drecours          #+#    #+#             */
/*   Updated: 2017/02/28 17:56:10 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_stickin(char *buff, char *line, char *piece)
{
	si \n trouve return e success
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*buff[BUFF_SIZE + 1];
	static char		*piece;

	ret = 1;
	ft_bzero(*buff);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (ERROR);
	while ((ret = read(fd, buff, BUFF_SIZE)) >= 0)
	{
		if (ft_strlen(piece) == 0 && ret == 0)
			return (END_OF_FILE);
		if (ft_stickin(buff, line, &piece) == E_SUCCESS)
			return (E_SUCCESS);
		ft_bzero(*buff);
	}
	if (ret < 0)
		return (ERROR);
}
