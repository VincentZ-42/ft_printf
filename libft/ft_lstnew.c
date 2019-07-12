/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:08:32 by vzhao             #+#    #+#             */
/*   Updated: 2019/06/07 15:21:22 by jiliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int *shape, char c)
{
	t_list *link;

	if (!(link = (struct s_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(link->shape = (int*)malloc(sizeof(int) * 4)))
	{
		free(link);
		return (NULL);
	}
	if (shape)
		ft_memcpy((void*)link->shape, (void*)shape, 16);
	link->index = c;
	link->used = 1;
	link->next = NULL;
	return (link);
}
