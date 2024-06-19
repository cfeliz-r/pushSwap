/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:29:19 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/19 14:04:13 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long	ft_isalpha(long c);
long	ft_isdigit(long c);
long	ft_isalnum(long c);
long	ft_isascii(long c);
long	ft_isprint(long c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, long c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
long	ft_toupper(long i);
long	ft_tolower(long i);
char	*ft_strchr(const char *s, long c);
char	*ft_strrchr(const char *s, long c);
long	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, long c, size_t n);
long	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
long	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned long start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(long n);
char	*ft_strmapi(char const *s, char (*f)(unsigned long, char));
void	ft_striteri(char *s, void (*f)(unsigned long, char *));
void	ft_putchar_fd(char c, long fd);
void	ft_putstr_fd(char *s, long fd);
void	ft_putendl_fd(char *s, long fd);
void	ft_putnbr_fd(long n, long fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
long	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
long	ft_strcmp(char *s1, char *s2);

#endif
