/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:05:58 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/22 16:23:40 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

// # define ERR_INFILE 2
// # define ERR_OUTFILE 2
// # define ERR_FORK 3
// # define ERR_PIPE 4
// # define ERR_EXECVE 5
// # define ERR_DUP 6
// #define ERR_PATHNAME 7
// #define ERR_MALLOC 8

typedef struct s_fds
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	char	*filename;
}				t_fds;

typedef struct s_execve_args
{
	char	**paths;
	char	*pathname;
	char	**argv;
	char	**envp;
	char	*cmd1;
	char	*cmd2;
}				t_execve_args;

void	initialize_fds(t_fds *fds);
void	print_fds(t_fds *fds);
void	close_fds(t_fds *fds);
void	open_files(const char *file1, const char *file2, t_fds *fds);
void	set_pipe(t_fds *fds);
pid_t	fork_and_exec(t_fds *fds, t_execve_args *execve_args, int cmd);
void 	exec_cmd(t_execve_args *execve_args, t_fds *fds);
void	redirect_first_cmd(t_fds *fds);
void	redirect_second_cmd(t_fds *fds);
char	**ft_split(char const *s, char c); // destroy
char	*get_path_env_var(t_execve_args *execve_args);
void	get_execve_args(t_execve_args *execve_args, int cmd, t_fds *fds);
int		is_path_env_var(char *env_var);
char	*find_pathname(t_execve_args *execve_args,  t_fds *fds);
char	*build_exec_path(char const *s1, char const *s2); 
size_t	ft_strlen(const char *s); // destroy
void	ft_putstr_fd(char *s, int fd); //destroy
void	populate_structs(t_fds *fds, t_execve_args *execve_args, char **argv, char **envp);
void	print_error(t_fds *fds);
void	free_mem(t_execve_args *execve_args);

#endif