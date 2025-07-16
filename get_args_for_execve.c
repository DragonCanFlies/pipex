/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_for_execve.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:22:15 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/16 17:34:32 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_execve_args(t_execve_args *execve_args, int cmd)
{
	char	*path_env_var;
	char	*pathname;
	int		n;

	if (cmd == 1)
		execve_args->argv = ft_split(execve_args->cmd1, ' ');
	else
		execve_args->argv = ft_split(execve_args->cmd2, ' ');
	path_env_var = get_path_env_var(execve_args);
	n = 5;
	while (n--)
	{
		path_env_var++;
	}
	execve_args->paths = ft_split(path_env_var, ':');
	pathname = find_pathname(execve_args); 
	if (!pathname)
	{
		exit (ERR_PATHNAME);
	}
	execve_args->pathname = pathname;
	
}
char	*find_pathname(t_execve_args *execve_args)
{	
	unsigned int	i;
	unsigned int	len_cmd;
	unsigned int	len_path;
	char			*pathname;

	i = 0;
	while (execve_args->paths[i])
	{
		pathname = ft_strjoinpath(execve_args->paths[i], execve_args->argv[0]);
		if (!pathname)
		{
			exit(ERR_MALLOC);
		}
		if (access(pathname, F_OK | X_OK) == 0)
		{
			return (pathname);
		} 
		free(pathname);
		i++;
	}
	return (NULL);
}

char	*get_path_env_var(t_execve_args *execve_args)
{
	int 	i;
	char	*path_env_var;
	
	i = 0;
	path_env_var = NULL;
	while (execve_args->envp[i])
	{
		if (is_path_env_var(execve_args->envp[i]))
		{
			path_env_var = execve_args->envp[i];
			break;
		}
		i++;
	}
	return (path_env_var);
}

int	is_path_env_var(char *env_var)
{
	if (*env_var++ == 'P' && 
		*env_var++ == 'A' && 
		*env_var++ == 'T' && 
		*env_var++ == 'H' && 
		*env_var == '=')
		return (1);
	return (0);
}