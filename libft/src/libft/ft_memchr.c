/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:28:16 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/23 15:15:05 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*scanner;

	scanner = s;
	while (n--)
	{
		if (*scanner == (unsigned char) c)
			return ((void *) scanner);
		scanner++;
	}
	return (NULL);
}
