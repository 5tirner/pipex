/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:56:14 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/12 18:22:48 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"

void	the_child(char **av, char **env, int *fd)
{
	int	fd_in;

	if (access(av[1], F_OK) == 0)
	{
		write(2, "pipex: no such file or directory: ", 34);
		write(2, av[1], ft_strlen(av[1]));
		write(2, "\n", 1);
		exit(1);
	}
	fd_in = open(av[1], O_RDWR, 0777);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd[0]);
	ft_exec(av[1])
}
int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (pid(fd) == -1)
				return (-1);
			pid = fork();
			if (pid == -1)
				return (-1);
			if (pid == 0)
				the_child(av, env, fd);
		}
	}
}