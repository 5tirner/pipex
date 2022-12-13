# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:28:25 by zasabri           #+#    #+#              #
#    Updated: 2022/12/13 22:45:47 by zasabri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= pipex.c\
		pipex_utils.c\
		../libft/ft_calloc.c\
		../libft/ft_bzero.c\
		../libft/ft_strnstr.c\
		../libft/ft_split.c\
		../libft/ft_strlen.c\
		../libft/ft_strjoin.c\
		
OBJS	= $(SRCS:.c=.o)

PROG	= pipex

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all : $(PROG)

$(PROG) : $(OBJS)

	$(CC) $(OBJS) -o $(PROG)

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(PROG)

re : fclean all
