/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:26:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 04:06:03 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Should make function print 8 bits at a time with space in between each byte?
** Do you need flags or precision????
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

int			print_color(char *str, int *index)
{
	int end_brac = 0;
	char *color;
	char *code;
	int len = 0;

	if (!ft_strchr(str, '}'))
		return (0);
	while (str[end_brac] != '}')
		end_brac++;
	color = ft_strsub(str, 0, ++end_brac);
	if (!ft_strcmp(color, "{red}"))
	{
		code = "\033[0;31m";
		*index += 4;
		len = 7; 
	}
	else if (!ft_strcmp(color, "{eoc}"))
	{
		code = "\033[0m";
		*index += 4;
		len = 4;
	}
	ft_putstr(code);
	ft_strdel(&color);
	return (len);
}
