/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:27:35 by jakim             #+#    #+#             */
/*   Updated: 2024/04/01 21:57:56 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_err(int n, int tar, int status, int type)
{
	if (type)
	{
		if (n == tar)
			error_end(status);
	}
	else if (type == 0)
	{
		if (n != tar)
			error_end(status);
	}
	else
	{
		if (n < tar)
			error_end(status);
	}
}

static void	pipe_set(int f1, int fd[], int type)
{
	if (!type)
	{
		close(fd[0]);
		dup2(f1, 0);
		dup2(fd[1], 1);
	}
	else
	{
		close(fd[1]);
		dup2(f1, 1);
		dup2(fd[0], 0);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		f1;
	pid_t	pid;
	int		stat;

	check_err(argc, 5, EINVAL, 0);
	f1 = open(argv[1], O_RDONLY);
	check_err(f1, -1, ENOENT, 1);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		pipe_set(f1, fd, 0);
		check_err(execute(argv[2], envp), -1, ENOENT, 1);
	}
	else
		waitpid(pid, &stat, WNOHANG);
	//check_err(WEXITSTATUS(stat), 0, ECHILD, 2);
	close(f1);
	f1 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	check_err(f1, -1, ENOENT, 1);
	pipe_set(f1, fd, 1);
	check_err(execute(argv[3], envp), -1, ENOENT, 1);
	close(f1);
	return (0);
}
