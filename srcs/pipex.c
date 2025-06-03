/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:50:01 by machouba          #+#    #+#             */
/*   Updated: 2024/03/19 12:23:36 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	err_perm(char **tab)
{
	int	err;

	err = errno;
	perror(tab[0]);
	errno = err;
	free_tab(tab);
	exit(126);
}

void	execute(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (s_cmd[0] == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		free_tab(s_cmd);
		exit(127);
	}
	path = get_path(s_cmd[0], envp);
	if (execve(path, s_cmd, envp) == -1)
	{
		if (errno == EACCES)
			err_perm(s_cmd);
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		free_tab(s_cmd);
		exit(127);
	}
	free(path);
	free_tab(s_cmd);
}

void	child_process(int *fd, char **argv, char **envp)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
	{
		close(fd[1]);
		close(fd[0]);
		perror(argv[1]);
		exit(1);
	}
	dup2(filein, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(filein);
	execute(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
	{
		close(fd[1]);
		close(fd[0]);
		perror(argv[4]);
		exit(1);
	}
	dup2(fileout, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	close(fileout);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t		pid;
	int			fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error(0, NULL);
		pid = fork();
		if (pid == -1)
			error(0, NULL);
		if (pid == 0)
			child_process(fd, argv, envp);
		pid = fork();
		if (pid == -1)
			error(0, NULL);
		if (pid == 0)
			parent_process(fd, argv, envp);
		close(fd[0]);
		close(fd[1]);
		return (wait_child(pid));
	}
	else
		write(2, "Invalid number of arguments.\n", 29);
}
