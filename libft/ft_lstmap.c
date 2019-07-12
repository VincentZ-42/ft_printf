/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:06:42 by vzhao             #+#    #+#             */
/*   Updated: 2019/05/16 17:43:05 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *start;
	t_list *curr;

	if (!lst || !f)
		return (NULL);
	if (!(start = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	start = f(lst);
	lst = lst->next;
	curr = start;
	while (lst)
	{
		if (!(tmp = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		tmp = f(lst);
		curr->next = tmp;
		curr = curr->next;
		lst = lst->next;
	}
	return (start);
}
