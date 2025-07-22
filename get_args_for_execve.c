/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_for_execve.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:22:15 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/22 16:20:26 by latabagl         ###   ########.fr       */
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
	path_env_var = get_path_env_var(execve_args); 
	execve_args->paths = ft_split(path_env_var, ':');
	if (!execve_args->argv || !execve_args->paths)
	{
		free_mem(execve_args);
		print_error(fds);
	} 
	pathname = find_pathname(execve_args, fds); 
	execve_args->pathname = pathname;
}	

char	*find_pathname(t_execve_args *execve_args, t_fds *fds)
{	
	unsigned int	i;
	char			*pathname;

	i = 0;
	while (execve_args->paths[i])
	{
		pathname = build_exec_path(execve_args->paths[i], execve_args->argv[0]); 
		if (!pathname)
		{
			free_mem(execve_args);
			print_error(fds);
		}
		if (access(pathname, F_OK) == 0 && access(pathname, X_OK) != 0)
		{
			free_mem(execve_args);
			ft_putstr_fd("pipex: permission denied: ", 2);
			ft_putstr_fd(execve_args->argv[0], 2);
			ft_putstr_fd("\n", 2);
			exit (126);
		}
		if (access(pathname, F_OK | X_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	free_mem(execve_args);
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(execve_args->argv[0], 2);
	ft_putstr_fd("\n", 2);
	exit (127);
}

char	*get_path_env_var(t_execve_args *execve_args)
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
	free_mem(execve_args);
	write(2, "pipex: PATH not set\n", 21);
    exit(127);
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

void	print_error(t_fds *fds)
{
	perror("pipex");
	close_fds(fds);
	exit(1);
}