/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:20:57 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/25 16:41:45 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	fork_and_exec(t_fds *fds, t_execve_args *execve_args, int cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		print_error(fds, ERR_GENERIC, execve_args);
	}
	else if (pid == 0)
	{
		if (cmd == 1)
			redirect_first_cmd(fds, execve_args);
		else
			redirect_second_cmd(fds, execve_args);
		close_fds(fds);
		get_execve_args(execve_args, cmd, fds);
		exec_cmd(execve_args, fds);
	}
	return (pid);
}

void	exec_cmd(t_execve_args *execve_args, t_fds *fds)
{
	execve(execve_args->pathname, execve_args->argv, execve_args->envp);
	if (access(execve_args->argv[0], F_OK) != 0)
		print_error(fds, ERR_CMD_NOT_FOUND, execve_args);
	else if (access(execve_args->argv[0], F_OK) == 0 && 
		access(execve_args->argv[0], X_OK) != 0)
		print_error(fds, ERR_PERMISSION, execve_args);
	else
		print_error(fds, ERR_GENERIC, execve_args);
}

// child read from file1 and write into pipe
void	redirect_first_cmd(t_fds *fds, t_execve_args *execve_args)
{
	close(fds->pipe_fd[0]);
	if (fds->infile == -1)
	{
		if (access(fds->filename, F_OK) == 0)
			print_error(fds, ERR_FILE_PERMISSION, execve_args);
		else
			print_error(fds, ERR_FILE_NOT_FOUND, execve_args);
	}
	if (dup2(fds->infile, STDIN_FILENO) == -1)
		print_error(fds, ERR_GENERIC, execve_args);
	if (dup2(fds->pipe_fd[1], STDOUT_FILENO) == -1)
		print_error(fds, ERR_GENERIC, execve_args);
}

// parent read from reading pipe end and write to outfile
void	redirect_second_cmd(t_fds *fds, t_execve_args *execve_args)
{
	close(fds->pipe_fd[1]); 
	if (dup2(fds->pipe_fd[0], STDIN_FILENO) == -1)
		print_error(fds, ERR_GENERIC, execve_args);
	if (dup2(fds->outfile, STDOUT_FILENO) == -1)
		print_error(fds, ERR_GENERIC, execve_args);
}
