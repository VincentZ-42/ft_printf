/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdif_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:11:22 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 13:09:48 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -------------------------------------------------------------
** Do not have to handle length for c conversion but I did......
** wint_t = wchar_t
** wchar_t can store larger values depending on system
** wchar_t gives accss to extended character sets
** -------------------------------------------------------------
*/

/*
** Possible error check here
**
**	// If (info->flag != minus || info->flag != 0) ERROR
**	// If (info->precision) ERROR
**	// ...
**	// If this flag is on, then we have to adjust our char before printing width
**	// Should make another function to skim these lines down........
**	// new function ft_strnew_space(size_t len) ??
*/

int			c_funct(t_var *info, va_list ap)
{
	char	c;
	wchar_t	wide_c;
	int		size;

	size = info->width;
	if (info->length == l)
		wide_c = va_arg(ap, wchar_t);
	else
		c = va_arg(ap, int);
	if (info->flag & minus)
	{
		(info->length == l) ? write(1, &wide_c, 1) : write(1, &c, 1);
		if (size)
			while (--size)
				ft_putchar(' ');
	}
	else
	{
		if (size)
			while (--size)
				ft_putchar(' ');
		(info->length == l) ? write(1, &wide_c, 1) : write(1, &c, 1);
	}
	return ((info->width) ? info->width : 1);
}

/*
** -------------------------------------------------------------
** Do not have to handle length for s conversion...
** -------------------------------------------------------------
*/

int			s_funct(t_var *info, va_list ap)
{
	char	*string;
	char	*print;
	char	*temp;
	int		len;

	string = va_arg(ap, char*);
	len = (!string) ? 6 : ft_strlen(string);
	len = (info->precision >= 0) ? info->precision : len;
	temp = (!string) ? ft_strdup("(null)") : ft_strsub(string, 0, len);
	print = (info->precision >= 0) ? ft_strsub(temp, 0, len) : ft_strdup(temp);
	print = apply_width(print, info);
	ft_putstr(print);
	len = ft_strlen(print);
	ft_strdel(&print);
	ft_strdel(&temp);
	return (len);
}

/*
** -------------------------------------------------------------------
** Do not have to handle precision/length for p conversion .....
** memory addresses are stored in hexadecimal num, which can be stored in
** a long unsigned int data type
** All hexadecimal numbers start with "0x" to indicate it is hexadecimal #
** ---------------------------------------------------------------------
*/

int			p_funct(t_var *info, va_list ap)
{
	LLUI	address;
	char	*temp;
	char	*temp1;
	int		len;

	address = va_arg(ap, long long unsigned int);
	temp = llui_itoa_base(address, 16, 'l');
	temp = apply_precision(temp, info, address);
	temp1 = ft_strjoin("0x", temp);
	ft_strdel(&temp);
	temp = apply_width(temp1, info);
	len = ft_strlen(temp);
	ft_putstr(temp);
	free(temp);
	return (len);
}

/*
** -----------------------------------------------------------------------
** i and d conversion (int data type) accepts all flags/widths/precision......
** Can handle mutiple flags......
** ............Special Cases.................
** 0 flag is ignored if precision exists.....
** flags: plus takes priority over space.....
** flags: minus takes priority over zero.....
** -----------------------------------------------------------------------
*/

/*
** short int and signed char data types will be promoted to int data type
** when compling, warning will turn into error if -Werror option
**
** if input is negative, it will lose it after I put it through itoa
** len does not include negative
*/

int			id_funct(t_var *info, va_list ap)
{
	int		len;
	_LLI	nbr;
	LLUI	input;
	char	*sign;
	char	*print;

	nbr = id_apply_length(info->length, ap);
	sign = (nbr < 0) ? "-" : "+";
	input = (nbr < 0) ? (-1) * nbr : nbr;
	print = llui_itoa_base(input, 10, 'l');
	print = apply_precision(print, info, input);
	if (info->flag & zero)
		print = zero_id(print, info, nbr, sign);
	else
	{
		print = apply_flags(print, info, sign);
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}

/*
** ----------------------------------------------------------------
** f conversion: Dealing with floating numbers (#s with decimal places)
** rounds up the decimal value based on precision
** temp1 will hold the whole #s
** temp2 will hold the dec #s
** then combine both whole #s n dec #s into a string to apply width n flags
** ----------------------------------------------------------------
*/

int			f_funct(t_var *info, va_list ap)
{
	__LD	input;
	int		len;
	char	*print;
	char	*sign;

	input = (info->length == L) ? va_arg(ap, __LD) : (__LD)va_arg(ap, double);
	input = round_up(input, info);
	sign = (input < 0) ? "-" : "+";
	print = get_f_number(input, info);
	if (info->flag & zero)
	{
		print = apply_width(print, info);
		print = apply_flags(print, info, sign);
	}
	else
	{
		print = apply_flags(print, info, sign);
		print = apply_width(print, info);
	}
	ft_putstr(print);
	len = ft_strlen(print);
	ft_strdel(&print);
	return (len);
}
