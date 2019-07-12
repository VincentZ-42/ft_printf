/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:20:48 by vzhao             #+#    #+#             */
/*   Updated: 2019/05/22 18:48:43 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	size_t	fresh_len;
	int		i;
	int		elem;

	if (!s || !c)
		return (NULL);
	fresh_len = ft_countwords(s, c);
	if (!(fresh = (char**)malloc(sizeof(char*) * fresh_len + 1)))
		return (NULL);
	i = 0;
	elem = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		fresh[elem] = ft_storeword(((char*)s) + i, c);
		elem++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	fresh[elem] = NULL;
	return (fresh);
}
