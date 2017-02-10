/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:46:52 by drecours          #+#    #+#             */
/*   Updated: 2017/01/05 21:06:22 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	if (!str)
		return (NULL);
	i = ft_compter_mots(str, c);
	if (!i || !(tab = malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			tab[j] = ft_strsub(str, i, ft_taille(str, i, c));
			i = i + ft_taille(str, i, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
