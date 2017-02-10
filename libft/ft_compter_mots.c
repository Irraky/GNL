/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compter_mots.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:56:49 by drecours          #+#    #+#             */
/*   Updated: 2017/01/05 17:04:48 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compter_mots(char const *str, char c)
{
	int		i;
	int		mots;

	mots = 0;
	i = 0;
	if (str[i] != c)
		++mots;
	i++;
	while (str[i])
	{
		if (str[i - 1] == c)
			mots++;
		i++;
	}
	return (mots);
}
