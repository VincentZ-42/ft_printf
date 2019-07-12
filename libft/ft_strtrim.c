/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:31:36 by vzhao             #+#    #+#             */
/*   Updated: 2019/05/20 15:26:45 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	int		start_fresh;
	int		end_fresh;
	int		j;

	if (!s)
		return (NULL);
	start_fresh = 0;
	end_fresh = ft_strlen(s) - 1;
	if (end_fresh < 1)
		return (ft_strdup(""));
	while (s[start_fresh] && ft_is_whitesp(s[start_fresh]) == 1)
		start_fresh++;
	while (end_fresh > 0 && ft_is_whitesp(s[end_fresh]) == 1)
		end_fresh--;
	if (end_fresh <= start_fresh)
		return (ft_strdup(""));
	if (!(fresh = (char*)malloc(sizeof(char) * (end_fresh - start_fresh) + 1)))
		return (NULL);
	j = 0;
	while (start_fresh <= end_fresh)
		fresh[j++] = s[start_fresh++];
	fresh[j] = '\0';
	return (fresh);
}
