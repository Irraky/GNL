/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:41:16 by drecours          #+#    #+#             */
/*   Updated: 2017/01/06 15:10:35 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *deux;

	if (lst != NULL)
	{
		if (!(deux = (t_list*)malloc(sizeof(lst))))
			return (NULL);
		deux = f(lst);
		deux->next = ft_lstmap(lst->next, f);
		return (deux);
	}
	return (NULL);
}
