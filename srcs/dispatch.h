/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:28:23 by vzhao             #+#    #+#             */
/*   Updated: 2019/07/29 02:16:15 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

# include "ft_printf.h"
# define TYPE_NUM 14

typedef int		(*t_funct)(t_var *info, va_list ap);

typedef struct	s_types
{
	char		type;
	t_funct		spec_funct;
}				t_types;

t_types		g_dispatch_table[] =
{
	{'%', mod_funct},
	{'c', c_funct},
	{'s', s_funct},
	{'p', p_funct},
	{'d', id_funct},
	{'i', id_funct},
	{'u', u_funct},
	{'o', o_funct},
	{'x', x_funct},
	{'X', bigx_funct},
	{'f', f_funct},
	{'b', b_funct},
	{'U', bigu_funct},
	{'O', bigo_funct}
};

#endif
