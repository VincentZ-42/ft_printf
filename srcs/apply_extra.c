/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:38:21 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/26 11:51:32 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_sign_plus_space(char *print, t_var *info, char *sign)
{
	char *c;
	char *temp;

	if (sign[0] == '-')
	{
		temp = ft_strjoin(sign, print);
		ft_strdel(&print);
		print = temp;
	}
	else if (info->flag & plus || info->flag & space)
	{
		if (info->flag & plus)
			c = sign;
		else if (info->flag & space)
			c = " ";
		temp = ft_strjoin(c, print);
		ft_strdel(&print);
		print = temp;
	}
	return (print);
}
