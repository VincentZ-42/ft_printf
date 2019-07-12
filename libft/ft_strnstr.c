/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:23:20 by vzhao             #+#    #+#             */
/*   Updated: 2019/05/22 18:57:45 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		if (needle[j] == haystack[i + j])
		{
			while (haystack[i + j] && needle[j] && \
				i + j < len && needle[j] == haystack[i + j])
				j++;
			if (needle[j] == '\0')
				return ((char*)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
