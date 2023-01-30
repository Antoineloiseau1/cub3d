/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:44:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/30 10:20:01 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// libft:

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *b, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
void	*ft_memmove(void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, int start, int len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_display_tab(char **tab);
char	*ft_strcat(char *dest, char *src);

// ft_printf

void	ft_putchar_len(char c, int *len);
void	ft_puthexa_len(unsigned int n, char c, int *len);
void	ft_putmem_len(unsigned long int mem, int *len);
void	ft_putnbr_len(int n, int *len);
void	ft_putstr_len(char *str, int *len);
void	ft_putunbr_len(unsigned int n, int *len);
void	ft_putunbr_len(unsigned int n, int *len);
void	ft_cases(char c, va_list args, int *len);
int		ft_printf(const char *format, ...);

// get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
int		ft_is_endline(char *save);
char	*ft_read_file(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_clean_save(char *save);
char	*ft_strrnstr(const char *haystack, const char *needle, size_t len);

// Self-made:

int		tab_len(char **tab);
char	**cut_endl(char **strings);
int		ft_isspace(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		locate_char(char *s, char c);
int		ft_strchrset(const char *s, char *charset);
char	**ft_tabdup(char **t_str);
char	*strcut_endl(char *s);
void	print_tab(char *tab[]);

#endif
