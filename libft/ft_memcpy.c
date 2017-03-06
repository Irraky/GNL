/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:36:14 by drecours          #+#    #+#             */
/*   Updated: 2016/12/05 11:23:59 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*sortie;
	char	*entree;

	entree = (char*)src;
	sortie = (char*)dest;
	i = -1;
	if (entree == sortie || n == 0)
		return (dest);
	while (++i != n)
		sortie[i] = entree[i];
	return (dest);
}
