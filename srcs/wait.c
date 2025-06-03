/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:07:50 by machouba          #+#    #+#             */
/*   Updated: 2024/03/15 13:10:33 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	wait_child(pid_t pid)
{
	int	status;
	int	val;

	while (errno != ECHILD)
	{
		if (wait(&status) == pid)
		{
			if (WIFEXITED(status))
				val = WEXITSTATUS(status);
			else
				val = 128 + WTERMSIG(status);
		}
	}
	return (val);
}
