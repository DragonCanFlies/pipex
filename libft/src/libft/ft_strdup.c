/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:40:44 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/20 17:40:44 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(const char *str);

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	char	*begin;

	len = my_strlen(s);
	dup = (char *) malloc(len + 1);
	if (!dup)
		return (NULL);
	begin = dup;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (begin);
}

static size_t	my_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}
