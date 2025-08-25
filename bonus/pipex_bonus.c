/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:22:59 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/25 18:04:45 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex file1 cmd1 cmd2 cmd3 file2  ie. infile cat ./script.sh "grep why" outfile
int	main(int argc, char **argv, char **envp)
{
	t_fds				fds;
	t_execve_args		execve_args;
	pid_t				pid1;
	pid_t				pid2;
	int					status;

	if (argc < 5)
	{
		ft_putstr_fd("pipex : file1 cmd1 cmd2 [cmd3 ...] file2\n", 2);
		return (1);
	}

	int	cmds = argc - 3;

	prepare_pipex(&execve_args, &fds, argv, envp);

	pid1 = fork_and_exec(&fds, &execve_args, 1);
	pid2 = fork_and_exec(&fds, &execve_args, 2);


	close_fds(&fds);
	waitpid(pid1, NULL, 0);
	// wait for every kid ?
	waitpid(pid2, &status, 0);
	free_mem(&execve_args);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

void	prepare_pipex(t_execve_args *execve_args, 
		t_fds *fds, 
		char **argv, 
		char **envp)
{
	populate_structs(fds, execve_args, argv, envp);
	initialize_fds(fds);
	open_files(argv[1], argv[4], fds, execve_args);
	set_pipe(fds, execve_args);
}
