/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:15:10 by drecours          #+#    #+#             */
/*   Updated: 2017/02/10 15:42:33 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char *buff[BUFF_SIZE + 1];
	char	*tmp;
	int	flag;
	
	if (fd < 0 || !line)
		return (ERROR);
	while (flag)
	{
		strcpy line -> tmp
		ft_bzero(buff);
		je lis fd dans le buff 
		je fou les trucs d'erreur
		si 0 caract dedans
			return (END_OF_FILE);
		je cherche un \n (incrementation variable i)
		line = memalloc taille de line = i = 1
		strcpy tmp -> line 
			strcmp de buff jusqu au \n a la fin de line
	}
	return (E_SUCCESS);
}
