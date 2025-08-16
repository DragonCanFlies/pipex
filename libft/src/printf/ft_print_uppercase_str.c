/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uppercase_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:01:15 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/28 16:14:29 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uppercase_str(char *str)
{
	int	len;
	int	i;

	if (!str)
		return (ft_printstr("(null)"));
	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	write(1, str, len);
	return (len);
}
