/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:06:57 by drecours          #+#    #+#             */
/*   Updated: 2016/12/16 05:11:19 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	c1;

	i = -1;
	c1 = (char)c;
	str = (char *)s;
	while (++i < n)
		if (str[i] == c1)
			return (str + i);
	return (NULL);
}
