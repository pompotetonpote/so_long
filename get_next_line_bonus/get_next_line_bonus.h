/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:00:12 by yperonne          #+#    #+#             */
/*   Updated: 2022/04/20 11:59:00 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;	
}				t_list;

char	*get_next_line(int fd);
void	read_and_stash(int fd, t_list **stash);
int		isnewline(t_list *stash);
t_list	*ft_lstlast(t_list *lst);
void	add_to_stash(t_list **stash, char *buf, int parsed);
void	extract_line(t_list *stash, char **line);
void	get_line(char **line, t_list *stash);
void	clean_stash(t_list **stash);
void	free_stash(t_list *stash);
size_t	ft_strlen(const char *str);

#endif
