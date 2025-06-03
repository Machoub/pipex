/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:13:44 by machouba          #+#    #+#             */
/*   Updated: 2024/03/15 13:18:00 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(int n, char *cmd)
{
	if (n == 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (n == 1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		exit(127);
	}
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_env(char **envp, char *name)
{
	int			i;
	int			j;
	char		*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*exec;
	char	*path_part;
	char	**allpath;
	char	*getenv;

	i = -1;
	getenv = get_env(envp, "PATH");
	if (!getenv || !*envp)
		return (cmd);
	allpath = ft_split(getenv, ':');
	if (!allpath)
		error(1, cmd);
	if (access(cmd, F_OK) == 0)
		return (free_tab(allpath), cmd);
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	return (perror("No such file or directory"), free_tab(allpath), cmd);
}
