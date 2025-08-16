/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:40:35 by latabagl          #+#    #+#             */
/*   Updated: 2025/06/17 17:11:34 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
int		add_buffer_to_stash(const char *buffer, char **stash);
size_t	ft_strlen(const char *s);
char	*extract_line(const char *stash);
int		is_newline(const char *stash);
void	clean_stash(char **stash, const char *line);
size_t	len_extracted_line(const char *stash);
void	copy_remaining_stash(const char *stash, char *new_stash, size_t index);
int		read_and_fill_stash(int fd, char **stash);
void	cpy_new_stash(char *new_stash, const char *stash, const char *buffer);

#endif
