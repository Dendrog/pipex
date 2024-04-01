/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:28:01 by jakim             #+#    #+#             */
/*   Updated: 2024/04/01 21:51:14 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"

char	*ft_strdup2(const char *s, int len);
void	error_end(int er);
char	**extract_path(char *envp[]);
char	**make_arg(char *argv);
void	f_all(char **target);
void	access_test(char *path, char **ar, char *envp[], int *flag);
int		execute(char *argv, char *envp[]);

#endif