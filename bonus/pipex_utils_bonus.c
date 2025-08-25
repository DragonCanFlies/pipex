/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:19:04 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/28 17:00:45 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*build_exec_path(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;
	char	*dest;

	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	result = (char *) malloc(len);
	if (!result)
		return (NULL);
	dest = result;
	while (*s1)
		*dest++ = *s1++;
	*dest++ = '/';
	while (*s2)
		*dest++ = *s2++;
	*dest = '\0';
	return (result);
}

void	free_mem(t_execve_args *execve_args)
{
	char	**paths_tmp;
	char	**argv_tmp;

	paths_tmp = execve_args->paths;
	argv_tmp = execve_args->argv;
	free(execve_args->pathname);
	if (execve_args->paths)
	{
		while (*paths_tmp)
			free(*paths_tmp++);
		free(execve_args->paths);
	}
	if (execve_args->argv)
	{
		while (*argv_tmp)
			free(*argv_tmp++);
		free(execve_args->argv);
	}
}
