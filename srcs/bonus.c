/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:26:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 13:40:26 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** b_funct prints number in binary (base of 2)
*/

int			b_funct(t_var *info, va_list ap)
{
	LLUI	input;
	char	*print;
	int		len;

	input = apply_length(ll, ap);
	print = llui_itoa_base(input, 2, 'l');
	if (info->flag & zero)
	{
		print = apply_precision(print, info, input);
		print = apply_width(print, info);
		print = apply_flags(print, info, "+");
	}
	else
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, "+");
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}

/*
** U funct = %lu
** O funct = %lo
*/

int			bigu_funct(t_var *info, va_list ap)
{
	LLUI	input;
	char	*print;
	int		len;

	input = apply_length(l, ap);
	print = llui_itoa_base(input, 10, 'l');
	if (info->flag & zero)
	{
		print = apply_precision(print, info, input);
		print = apply_width(print, info);
		print = apply_flags(print, info, "+");
	}
	else
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, "+");
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}

int			bigo_funct(t_var *info, va_list ap)
{
	LLUI	input;
	char	*print;
	int		len;

	input = apply_length(l, ap);
	print = llui_itoa_base(input, 8, 'l');
	if (info->flag & hash && info->precision <= 0)
		info->precision = 1;
	if (info->flag & zero)
	{
		print = apply_precision(print, info, input);
		print = apply_width(print, info);
		print = apply_flags(print, info, "+");
	}
	else
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, "+");
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}
