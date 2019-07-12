/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:31:47 by vzhao             #+#    #+#             */
/*   Updated: 2019/05/31 14:27:42 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	i = 0;
	if (n <= 0 || dst == src)
		return (dst);
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	while (n-- > 0)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
