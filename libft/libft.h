/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 16:51:20 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 15:32:06 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUF_SIZE 1
# define BUFF_SIZE 128

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_print_bits(unsigned char octet);
void				ft_swap(void const *a, void const *b);
void				ft_error(char *str);

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memalloc(size_t size);

char				*ft_stractrim(const char *str, const char c);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strdup(char *src);
char				*ft_strjoin(char const *dest, char const *src);
char				*ft_strjoinfree(char *dest, char *src);
char				*ft_strcjoin(char const *dest, char const *src, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *destination, const char *source,
	size_t num);
size_t				ft_strlcat(char *dest, const char *src, size_t num);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnchr(const char *s, int c, size_t start);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find,
	size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strrev(char const *str);

int					ft_sqrt(int nb);
int					ft_occur(const char *str, const char c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_atoi(char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int n);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_absolu(int nb);
size_t				ft_strlen(char const *str);
int					*ft_range(int min, int max);
size_t				ft_strspn(const char *s, const char *accept);
size_t				ft_strcspn(const char *s, const char *reject);
int					ft_natoi(char *str, size_t start);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_print_lst(t_list *elem);

int					get_next_line(const int fd, char **line);

#endif
