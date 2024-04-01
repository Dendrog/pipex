void	access_test(char *path, char **ar, char *envp[], int *flag)
{
	char	tmp;

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
	char *tmp;
	char	**path;
	char	**ar;
	int	flag;
	int	i;

	i = 0;
	flag = -1;
	path = extract_path(envp);
	ar = make_arg(argv);
	while(path[i])
	{
		//access_test(path[i], ar, envp, &flag);
		tmp = ft_strjoin(path[i], ar[0]);
		if (!access(tmp, X_OK))
		{
			free(ar[0]);
			ar[0] = ft_strdup(tmp);
			flag = execve(tmp, ar, envp);
		}
		free(tmp);
		i++;
	}
	tmp = ft_strdup(ar[0]);
	if (!access(tmp, X_OK))
	{
			free(ar[0]);
			ar[0] = ft_strdup(tmp);
			flag = execve(tmp, ar, envp);
	}
	free(tmp);
	f_all(ar);
	f_all(path);
	return (flag);
}

char	**extract_path(char *envp[])
{
	char **tmp;
	char **re;

	tmp = NULL;
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			break ;
		envp++;
	}
	if (*envp)
	{
		tmp = ft_split((*envp) + 5, ':');
		re = tmp;
		while (*re)
		{
			ft_strlcat(*re,"/",999);
			re++;
		}
	}
	return (tmp);
}

char **make_arg(char *argv)
{
	char	**re;
	char	*tmp;

	re = ft_split(argv,' ');
	if (!re)
		return (NULL);
	tmp = ft_strdup2(re[0], 100);
	re[0] = tmp;
	return (re);
}