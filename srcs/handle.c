/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:03:00 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/12 19:56:01 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_flags(t_var *info)
{
	if (info->flag & zero && info->flag & minus)
		info->flag -= zero;
	if (info->flag & space && info->flag & plus)
		info->flag -= space;
	if (info->flag & zero && info->precision >= 0)
		info->flag -= zero;
}
