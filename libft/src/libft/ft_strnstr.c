/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:36:50 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/23 15:16:56 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*big_search;
	const char	*little_search;
	size_t		len_search;

	if (!*little)
		return ((char *) big);
	while (*big && len)
	{
		if (*big == *little)
		{
			little_search = little;
			big_search = big;
			len_search = len;
			while (*big_search == *little_search && *big_search && len_search--)
			{
				big_search++;
				little_search++;
			}
			if (!*little_search)
				return ((char *) big);
		}
		big++;
		len--;
	}
	return (NULL);
}
