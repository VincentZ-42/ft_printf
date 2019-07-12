/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:28:23 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/11 18:07:51 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

# include "ft_printf.h"
# define  TYPE_NUM 3

typedef int (*type_funct)(t_var *info, va_list ap);

typedef struct	s_types
{
	char		type;
	type_funct	spec_funct;
}				t_types;

t_types		dispatch_table[] =
{
			{'c', c_funct},
			{'s', s_funct},
			{'p', p_funct}
};

#endif 
