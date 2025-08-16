/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:57:26 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/26 14:45:58 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_byte;
	const unsigned char	*src_byte;

	dest_byte = dest;
	src_byte = src;
	if (dest < src || dest >= src + n)
	{
		while (n > 0)
		{
			n--;
			*dest_byte++ = *src_byte++;
		}
	}
	else 
	{
		while (n > 0)
		{
			n--;
			*(dest_byte + n) = *(src_byte + n);
		}
	}
	return (dest);
}
