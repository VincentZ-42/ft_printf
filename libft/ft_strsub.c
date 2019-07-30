/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:13:51 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 04:06:06 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ans;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ans = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
		ans[i++] = s[start++];
	ans[i] = '\0';
	return (ans);
}
