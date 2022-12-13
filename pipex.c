/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:45:00 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/12 17:27:31 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

void	the_child_process(char **av, char **env, int *fd)
{
	int		fd_in;

	if (access(av[1], F_OK) == -1)
	{
		write(2, "pipex: ", 7);
		write(2, "no such file or directory: ", 27);
		write(2, av[1], ft_strlen(av[1]));
		write(2, "\n", 1);
		exit (1);
	}
	fd_in = open(av[1], O_RDWR, 0777);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd[0]);
	ft_execute(av[2], env);
}

void	the_parent_process(char **av, char **env, int *fd)
{
	int		fd_out;

	fd_out = open(av[4], O_RDWR | O_CREAT, 0777);
	if (fd_out == -1)
	{
		write(2, "pipex: ", 7);
		write(2, av[4], ft_strlen(av[4]));
		write(2, " : file doesn't open\n", 21);
		exit (1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
		{
			write(2, "Creation of a child process was unsuccessful\n", 45);
			return (1);
		}
		if (pid == 0)
			the_child_process(av, env, fd);
		waitpid(pid, NULL, 0);
		the_parent_process(av, env, fd);
	}
	else
	{
		write(2, "Invalid number of argements\n", 28);
		return (1);
	}
}
