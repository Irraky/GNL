/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:34:20 by drecours          #+#    #+#             */
/*   Updated: 2017/01/04 18:57:21 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len_dst;
	size_t		len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= size)
		return (len_src + size);
	dst = ft_strncat(dst, (char*)src, size - len_dst - 1);
	return (len_dst + len_src);
}
