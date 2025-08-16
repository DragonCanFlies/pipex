/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:07:17 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/23 15:17:00 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_begin;

	s_begin = s;
	while (*s) 
		s++;
	if ((unsigned char) c == *s)
		return ((char *) s);
	while (s >= s_begin)
	{
		if ((unsigned char) c == *s)
			return ((char *) s);
		s--;
	}
	return (NULL);
}
