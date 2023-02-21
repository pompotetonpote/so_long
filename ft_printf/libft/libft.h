/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:47:22 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/14 16:25:56 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int a);
int		ft_isdigit(int a);
int		ft_isalnum(int a);
int		ft_isascii(int a);
int		ft_isprint(int a);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int a);
int		ft_tolower(int a);
char	*ft_strchr(const char *str, int a);
char	*ft_strrchr(const char *str, int a);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
void	*ft_memchr(const void *dst, int a, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *dst, int a, size_t len);
void	ft_bzero(void *dst, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *str, char c);
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
t_list	*ft_lstnew(void *content);
void	*ft_lstadd_front(t_list **alst, t_list *new);
void	*ft_lstadd_back(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
