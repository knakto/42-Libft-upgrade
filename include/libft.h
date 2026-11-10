/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kml.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:31:29 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 21:06:55 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KML_H
# define KML_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>

//############ DIGIT ###############//
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
long	ft_htol(const char *nptr);

//############ CHAR ###############//
int	ft_isspace(int c);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

//############ PRINT ###############//
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		pnf(const char *str, ...);

//############ MEMORY ###############//
void	ft_free(void);
void	*ft_malloc(size_t count, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//############ STRING ###############//
char	*fjoin(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**fsplit(char *s, char c);
char	**ft_split(const char *s, char c);
char	**free_split(char **alloc);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);

//############ LINKED LIST ###############//
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstremove_if(t_list **list, void *data_ref,
			int (*cmp)(void *content, void *data_ref),
			void (*del)(void *content));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter_if(t_list *list, void (*f)(void *), void *data_ref,
			int (*cmp)(void *contnet, void *data_ref));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_list_find(t_list *list, void *data_ref,
			int (*cmp)(void *content, void *data_ref));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstadd_back(t_list **lst, t_list *node);

//############ MEMORY ###############//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_line
{
	char			*content;
	int				length;
	struct s_line	*next;
}					t_line;

char	  *get_next_line(int fd);
t_line	*ft_gnl_lstnew(char *content);
t_line	*ft_gnl_lstlast(t_line *lst);
void	  *ft_gnl_calloc(size_t nmemb, size_t size);
void	  ft_gnl_lstadd_back(t_line **lst, t_line *lst_new);
void	  ft_gnl_lstclear(t_line **lst, void (*del)(void *));

#endif
