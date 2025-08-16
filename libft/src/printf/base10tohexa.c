/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base10tohexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:53:02 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/28 18:21:42 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	how_many_digits(unsigned long n);

char	*base10tohexa(unsigned long n)
{
	char	*hexa_digits;
	char	*res;
	size_t	len;
	size_t	i;

	hexa_digits = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	len = how_many_digits(n) + 1;
	res = malloc(len);
	if (!res)
		return (NULL);
	i = len - 1;
	res[i--] = '\0';
	while (n)
	{
		res[i] = hexa_digits[n % 16];
		i--;
		n = n / 16;
	}
	return (res);
}

static size_t	how_many_digits(unsigned long n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}
