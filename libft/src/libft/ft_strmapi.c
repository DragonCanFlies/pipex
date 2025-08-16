/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:16:42 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/23 15:16:42 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			s_len;
	unsigned int	index;

	s_len = ft_strlen(s);
	str = malloc(s_len + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}

/*#include <stdio.h>
char	ft_add_index(unsigned int i, char c);
int main(void)
{
    printf("\nstrmapi\n");
    char    (*fct_pointer)(unsigned int, char);
    fct_pointer = ft_add_index;
    printf("%c\n", fct_pointer(1, 'a'));
    char    *test = "abcde"; // acegi
    printf("! %s\n", ft_strmapi(test, fct_pointer));
}

char	ft_add_index(unsigned int i, char c)
{
	return (c + i);
}*/