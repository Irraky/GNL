/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:14:54 by drecours          #+#    #+#             */
/*   Updated: 2017/03/06 19:41:58 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE 1
# define E_SUCCESS 1
# define END_OF_FILE 0
# define ERROR -1

# define END_OF_LINE 0
# define IN_LINE 1

int		get_next_line(const int fd, char **line);

#endif
