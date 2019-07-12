/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:41:09 by jiliu             #+#    #+#             */
/*   Updated: 2019/06/07 16:51:05 by jiliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freelist(t_list *head)
{
	t_list *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->shape);
		free(tmp);
	}
}
