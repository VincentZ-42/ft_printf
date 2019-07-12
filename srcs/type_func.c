/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:55:54 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/11 18:07:47 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//------------------------------------------------------------------------------
//Do not have to handle length for c conversion but I did...........
//---------------------------------------------------------------------------
int		c_funct(t_var *info, va_list ap)
{
	// wint_t is the same thing as..
	// ..wchar_t can store larger values depending on system.
	// ..gives access to extended character sets
	char	c;
	wchar_t wide_c;
	int size;
	
	// Possible error check here
	// ...
	// If (info->flag != minus || info->flag != 0) ERROR
	// If (info->precision) ERROR
	// ...
	// If this flag is on, then we have to adjust our char before printing width
	// Should make another function to skim these lines down........
	// new function ft_strnew_space(size_t len) ??
	if (info->flag == minus)
	{
		size = info->width;
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
		return ((info->width) ? info->width : 1);
	}
	else
	{
		size = info->width;
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
		return ((info->width) ? info->width : 1);
	}
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
	temp = (!string) ? "(null)" : ft_strsub(string, 0, len);
	len = ft_strlen(temp);
	width = (info->width > len) ? info->width - len : 0;
	padding = ft_memset(ft_strnew(width), ' ', width);
	printf("width = %d padding = %zu\n", width, ft_strlen(padding)); 
	if (info->flag == minus)
		string = ft_strjoin(temp, padding);
	else
		string = ft_strjoin(padding, temp);
	ft_putstr(string);
	len = ft_strlen(string);
	free(temp);
	free(padding);
	free(string);
	return (len);
}

//------------------------------------------------------------------------------
//Do not have to handle precision or length for p conversion .....
// memory addresses are stored in hexadecimal num, which can be stored in
// a long unsigned int data type
// All hexadecimal numbers start with "0x" to indicate it is hexadecimal #
//---------------------------------------------------------------------------

int		ft_int_len_base(long unsigned int nbr, int base)
{
	long unsigned int n;
	int len;

	len = (nbr <= 0) ? 1 : 0;
	n = (nbr < 0) ? nbr * -1 : nbr;
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	check_base(long unsigned int n, int base)
{
	char c;
	long unsigned int temp;

	temp = n % base;
	c = (temp < 10) ? temp + '0' : temp + 'a' - 10;
	return (c);
}

char	*ft_itoa_base(long unsigned int value, int base)
{
	char *ans;
	int len;
	long unsigned int n;

	len = ft_int_len_base(value, base);
	n = (base == 10 && value < 0) ? value * -1 : value;
	if (!(ans = (char*)malloc(sizeof(char) * len + 1)))
	   return (NULL);
	ans[len--] = '\0';
	if (value < 0 && base == 10)
		ans[0] = '-';
	if (n == 0)
		ans[0] = '0';
	while (n > 0)
	{
		ans[len--] = check_base(n, base);
		n /= base;
	}
	return (ans);
}

int		p_funct(t_var *info, va_list ap)
{
	long unsigned int address;
	char *temp;
	char *temp1;
	char *padding;
	int len;
	int width;

	len = 0;
	address = va_arg(ap, long unsigned int);
	temp = ft_itoa_base(address, 16);
	len = ft_strlen(temp) + 2;
	width = (info->width > len) ? info->width - len : 0;
	padding = ft_memset(ft_strnew(width), ' ', width);
	temp1 = ft_strjoin("0x", temp);
	ft_strdel(&temp);
	if (info->flag == minus)
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
