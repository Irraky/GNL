/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:44:20 by drecours          #+#    #+#             */
/*   Updated: 2016/12/21 20:01:50 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		s2[u] = f(u, s[u]);
	return (s2);
}
