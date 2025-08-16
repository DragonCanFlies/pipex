/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_for_execve.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:22:15 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/28 17:09:17 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_execve_args(t_execve_args *execve_args, int cmd, t_fds *fds)
{
	char	*path_env_var;
	char	*pathname;

	if (cmd == 1)
		execve_args->argv = ft_split(execve_args->cmd1, ' ');
	else
		execve_args->argv = ft_split(execve_args->cmd2, ' '); 
	path_env_var = get_path_env_var(execve_args, fds); 
	execve_args->paths = ft_split(path_env_var, ':');
	if (!execve_args->argv || !execve_args->paths)
		print_error(fds, ERR_GENERIC, execve_args);
	pathname = find_pathname(execve_args, fds); 
	execve_args->pathname = pathname;
}	

char	*find_pathname(t_execve_args *execve_args, t_fds *fds)
{	
	unsigned int	i;
	char			*pathname;

	i = 0;
	if (!execve_args->argv[0] || execve_args->argv[0][0] == '\0')
		print_error(fds, ERR_CMD_NOT_FOUND, execve_args);
	while (execve_args->paths[i])
	{
		pathname = build_exec_path(execve_args->paths[i], execve_args->argv[0]); 
		if (!pathname)
			print_error(fds, ERR_GENERIC, execve_args);
		if (access(pathname, F_OK) == 0 && access(pathname, X_OK) != 0)
			print_error(fds, ERR_PERMISSION, execve_args);
		if (access(pathname, F_OK | X_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	print_error(fds, ERR_CMD_NOT_FOUND, execve_args);
	return (NULL);
}

char	*get_path_env_var(t_execve_args *execve_args, t_fds *fds)
{
	int 	i;
	
	i = 0;
	while (execve_args->envp[i])
	{
		if (is_path_env_var(execve_args->envp[i]))
		{
			return (execve_args->envp[i] + 5);
		}
		i++;
	}
	print_error(fds, ERR_CMD_NOT_FOUND, execve_args);
	return (NULL);
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

