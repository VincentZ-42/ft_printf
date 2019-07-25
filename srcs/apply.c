/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:57:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/24 18:55:49 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** unsigned short int and unsigned char will be promoted to unsigned int
** So, you do not have to consider length of h or hh
*/
llui		apply_length(int length, va_list ap)
{
	llui	data_type;
	
	if (length == h)
		data_type = (llui)va_arg(ap, unsigned short);
	else if (length == hh)
		data_type = (llui)va_arg(ap, unsigned char);
	else if (length == ll)
		data_type = va_arg(ap, long long unsigned int);
	else if (length == l)
		data_type = (llui)va_arg(ap, unsigned long int);
//	else if (length == j)
//		data_type = va_arg(ap, uintmax_t);
//	else if (length == z)
//		data_type = va_arg(ap, size_t);
	else
		data_type = (llui)va_arg(ap, unsigned int);
	return (data_type);
}

char	*apply_precision(char *print, t_var *info, llui input)
{
	int len;
	int prec;
	char *padding;
	char *temp;

	prec = info->precision;
	len = ft_strlen(print);
	len += (info->flag & hash && info->conv == 'o') ? 1: 0;
	if (prec == 0 && input == 0)
	{
		ft_strdel(&print);
		return (ft_strnew(1));
	}
	if (prec <= len)
	   return (print);
// This means prec > len.......
	prec -= len;
	padding = ft_memset(ft_strnew(prec), '0', prec);
	temp = ft_strjoin(padding, print);
	ft_strdel(&padding);
	ft_strdel(&print);
	print = temp;
	return (print);
}

char	*apply_flags(char *print, t_var *info, llui input, char *sign)
{
	char *c;
	char *temp;
	llui z;

	z = 0;
// These flags only apply to d, i, and f conversions
	if (info->conv == 'd' || info->conv == 'i' || info->conv =='f')
	{
		if (sign[0] == '-')
		{
			c = "-";
			temp = ft_strjoin(c, print);
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
	}
/*
**	# applies to  o, x, or X conversions 
*/
	if (info->conv == 'o' || info->conv == 'x' || info->conv == 'X')
	{
		if (info->flag & hash && input != 0)
		{
			if (info->conv == 'o')
				c = "0";
			else if (info->conv == 'x')
				c = "0x";
			else if (info->conv == 'X')
				c = "0X";
//			if ((info->conv == 'x' || info->conv == 'X') && input == 0)
//				return (print);
//			if (input == 0)
//				return (print);
			temp = ft_strjoin(c, print);
			ft_strdel(&print);
			print = temp;
		}
	}
	return (print);
}

char	*apply_width(char *print, t_var *info)
{
	char pad = ' ';
	int len;
	char *padding;
	char *temp;

	len = ft_strlen(print);
	if (info->width <= len)
		return (print);
// Assume width > len from here on....
	info->width -= len;
	padding = ft_memset(ft_strnew(info->width), pad, info->width);
	if (info->flag & minus)
	{
		temp = ft_strjoin(print, padding);
		ft_strdel(&print);
		print = temp;
	}
	else if (info->flag & zero)
	{	
		ft_strdel(&padding);
		padding = ft_memset(ft_strnew(info->width), '0', info->width);
		temp = ft_strjoin(padding, print);
		ft_strdel(&print);
		print = temp;
	}
	else
	{
		temp = ft_strjoin(padding, print);
		ft_strdel(&print);
		print = temp;
	}
	ft_strdel(&padding);
	return (print);
}
