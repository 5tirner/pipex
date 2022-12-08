/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:41:40 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/08 16:18:44 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

char	*ft_path_cmd(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*current;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		current = ft_strjoin(paths[i], "/");
		path = ft_strjoin(current, cmd);
		free(current);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	ft_generate_error(void)
{
	perror("ERROR!... .");
}

void	ft_execute(char *argv, char **env)
{
	char	**cmd;
	int		i;
	char	*pathname;

	i = -1;
	cmd = ft_split(argv, ' ');
	pathname = ft_path_cmd(cmd[0], env);
	if (!pathname)
	{
		write(2, "pipex: command not found: ", 26);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, "\n", 1);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		return ;
	}
	if (execve(pathname, cmd, env) == -1)
	{
		write(2, "pipex: command not found: ", 26);
		write(2, cmd[i], ft_strlen(cmd[i]));
		write(2, "\n", 1);
		return ;
	}
}