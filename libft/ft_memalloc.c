/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:08:46 by vzhao             #+#    #+#             */
/*   Updated: 2019/05/16 17:07:07 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *fresh;

	if (!(fresh = (void*)malloc(sizeof(void*) * size)))
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
