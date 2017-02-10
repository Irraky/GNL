/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:17:37 by drecours          #+#    #+#             */
/*   Updated: 2017/01/06 16:00:49 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (len == 0)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[j + i] == little[j] || (little[j]) == '\0') && j + i < len)
		{
			if (little[++j] == '\0' || (little[j - 1] == big[i + j - 1] &&
						(i + j - 1) == len))
				return ((char *)&big[i]);
			if ((j + i) >= len)
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
