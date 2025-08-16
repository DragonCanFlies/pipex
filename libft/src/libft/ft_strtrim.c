/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:17:05 by latabagl          #+#    #+#             */
/*   Updated: 2025/05/23 15:17:05 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_char_in_set(char c, const char *set);
static size_t	my_strlen(const char *s);
static char		*empty_string(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*begin;
	char const	*end;
	char		*result;
	char		*result_begin;

	begin = s1;
	while (*begin && is_char_in_set(*begin, set))
		begin++;
	if (((unsigned long)(begin - s1)) == my_strlen(s1))
		return (empty_string());
	end = s1 + my_strlen(s1) - 1;
	while (is_char_in_set(*end, set))
		end--;
	result = (char *) malloc(end - begin + 2);
	if (!result)
		return (NULL);
	result_begin = result;
	while (begin <= end)
		*result++ = *begin++;
	*result = '\0';
	return (result_begin);
}

static int	is_char_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	my_strlen(const char *s)
{
	const char	*begin;

	begin = s;
	while (*s)
		s++;
	return (s - begin);
}

static char	*empty_string(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
/*#include <stdio.h>
int main(void)
{
	printf("! %s\n", ft_strtrim("---hello123", "-123")); // hello
    printf("! %s\n", ft_strtrim("-x-hello--a", "ax-")); //hello
    printf("! %s\n", ft_strtrim("---hello---", "")); //---hello---
    printf("! %s\n", ft_strtrim("------", "-")); //""
    printf("! %s\n", ft_strtrim("", "hgtre")); // ""
    printf("! %s\n", ft_strtrim("lavvla", "hgtre")); // lavvla
}*/
