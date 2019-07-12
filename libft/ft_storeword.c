/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storeword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:57:11 by vzhao             #+#    #+#             */
/*   Updated: 2019/06/25 16:45:45 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_storeword(char const *s, char c)
{
	char	*ans;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	if (!(ans = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i] != c && s[i])
	{
		ans[i] = s[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
