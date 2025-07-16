/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:20:57 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/16 17:33:14 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	fork_and_exec(t_fds *fds, t_execve_args *execve_args, int cmd)
{
	pid_t pid;
	
	pid = fork();
	if (pid == -1)
	{
		printf("zsh4: %s\n", strerror(errno));
		exit (ERR_FORK);
	}
	else if (pid == 0)
	{
		if (cmd == 1)
		{
			redirect_first_cmd(fds);
			close_fds(fds);
			get_execve_args(execve_args, cmd);
			exec_first_cmd(execve_args);
		}
		else
		{
			redirect_second_cmd(fds);
			close_fds(fds);
			get_execve_args(execve_args, cmd);
			exec_second_cmd(execve_args);
		}					
	}
	return (pid);
}

void exec_first_cmd(t_execve_args *execve_args)
{
	execve(execve_args->pathname, execve_args->argv, execve_args->envp);
	printf("zsh5: %s\n", strerror(errno));
	exit (ERR_EXECVE);
}

void exec_second_cmd(t_execve_args *execve_args)
{
	execve(execve_args->pathname, execve_args->argv, execve_args->envp);
	printf("zsh6: %s\n", strerror(errno));
	exit(ERR_EXECVE);
}

// child read from file1 and write into pipe
void redirect_first_cmd(t_fds *fds)
{
	close(fds->pipe_fd[0]); 
	if (dup2(fds->infile, STDIN_FILENO) == -1)
	{
		printf("zsh7: %s\n", strerror(errno));
		exit (ERR_DUP);
	}
	if (dup2(fds->pipe_fd[1], STDOUT_FILENO) == -1)
	{
		printf("zsh8: %s\n", strerror(errno));
		exit (ERR_DUP);
	}
}

// parent read from reading pipe end and write to outfile
void redirect_second_cmd(t_fds *fds)
{
	close(fds->pipe_fd[1]); 
	if (dup2(fds->pipe_fd[0], STDIN_FILENO) == -1)
	{
		printf("zsh9: %s\n", strerror(errno));
		exit (ERR_DUP);
	}
	if (dup2(fds->outfile, STDOUT_FILENO) == -1)
	{
		printf("zsh10: %s\n", strerror(errno));
		exit (ERR_DUP);
	} 
}