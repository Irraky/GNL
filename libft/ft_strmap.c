/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:29:32 by drecours          #+#    #+#             */
/*   Updated: 2016/12/16 08:15:53 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;
	int		u;

	u = -1;
	if (!s || !f)
		return (NULL);
	if (!(s2 = ft_strdup(s)))
		return (NULL);
	i = ft_strlen(s2);
	while (++u < i)
		s2[u] = f(s[u]);
	return (s2);
}
