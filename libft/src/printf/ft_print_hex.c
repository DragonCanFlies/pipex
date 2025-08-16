/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:44:01 by latabagl          #+#    #+#             */
/*   Updated: 2025/06/04 17:38:55 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char c)
{
	char	*str;
	int		count;

	count = 0;
	str = base10tohexa((unsigned long) n);
	if (!str)
		return (ft_printstr("0"));
	if (c == 'x')
		count = ft_printstr(str);
	else 
		count = ft_print_uppercase_str(str);
	free(str);
	return (count);
}
