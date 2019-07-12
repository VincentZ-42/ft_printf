/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:56:42 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/10 20:25:18 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*ans;

	i = 0;
	ans = b;
	while (len-- > 0)
		ans[i++] = (unsigned char)c;
	return (b);
}
