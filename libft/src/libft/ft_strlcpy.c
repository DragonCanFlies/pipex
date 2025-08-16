/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:49:38 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/23 18:36:04 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	const char	*src_begin;
	size_t		src_size;
	size_t		i;

	src_begin = src;
	while (*src)
		src++;
	src_size = src - src_begin;
	if (dest_size == 0)
		return (src_size);
	src = src_begin;
	i = 0;
	while (*src && i < dest_size - 1)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (src_size);
}
