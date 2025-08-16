/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:16:12 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/23 15:16:12 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
/*#include <stdio.h>
void	ft_add_index(unsigned int i, char *c);
int main(void)
{
    printf("\nstriteri\n");
    char    test[] = "abcde";
    ft_striteri(test, ft_add_index);
    printf("%s\n", test);
}

void	ft_add_index(unsigned int i, char *c)
{
	*c += i;
}*/