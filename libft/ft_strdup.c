/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:24:56 by drecours          #+#    #+#             */
/*   Updated: 2017/03/06 15:42:24 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*truc;

	i = -1;
	len = ft_strlen(s1);
	if (!(truc = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i++ != len)
		truc[i] = s1[i];
	truc[i] = '\0';
	return (truc);
}
