/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:52:47 by drecours          #+#    #+#             */
/*   Updated: 2016/12/21 20:48:08 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	char	*troncon;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(troncon = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (++i < size)
		troncon[i] = s[start + i];
	troncon[i] = '\0';
	return (troncon);
}
