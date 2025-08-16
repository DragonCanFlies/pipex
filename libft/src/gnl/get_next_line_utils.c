/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:35:15 by latabagl          #+#    #+#             */
/*   Updated: 2025/06/17 17:00:23 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*begin;

	begin = s;
	while (*s)
		s++;
	return (s - begin);
}

int	is_newline(const char *stash)
{
	if (!stash)
		return (0);
	while (*stash)
	{
		if (*stash == '\n')
			return (1);
		stash++;
	}
	return (0);
}

size_t	len_extracted_line(const char *stash)
{
	size_t	len;

	len = 0;
	while (stash[len])
	{
		if (stash[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	return (len);
}

void	copy_remaining_stash(const char *stash, char *new_stash, size_t index)
{
	while (stash[index])
	{
		*new_stash++ = stash[index];
		index++;
	}
	*new_stash = '\0';
}

void	clean_stash(char **stash, const char *line)
{
	char	*new_stash;
	size_t	len_extract;
	size_t	len_stash;

	len_extract = ft_strlen(line);
	len_stash = ft_strlen(*stash);
	new_stash = malloc(len_stash - len_extract + 1);
	if (!new_stash)
	{
		return ;
	}
	copy_remaining_stash(*stash, new_stash, len_extract);
	free(*stash);
	*stash = new_stash;
}
