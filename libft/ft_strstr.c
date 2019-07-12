/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:40:46 by vzhao             #+#    #+#             */
/*   Updated: 2019/05/22 19:40:36 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			while (haystack[i + j] && needle[j] && needle[j] == haystack[i + j])
				j++;
			if (needle[j] == '\0')
				return ((char*)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
