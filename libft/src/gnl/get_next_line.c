/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:45:34 by latabagl          #+#    #+#             */
/*   Updated: 2025/06/17 17:08:34 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	ssize_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_and_fill_stash(fd, &stash);
	if (bytes_read < 0 || !stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	clean_stash(&stash, line);
	return (line);
}

int	read_and_fill_stash(int fd, char **stash)
{
	ssize_t			bytes_read;
	char			*buffer;
	int				success;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (!is_newline(*stash) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		success = add_buffer_to_stash(buffer, stash);
		if (!success)
		{
			bytes_read = -1;
			break ;
		}
	}
	free(buffer);
	return (bytes_read);
}

int	add_buffer_to_stash(const char *buffer, char **stash)
{
	size_t	stash_len;
	char	*new_stash;

	stash_len = ft_strlen(buffer) + 1;
	if (*stash)
		stash_len += ft_strlen(*stash);
	new_stash = malloc(stash_len);
	if (!new_stash)
		return (0);
	cpy_new_stash(new_stash, *stash, buffer);
	free(*stash);
	*stash = new_stash;
	return (1);
}

void	cpy_new_stash(char *new_stash, const char *stash, const char *buffer)
{
	while (stash && *stash)
		*new_stash++ = *stash++;
	while (*buffer)
		*new_stash++ = *buffer++;
	*new_stash = '\0';
}

char	*extract_line(const char *stash)
{
	char	*line;
	char	*line_begin;
	size_t	len;

	len = len_extracted_line(stash);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line_begin = line;
	while (len--)
	{
		*line++ = *stash++;
	}
	*line = '\0';
	return (line_begin);
}
