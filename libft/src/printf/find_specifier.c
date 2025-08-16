/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:14:04 by latabagl          #+#    #+#             */
/*   Updated: 2025/06/04 17:25:50 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_specifier(char c, va_list args)
{
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == '%')
		return (ft_printchar('%'));
	else if (c == 's')
		return (ft_printstr(va_arg(args, const char *)));
	else if (c == 'p')
		return (ft_printaddress(va_arg(args, void *)));
	else if (c == 'i' || c == 'd')
		return (ft_printint(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	return (0);
}
