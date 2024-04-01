/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:27:50 by jakim             #+#    #+#             */
/*   Updated: 2024/04/01 20:41:44 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	access_test(char *path, char **ar, char *envp[], int *flag)
{
	char	*tmp;

	tmp = ft_strjoin(path, ar[0]);
	if (!access(tmp, X_OK))
	{
		free(ar[0]);
		ar[0] = ft_strdup(tmp);
		*flag = execve(tmp, ar, envp);
	}
	free(tmp);
}

int	execute(char *argv, char *envp[])
{
	char	**path;
	char	**ar;
	int		flag;
	int		i;

	i = 0;
	flag = -1;
	path = extract_path(envp);
	ar = make_arg(argv);
	while (path[i])
	{
		access_test(path[i], ar, envp, &flag);
		i++;
	}
	access_test("", ar, envp, &flag);
	f_all(ar);
	f_all(path);
	return (flag);
}
