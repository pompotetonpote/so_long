/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:59:36 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/18 18:29:08 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_and_stash(fd, &stash);
	if (!stash)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_stash(int fd, t_list **stash)
{
	char	*buf;
	int		parsed;

	parsed = 1;
	while (!isnewline(*stash) && parsed != 0)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return ;
		parsed = read(fd, buf, BUFFER_SIZE);
		if ((parsed == 0 && *stash == NULL) || parsed == -1)
		{
			free(buf);
			return ;
		}
		buf[parsed] = '\0';
		add_to_stash(stash, buf, parsed);
		free(buf);
	}
}

void	add_to_stash(t_list **stash, char *buf, int parsed)
{
	int		i;
	t_list	*last;
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (!lstnew)
		return ;
	lstnew->next = NULL;
	lstnew->content = malloc((parsed + 1) * sizeof(char));
	if (!(lstnew->content))
		return ;
	i = 0;
	while (buf[i] && i < parsed)
	{
		lstnew->content[i] = buf[i];
		i++;
	}
	lstnew->content[i] = '\0';
	if (!(*stash))
	{
		*stash = lstnew;
		return ;
	}
	last = ft_lstlast(*stash);
	last->next = lstnew;
}

void	extract_line(t_list *stash, char **line)
{
	int		i;
	int		j;

	if (!stash)
		return ;
	get_line(line, stash);
	if (!(*line))
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;

	clean = malloc(sizeof(t_list));
	if (!stash || !clean)
		return ;
	clean->next = NULL;
	last = ft_lstlast(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof (char)
			* ((ft_strlen(last->content) - i) + 1));
	if (!(clean->content))
		return ;
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	free_stash(*stash);
	*stash = clean;
}
