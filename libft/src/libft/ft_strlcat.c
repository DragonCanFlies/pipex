/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:52:18 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/23 15:22:12 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	space;

	dst_size = my_strlen(dst);
	src_size = my_strlen(src);
	if (dst_size >= size)
		return (size + src_size);
	while (*dst)
		dst++;
	space = size - dst_size - 1;
	while (*src && space--)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_size + src_size);
}

static size_t	my_strlen(const char *s)
{
	const char	*begin;

	begin = s;
	while (*s)
		s++;
	return (s - begin);
}
