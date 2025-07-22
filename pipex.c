/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:22:59 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/22 14:28:29 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex file1 cmd1 cmd2 file2  infile cat "wc -l" outfile
int	main(int argc, char **argv, char **envp)
{
	t_fds				fds;
	t_execve_args		execve_args;
	pid_t				pid1;
	pid_t				pid2;
	int					status;

	if (argc != 5)
	{
		write(2, "pipex must take 4 arguments: file1 cmd1 cmd2 file2\n", 52);
		return (1);
	}
	populate_structs(&fds, &execve_args, argv, envp);
	initialize_fds(&fds);
	open_files(argv[1], argv[4], &fds);
	set_pipe(&fds);
	pid1 = fork_and_exec(&fds, &execve_args, 1);
	pid2 = fork_and_exec(&fds, &execve_args, 2);
	close_fds(&fds);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	free_mem(&execve_args);
	return (1);
}

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

/* 
void	print_fds(t_fds *fds)
{
	printf("infile %i\n", fds->infile);
	printf("outfile %i\n", fds->outfile);
	printf("pipe reading end %i\n", fds->pipe_fd[0]);
	printf("pipe writing end %i\n", fds->pipe_fd[1]);
} */
