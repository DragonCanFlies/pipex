/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:19:24 by latabagl          #+#    #+#             */
/*   Updated: 2025/07/28 17:01:49 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(t_fds *fds, int err, t_execve_args *execve_args)
{
	int	exit_status;

	if (err == ERR_CMD_NOT_FOUND)
		print_message("command not found: ", execve_args->argv[0]);
	else if (err == ERR_PERMISSION)
		print_message("permission denied: ", execve_args->argv[0]);
	else if (err == ERR_FILE_PERMISSION)
		print_message("permission denied: ", fds->filename);
	else if (err == ERR_FILE_NOT_FOUND)
		print_message("no such file or directory: ", fds->filename);
	else 
		perror("pipex");
	close_fds(fds);
	free_mem(execve_args);
	exit_status = get_exit_status(err);
	exit(exit_status);
}

void	print_message(char *msg, char *cmd_or_file)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(cmd_or_file, 2);
	ft_putstr_fd("\n", 2);
}

int	get_exit_status(int err)
{
	if (err == ERR_CMD_NOT_FOUND)
		return (127);
	else if (err == ERR_PERMISSION)
		return (126);
	return (1);
}
