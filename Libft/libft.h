/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:53:05 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/05/03 19:28:32 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int ch);
int				ft_isalnum(int c);
int				ft_isprint(int c);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src,
	size_t n);
void			*ft_memccpy(void *dst, const void *src,
	int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *str);
size_t			ft_str_number_of_words(const char *str, char sep);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t len);
char			*ft_strcat(char *str1, const char *rstr2);
char			*ft_strchr(const char *str, int ch);
void			ft_strclr(char *s);
void			ft_str_array_free_all(char **arr);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlcat(char *dst, const char *src,
	size_t size);
char			*ft_strncat(char *dst, const char *src,
	size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned intstart, size_t len);
char			*ft_strnstr(const char *stra, const char *strb, size_t len);
char			*ft_strrchr(const char *str, int ch);
int				ft_strsplitcnt(char const *s, char c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *stra, const char *strb);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
void			ft_putchar(int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(int c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lst_print_all(t_list *lst);
void			ft_lst_free_all(t_list *lst);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
long long int	ft_maxmin(char *type, char *maxmin);
int				get_next_line(const int fd, char **line);

#endif
