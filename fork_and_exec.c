/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:20:57 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/22 16:17:29 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	fork_and_exec(t_fds *fds, t_execve_args *execve_args, int cmd)
{
	pid_t pid;
	
	pid = fork();
	if (pid == -1)
	{
		print_error(fds);
	}
	else if (pid == 0)
	{
		if (cmd == 1)
			redirect_first_cmd(fds);
		else
			redirect_second_cmd(fds);	
		close_fds(fds);
		get_execve_args(execve_args, cmd, fds);
		exec_cmd(execve_args, fds);		
	}
	return (pid);
}

void exec_cmd(t_execve_args *execve_args, t_fds *fds)
{
	execve(execve_args->pathname, execve_args->argv, execve_args->envp);
	free_mem(execve_args);
	print_error(fds);	
}

// child read from file1 and write into pipe
void redirect_first_cmd(t_fds *fds)
{
	close(fds->pipe_fd[0]);
	if (fds->infile == -1)
	{
		if (access(fds->filename, F_OK) == 0)
			write(2, "pipex: permission denied: ", 26);
		else
			write(2, "pipex: no such file or directory: ", 34);
		write(2, fds->filename, ft_strlen(fds->filename));
		write(2, "\n", 1);
		close_fds(fds);
		exit(1);
	}
	if (dup2(fds->infile, STDIN_FILENO) == -1)
		print_error(fds);
	if (dup2(fds->pipe_fd[1], STDOUT_FILENO) == -1)
		print_error(fds);
}

// parent read from reading pipe end and write to outfile
void redirect_second_cmd(t_fds *fds)
{
	close(fds->pipe_fd[1]); 
	if (dup2(fds->pipe_fd[0], STDIN_FILENO) == -1)
		print_error(fds);
	if (dup2(fds->outfile, STDOUT_FILENO) == -1)
		print_error(fds); 
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
