/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:54:57 by drecours          #+#    #+#             */
/*   Updated: 2017/01/06 12:26:40 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*j;

	while (*alst)
	{
		j = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = j;
	}
	*alst = NULL;
}
