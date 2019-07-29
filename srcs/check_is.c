/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:38:08 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 02:11:13 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

int		is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
		return (1);
	return (0);
}

int		is_type(char c)
{
	if (c == '%')
		return (1);
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	if (c == 'b' || c == 'U' || c == 'O')
		return (1);
	return (0);
}
