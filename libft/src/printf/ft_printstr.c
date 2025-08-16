/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:37:40 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/28 19:21:31 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *str)
{
	int	len;

	if (!str)
		return (ft_printstr("(null)"));
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
