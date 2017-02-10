/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:48:07 by drecours          #+#    #+#             */
/*   Updated: 2016/12/23 15:17:24 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*entree;
	unsigned char		*sortie;

	entree = src;
	sortie = dest;
	i = -1;
	while (++i < n)
	{
		sortie[i] = entree[i];
		if (entree[i] == (unsigned char)c)
			return (sortie + i + 1);
	}
	return (NULL);
}
