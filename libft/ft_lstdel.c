/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:43:50 by vzhao             #+#    #+#             */
/*   Updated: 2019/06/07 14:39:45 by jiliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void **))
{
	t_list *temp;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		del((void*)(*alst)->shape);
		del((*alst)->content);
		free(*alst);
		*alst = temp;
	}
	*alst = NULL;
}
