/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:55:54 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/24 18:55:47 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ------------------------------------------------------------------------------
** Do not have to handle length for c conversion but I did...........
** wint_t = wchar_t
** wchar_t can store larger values depending on system
** wchar_t gives accss to extended character sets
** ---------------------------------------------------------------------------
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
int		c_funct(t_var *info, va_list ap)
{
	char	c;
	wchar_t wide_c;
	int size;	

	size = info->width;
	if (info->flag & minus)
	{
		if (info->length == l)
		{
			wide_c = va_arg(ap, wchar_t);
			write(1, &wide_c, 1);
		}
		else
		{
			c = va_arg(ap, int);
			write(1, &c, 1);
		}
		if (size)
			while (--size)
				ft_putchar(' ');
	}
	else
	{
		if (size)
			while (--size)
				ft_putchar(' ');
		if (info->length == l)
		{
			wide_c = va_arg(ap, wchar_t);
			write(1, &wide_c, 1);
		}
		else
		{
			c = va_arg(ap, int);
			write(1, &c, 1);
		}
	}
	return ((info->width) ? info->width : 1);
}

//------------------------------------------------------------------------------
//Do not have to handle length for s conversion as stated in instructions...
//---------------------------------------------------------------------------
int		s_funct(t_var *info, va_list ap)
{
	char *string;
	char *padding;
	char *temp;
	int len;
	int width;

	string = va_arg(ap, char*);
	len = (!string) ? 6 : ft_strlen(string);
	len = (info->precision >= 0) ? info->precision : len;
	temp = (!string) ? ft_strdup("(null)") : ft_strsub(string, 0, len);
	len = ft_strlen(temp);
	width = (info->width > len) ? info->width - len : 0;
	padding = ft_memset(ft_strnew(width), ' ', width);
	if (info->flag & minus)
		string = ft_strjoin(temp, padding);
	else
		string = ft_strjoin(padding, temp);
	ft_putstr(string);
	len = ft_strlen(string);
	ft_strdel(&temp);
	ft_strdel(&padding);
	ft_strdel(&string);
	return (len);
}

/*
** ------------------------------------------------------------------------------
** // Do not have to handle precision or length for p conversion .....
** // memory addresses are stored in hexadecimal num, which can be stored in
** // a long unsigned int data type
** // All hexadecimal numbers start with "0x" to indicate it is hexadecimal #
** ---------------------------------------------------------------------------
*/
int		p_funct(t_var *info, va_list ap)
{
	llui address;
	char *temp;
	char *temp1;
	char *padding;
	int len;
	int width;

	address = va_arg(ap, long long unsigned int);
	temp = llui_itoa_base(address, 16, 'l');
	temp = apply_precision(temp, info, address);
	len = ft_strlen(temp) + 2;
	width = (info->width > len) ? info->width - len : 0;
	padding = ft_memset(ft_strnew(width), ' ', width);
	if (info->precision == 0)
	{
		ft_strdel(&temp);
		temp = ft_strnew(1);
	}
	temp1 = ft_strjoin("0x", temp);
	ft_strdel(&temp);
	if (info->flag & minus)
		temp = ft_strjoin(temp1, padding);
	else
		temp = ft_strjoin(padding, temp1);
	ft_strdel(&temp1);
	len = ft_strlen(temp);
	ft_putstr(temp);
	free(padding);
	free(temp);
	return (len);
}
//------------------------------------------------------------------------------
// i and d conversion (int data type) accepts all flags/widths/precision......
// Can handle mutiple flags......
// ............Special Cases.................
// 0 flag is ignored if precision exists.....
// flags: plus takes priority over space.....
// flags: minus takes priority over zero.....
//---------------------------------------------------------------------------

int		id_funct(t_var *info, va_list ap)
{
	int len;
	long long int nbr;
	llui input;
	char *sign;
	char *print;

//  short int and signed char data types will be promoted to int data type
//  when compling, warning will turn into error if -Werror option
	if (info->length == h)
		nbr = (long long int)va_arg(ap, short int);
	else if (info->length == hh)
		nbr = (long long int)va_arg(ap, signed char);
	else if (info->length == l)
		nbr = (long long int)va_arg(ap, long int);
	else if (info->length == ll)
		nbr = va_arg(ap, long long int);
	else
		nbr = (long long int)va_arg(ap, int);
//if input is negative, it will lose it after I put it through itoa
//len does not include negative
	sign = (nbr < 0) ? "-" : "+";
	input = (nbr < 0) ? (-1) * nbr : nbr;
//	printf("nbr = %lld\ninput = %lld\n", nbr, input);
	print = llui_itoa_base(input, 10, 'l');
	if (info->flag & minus)
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, input, sign);
		print = apply_width(print, info);
	}
	else if (info->flag & zero)
	{
		print = apply_precision(print, info, input);
		if (nbr < 0 || info->flag & plus)
			info->width--;
		if (info->flag & space)
			info->width--;
		print = apply_width(print, info);
		print = apply_flags(print, info, input, sign);
	}
	else
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, input, sign);
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}


// ------------------------------------------------------------------------------
// // u conversion: flags, lengths, width, are all the same as ^^^^^^^^^
// // '+' is concerned when specifier are 'd i f e E g G'
// // ' ' is concerned when specifier are 'd i f e E g G'
// ------------------------------------------------------------------------------
//

int		u_funct(t_var *info, va_list ap)
{
	llui input;
	char *print;
	int len;
	char *sign;

	sign = "+";
	input = apply_length(info->length, ap);
	print = llui_itoa_base(input, 10, 'l');

	if (info->flag & minus)
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, input, sign);
		print = apply_width(print, info);
	}
	else if (info->flag & zero)
	{
		print = apply_precision(print, info, input);
		print = apply_width(print, info);
		print = apply_flags(print, info, input, sign);
	}
	else
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, input, sign);
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}


// ------------------------------------------------------------------------------
// // o, x, X  conversions: flags, lengths, width, are all the same as ^^^^^^^^^
// ------------------------------------------------------------------------------

int		o_funct(t_var *info, va_list ap)
{
	llui input;
	char *print;
	int len;
	char *sign;

	sign = "+";
	input = apply_length(info->length, ap);
	print = llui_itoa_base(input, 8, 'l');
	if (info->flag & hash && info->precision <= 0)
		info->precision = 1;
//	if (info->flag & hash)
//		info->width -= 1;
	if (info->flag & zero)
	{
		print = apply_precision(print, info, input);
		print = apply_width(print, info);
		print = apply_flags(print, info, input, sign);
	}
	else
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, input, sign);
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}

int		x_funct(t_var *info, va_list ap)
{
	llui input;
	char *print;
	int len;
	char *sign;

	sign = "+";
	input = apply_length(info->length, ap);
	print = llui_itoa_base(input, 16, 'l');
	if (info->flag & zero)
	{
		if (info->flag & hash)
			info->width -= 2;
		print = apply_precision(print, info, input);
		print = apply_width(print, info);
		print = apply_flags(print, info, input, sign);
	}
	else
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, input, sign);
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}

int		X_funct(t_var *info, va_list ap)
{
	llui input;
	char *print;
	int len;
	char *sign;

	sign = "+";
	input = apply_length(info->length, ap);
	print = llui_itoa_base(input, 16, 'U');
	if (info->flag & zero)
	{
		if (info->flag & hash)
			info->width -= 2;
		print = apply_precision(print, info, input);
		print = apply_width(print, info);
		print = apply_flags(print, info, input, sign);
	}
	else
	{
		print = apply_precision(print, info, input);
		print = apply_flags(print, info, input, sign);
		print = apply_width(print, info);
	}
	len = ft_strlen(print);
	ft_putstr(print);
	ft_strdel(&print);
	return (len);
}

//------------------------------------------------------------------------------
// f conversion: Dealing with floating numbers (#s with decimal places)
// NEED TO FIND A WAY TO DEAL WITH 
//---------------------------------------------------------------------------

int		f_funct(t_var *info, va_list ap)
{
	long double input;
	int len;
	char *temp1;
	char *temp2;
	char *print;
	
	if (info->length == L)
		input = va_arg(ap, long double);
	else
		input = (long double)va_arg(ap, double);
// above handles length ^^^^^
	input = round_up(input, info->precision);
	temp1 = ld_itoa(input);
//ld_decimals may have trouble rounding when there are only 6 decimals...
	temp2 = ld_decimals(input, info->precision);
//	handles precision n round up based on precision ^^^
//	printf("\ntemp1 = %s\ntemp2 = %s\n", temp1, temp2);
	if (temp2 == NULL && info->flag & hash)
	{
		print = ft_strjoin(temp1, ".");
		ft_strdel(&temp1);
		temp1 = ft_strdup(print);
		ft_strdel(&print);
	}
	else if (temp2 == NULL)
		;
	else if (temp2)
	{
		print = ft_strjoin(temp1, ".");
		ft_strdel(&temp1);
		temp1 = ft_strjoin(print, temp2);
		ft_strdel(&print);
	}
//	printf("\ntemp1 = %s\ntemp2 = %s\n", temp1, temp2);
//	temp1 = the whole numbers + decimals
	print = f_add_s_flag_width(temp1, info, input);	
	ft_putstr(print);
	len = ft_strlen(print);
	ft_strdel(&print);
	ft_strdel(&temp1);
	ft_strdel(&temp2);
	return (len);
}

