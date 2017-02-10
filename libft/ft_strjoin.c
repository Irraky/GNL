/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:04:41 by drecours          #+#    #+#             */
/*   Updated: 2017/01/05 15:28:12 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		s3[i] = s1[i];
	while (++j <= ft_strlen(s2))
		s3[i + j] = s2[j];
	return (s3);
}
