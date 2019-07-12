/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:44:23 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/11 16:41:32 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			len;
	char			*fresh;

	nbr = (n < 0) ? n * -1 : n;
	len = ft_int_len(n);
	if (!(fresh = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	fresh[len--] = '\0';
	if (nbr == 0)
		fresh[0] = '0';
	else if (n < 0)
		fresh[0] = '-';
	while (nbr > 0)
	{
		fresh[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (fresh);
}
