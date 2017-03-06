/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:56:26 by drecours          #+#    #+#             */
/*   Updated: 2016/12/16 11:08:59 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*un;
	char	*deux;

	deux = (char*)s2;
	un = (char*)s1;
	i = -1;
	while (++i < n)
		if (un[i] != deux[i])
			return ((unsigned char)un[i] - (unsigned char)deux[i]);
	return (0);
}
