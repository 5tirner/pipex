/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:55:45 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/12 17:56:06 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s1, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	the_child_process(char **av, char **envp, int *fd);
void	the_parent_process(char **av, char **envp, int *fd);
char	*ft_path_cmd(char *cmd, char **envp);
void	ft_execute(char *argv, char **envp);
#endif