/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:05:58 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/25 14:01:49 by latabagl         ###   ########.fr       */
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
# include "libft.h"

# define ERR_CMD_NOT_FOUND   127
# define ERR_PERMISSION      126
# define ERR_FILE_PERMISSION 42
# define ERR_FILE_NOT_FOUND  43
# define ERR_GENERIC         1

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
void	open_files(const char *file1, 
			const char *file2, 
			t_fds *fds, 
			t_execve_args *execve_args);
void	set_pipe(t_fds *fds, t_execve_args *execve_args);
pid_t	fork_and_exec(t_fds *fds, t_execve_args *execve_args, int cmd);
void	exec_cmd(t_execve_args *execve_args, t_fds *fds);
void	redirect_first_cmd(t_fds *fds, t_execve_args *execve_args);
void	redirect_second_cmd(t_fds *fds, t_execve_args *execve_args);
char	*get_path_env_var(t_execve_args *execve_args, t_fds *fds);
void	get_execve_args(t_execve_args *execve_args, int cmd, t_fds *fds);
int		is_path_env_var(char *env_var);
char	*find_pathname(t_execve_args *execve_args, t_fds *fds);
char	*build_exec_path(char const *s1, char const *s2); 
void	populate_structs(t_fds *fds, 
			t_execve_args *execve_args, 
			char **argv, 
			char **envp);
void	print_error(t_fds *fds, int err, t_execve_args *execve_args);
void	print_message(char *msg, char *cmd_or_file);
int		get_exit_status(int err);
void	free_mem(t_execve_args *execve_args);
void	prepare_pipex(t_execve_args *execve_args, 
			t_fds *fds, 
			char **argv, 
			char **envp);

#endif