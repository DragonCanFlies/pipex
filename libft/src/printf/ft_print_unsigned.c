/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:49:17 by latabagl          #+#    #+#             */
/*   Updated: 2025/06/04 17:15:10 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_count(unsigned int n);
static void	print_unsigned(unsigned int n);

int	ft_print_unsigned(unsigned int n)
{
	int		count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = get_count(n);
	print_unsigned(n);
	return (count);
}

static int	get_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	print_unsigned(unsigned int n)
{
	char	digit;

	if (n >= 10)
		print_unsigned(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}
