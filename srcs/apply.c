/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:57:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/20 17:43:09 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long unsigned int		apply_length(int length, va_list ap)
{
	long long unsigned int	data_type;
	
	if (length == ll)
		data_type = va_arg(ap, long long unsigned int);
	else if (length == l)
		data_type = (long long unsigned int)va_arg(ap, unsigned long int);
/* unsigned short in and unsigned char can be held in int data type, and 
 * will be promoted to it.....which will give warning when compiling
 * Try using bit storage for holding the data correct, and then chopping ...
 * off any excess info you may receive. 
	else if (length == h)
		data_type = (long long unsigned int)va_arg(ap, unsigned short int);
	else if (length == hh)
		data_type = (long long unsigned int)va_arg(ap, unsigned char);
*/	else
		data_type = (long long unsigned int)va_arg(ap, unsigned int);
	return (data_type);
}

char	*apply_precision(char *print, int prec)
{
	int len;
	char *padding;
	char *temp;

	len = ft_strlen(print);
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

char	*apply_flags(char *print, t_var *info, llui input)
{
	char *c;
	char *temp;

// can have these two conditions because plus will erase space flag
/*	c = "\0";
	if (flag & plus)
		c = "+";
	if (flag & space)
		c = " ";
Above flags do not apply to u, o, x, or X conversions 
*/
	if ((info->flag & hash) && input != 0)
	{
		if (info->conv == 'o')
			c = "0";
		else if (info->conv == 'x')
			c = "0x";
		else if (info->conv == 'X')
			c = "0X";
		temp = ft_strjoin(c, print);
		ft_strdel(&print);
		print = temp;
	}
	return (print);
}

char	*apply_width(char *print, int width, int flag)
{
	char pad = ' ';
	int len;
	char *padding;
	char *temp;

	len = ft_strlen(print);
	if (width <= len)
		return (print);
// Assume width > len from here on....
	width -= len;
	padding = ft_memset(ft_strnew(width), pad, width);
	if (flag & minus)
	{
		temp = ft_strjoin(print, padding);
		ft_strdel(&print);
		print = temp;
	}
	else
	{
		if (flag & zero)
		{
			ft_strdel(&padding);
			padding = ft_memset(ft_strnew(width), '0', width);
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
	}
	ft_strdel(&padding);
	return (print);
}
