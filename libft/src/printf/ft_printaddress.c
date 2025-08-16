/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:53:16 by latabagl          #+#    #+#             */
/*   Updated: 2025/06/04 17:24:47 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddress(void *ptr)
{
	char	*adress;
	int		count;

	if (!ptr)
		return (ft_printstr("(nil)"));
	adress = base10tohexa((unsigned long) ptr);
	if (!adress)
		return (0); 
	write(1, "0x", 2);
	count = ft_printstr(adress) + 2;
	free(adress);
	return (count);
}
