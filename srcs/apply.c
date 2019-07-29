/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:57:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 03:13:36 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** unsigned short int and unsigned char will be promoted to unsigned int
** So, you do not have to consider length of h or hh
**-------for id conversion--------
** h = short int (2 bytes)
** hh = signed char (1 byte)
** have to recast because value in the first bit holds the sign
**-------for unsigned conv-------
** h = unsigned short (2 bytes)
** hh = unsigned char (1 bytes)
** 0xff = 1 byte (11111111)
** 0xffff = 2 bytes (1111111111111111)
*/

_LLI		id_apply_length(int length, va_list ap)
{
	_LLI data;

	if (length == h)
		data = (short int)(0xffff & va_arg(ap, int));
	else if (length == hh)
		data = (signed char)(0xff & va_arg(ap, int));
	else if (length == l)
		data = (long long int)va_arg(ap, long int);
	else if (length == ll)
		data = va_arg(ap, long long int);
	else
		data = (long long int)va_arg(ap, int);
	return (data);
}

LLUI		apply_length(int length, va_list ap)
{
	LLUI	data_type;

	if (length == h)
		data_type = (0xffff & va_arg(ap, unsigned int));
	else if (length == hh)
		data_type = (0xff & va_arg(ap, unsigned int));
	else if (length == ll)
		data_type = va_arg(ap, long long unsigned int);
	else if (length == l)
		data_type = (LLUI)va_arg(ap, unsigned long int);
	else if (length == j)
		data_type = va_arg(ap, uintmax_t);
	else if (length == z)
		data_type = va_arg(ap, size_t);
	else
		data_type = (LLUI)va_arg(ap, unsigned int);
	return (data_type);
}

char		*apply_precision(char *print, t_var *info, LLUI input)
{
	int		len;
	int		prec;
	char	*padding;
	char	*temp;

	prec = info->precision;
	len = ft_strlen(print);
	len += (info->flag & hash && info->conv == 'o') ? 1 : 0;
	if (prec == 0 && input == 0)
	{
		ft_strdel(&print);
		return (ft_strnew(1));
	}
	if (prec <= len)
		return (print);
	prec -= len;
	padding = ft_memset(ft_strnew(prec), '0', prec);
	temp = ft_strjoin(padding, print);
	ft_strdel(&padding);
	ft_strdel(&print);
	print = temp;
	return (print);
}

/*
** -------------------------------------------------------------------------
** for dif conv, sign will always be applied if # is negative
** for oxX conv, ft_strcmp(print, "0") will only return false if input == 0;
** for oxX conv, if print == NULL, then we do not apply hash flag
** -------------------------------------------------------------------------
*/

char		*apply_flags(char *print, t_var *info, char *sign)
{
	char	*c;
	char	*temp;

	if (info->conv == 'd' || info->conv == 'i' || info->conv == 'f')
		print = apply_flags_sps(print, info, sign);
	if (info->conv == 'o' || info->conv == 'x' || info->conv == 'X')
	{
		if (info->flag & hash && ft_strcmp(print, "0"))
		{
			if (info->conv == 'o')
				c = "0";
			else if (info->conv == 'x')
				c = "0x";
			else if (info->conv == 'X')
				c = "0X";
			if ((info->conv == 'x' || info->conv == 'X') && !*print)
				return (print);
			temp = ft_strjoin(c, print);
			ft_strdel(&print);
			print = temp;
		}
	}
	return (print);
}

char		*apply_width(char *print, t_var *info)
{
	int		len;
	char	*padding;
	char	*temp;

	len = ft_strlen(print);
	if (info->width <= len)
		return (print);
	info->width -= len;
	padding = ft_memset(ft_strnew(info->width), ' ', info->width);
	if (info->flag & minus)
		temp = ft_strjoin(print, padding);
	else if (info->flag & zero)
	{
		ft_strdel(&padding);
		padding = ft_memset(ft_strnew(info->width), '0', info->width);
		temp = ft_strjoin(padding, print);
	}
	else
		temp = ft_strjoin(padding, print);
	ft_strdel(&print);
	ft_strdel(&padding);
	print = temp;
	return (print);
}
