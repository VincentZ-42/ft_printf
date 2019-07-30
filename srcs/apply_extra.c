/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:38:21 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 13:40:23 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_flags_sps(char *print, t_var *info, char *sign)
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

char	*zero_id(char *print, t_var *info, _LLI nbr, char *sign)
{
	if (nbr < 0 || info->flag & plus)
		info->width--;
	if (info->flag & space)
		info->width--;
	print = apply_width(print, info);
	print = apply_flags(print, info, sign);
	return (print);
}
