/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_things_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:20:01 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/21 17:50:25 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialize_fds(t_fds *fds)
{
	fds->infile = -1;
	fds->outfile = -1;
	fds->pipe_fd[0] = -1;
	fds->pipe_fd[1] = -1;
}

void	close_fds(t_fds *fds)
{
	close(fds->infile);
	close(fds->outfile);
	close(fds->pipe_fd[0]);
	close(fds->pipe_fd[1]);
}

void	open_files(const char *infile, const char *outfile, t_fds *fds)
{
	fds->infile = open(infile, O_RDONLY);
	fds->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds->outfile == -1)
	{
		perror("pipex");
		close_fds(fds);
		exit(1);
	}	
}

void	set_pipe(t_fds *fds)
{
	if (pipe(fds->pipe_fd) == -1)
	{
		perror("pipex");
		close_fds(fds);
		exit(1);
	}
}
