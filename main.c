#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include "libft/libft.h"

int main(int argc, char *argv[], char *envp[]){
	int	fd[2];
	int	f1;
	pid_t	pid;
	int	stat;

	if (argc != 5)
		error_end(EINVAL);
	f1 = open(argv[1], O_RDONLY);
	if (f1 == -1)
		error_end(ENOENT);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(f1, 0);
		dup2(fd[1], 1);
		if(execute(argv[2], envp) == -1)
			error_end(ENOENT);
	}
	else
		wait(&stat);
	if (WEXITSTATUS(stat) < 0)
		error_end(ECHILD);
	close(f1);
	//
	f1 = open(argv[4], O_WRONLY | O_TRUNC |O_CREAT, 0644);
	if (f1 == -1)
		error_end(ENOENT);
	close(fd[1]);
	dup2(f1, 1);
	dup2(fd[0], 0);
	if(execute(argv[3], envp) == -1)
		error_end(ENOENT);
	if (WEXITSTATUS(stat) != 0)
		error_end(ECHILD);
	close(f1);
}