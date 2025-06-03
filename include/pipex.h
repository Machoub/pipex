/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:09:28 by machouba          #+#    #+#             */
/*   Updated: 2024/03/15 13:09:58 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/inc/libft.h"

void	parent_process(int *fd, char **argv, char **envp);
void	child_process(int *fd, char **argv, char **envp);
void	execute(char *cmd, char **envp);
void	error(int n, char *cmd);
void	free_tab(char **tab);
char	*get_env(char **envp, char *name);
char	*get_path(char *cmd, char **envp);
int		wait_child(pid_t pid);

#endif