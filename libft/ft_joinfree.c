/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:41:18 by drecours          #+#    #+#             */
/*   Updated: 2017/03/06 16:49:52 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char const *s1, char const *s2, int nb)
{
	size_t			size;
	size_t			i;
	size_t			j;
	char			*str;

	if (!s1)
	{
		str = ft_strdup(s2);
		return (str);
	}
	i = -1;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)ft_memalloc(sizeof(str) * size + 1)))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (nb == 1 || nb == 3)
		free((void*)s1);
	if (nb == 2 || nb == 3)
		free((void*)s2);
	return (str);
}
