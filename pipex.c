/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:22:59 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/16 16:24:44 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex file1 cmd1 cmd2 file2  infile cat "wc -l" outfile
int	main(int argc, char **argv, char **envp)
{
	t_fds			fds;
	t_execve_args	execve_args;
	pid_t				pid1;
	pid_t				pid2;

	// for (int i = 0; envp[i]; i++)
	// 	printf("%s\n", envp[i]);
	// char	*str = "PATH=/home/latabagl/bin:/home/latabagl/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	// char	**paths = ft_split(str, ':');
	// for (int j = 0; paths[j]; j++)
	// 	printf("%s\n", paths[j]);
	if (argc < 5)
	{
		printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	//printf("1\n");
	execve_args.envp = envp; 
	execve_args.cmd1 = argv[2];
	execve_args.cmd2 = argv[3];
	
	initialize_fds(&fds);
	//printf("2\n");
	open_files(argv[1], argv[4], &fds);
	//printf("3\n");
	set_pipe(&fds);
	//printf("4\n");
	pid1 = fork_and_exec(&fds, &execve_args, 1);
	//printf("5\n");
	waitpid(pid1, NULL, 0);
	// wait(wstatus);
	// if (*wstatus != 0) // not how to handle wstatus
	// {
	// 	close_fds(&fds);
	// 	return (1);
	// }
	pid2 = fork_and_exec(&fds, &execve_args, 2);
	//printf("6\n");
	//waitpid(pid2, NULL, 0);
	//printf("7\n");
	close_fds(&fds);
	return (0);
}

// to be commented out 
void	print_fds(t_fds *fds)
{
	printf("infile %i\n", fds->infile);
	printf("outfile %i\n", fds->outfile);
	printf("pipe reading end %i\n", fds->pipe_fd[0]);
	printf("pipe writing end %i\n", fds->pipe_fd[1]);
}

// to be destroyed
char	*ft_strjoinpath(char const *s1, char const *s2)
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
