/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_uoxXmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:16:32 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 01:58:59 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ---------------------------------------------------------------
** u conversion:
** '+' is concerned when specifier are 'd i f e E g G'
** ' ' is concerned when specifier are 'd i f e E g G'
** ---------------------------------------------------------------
*/

int			u_funct(t_var *info, va_list ap)
{
	LLUI	input;
	char	*print;
	int		len;

	input = apply_length(info->length, ap);
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

/*
** ---------------------------------------------------------------
** o, x, X  conversions:
** ---------------------------------------------------------------
*/

int			o_funct(t_var *info, va_list ap)
{
	LLUI	input;
	char	*print;
	int		len;

	input = apply_length(info->length, ap);
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

int			x_funct(t_var *info, va_list ap)
{
	LLUI	input;
	char	*print;
	int		len;

	input = apply_length(info->length, ap);
	print = llui_itoa_base(input, 16, 'l');
	if (info->flag & zero)
	{
		if (info->flag & hash && input != 0)
			info->width -= 2;
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

int			bigx_funct(t_var *info, va_list ap)
{
	LLUI	input;
	char	*print;
	int		len;

	input = apply_length(info->length, ap);
	print = llui_itoa_base(input, 16, 'U');
	if (info->flag & zero)
	{
		if (info->flag & hash && input != 0)
			info->width -= 2;
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

int			mod_funct(t_var *info, va_list ap)
{
	int		len;
	char	*print;

	if (ap)
		;
	print = ft_strdup("%");
	print = apply_width(print, info);
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}
