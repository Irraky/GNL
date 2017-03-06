/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:16:02 by drecours          #+#    #+#             */
/*   Updated: 2016/12/23 10:43:44 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*copie;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == '\t' || s[j] == ' ' || s[j] == '\n') && i < j)
		j--;
	if (!(copie = (char *)malloc(j - i + 2)))
		return (NULL);
	k = -1;
	while (++k <= j - i)
		copie[k] = s[i + k];
	copie[k] = '\0';
	return (copie);
}
