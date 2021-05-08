/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:02:53 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 23:12:33 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *h, const char *n, size_t len);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
							void (*del)(void *));

void				*ft_lincpy(char *dst, const char *src);
void				*ft_linlcpy(char *dst, const char *src, size_t n);
int					ft_linlen(char *str);
int					ft_intlen(int n);
int					ft_flolen(double n);
int					ft_arrlen(char **s);
int					ft_declen(double n);
int					ft_wrdlen(char *s, char c, int i);
int					ft_wrdlens(char *s, char *c, int i);
int					ft_cntwrd(char *s, char c);
int					ft_cntwrds(char *s, char *c);
char				*ft_malstr(char *s, char c);
char				*ft_malstrs(char *s, char *c);
void				*ft_frenarr(char **s, int i);
void				*ft_frearr(char **s);
char				*ft_revstr(char *s);
char				*ft_strupp(char *s);
char				*ft_strlow(char *s);
int					ft_isneg(double n);
int					ft_isxdigit(char *str);
int					ft_isodigit(int n);
int					ft_power(int n, int p);
unsigned long long	ft_sqrt(unsigned long long n);
unsigned long long	ft_factor(unsigned long long n);
unsigned long long	ft_fnprim(unsigned long long n);
int					ft_isprim(unsigned long long n);
void				ft_putznbr_fd(int n, int e, int fd);
void				ft_putflo_fd(double n, int fd);
void				ft_putzflo_fd(double n, int e, int fd);
int					ft_ftoi(double n);
double				ft_itof(int n);
double				ft_iftof(int n, int f);
char				*ft_ftoa(double n);
double				ft_atof(char *str);
int					ft_itob(int d);
int					ft_btoi(int i);
int					ft_dtoh(char c);
char				ft_htod(int n);
int					ft_htoi(char *str);
char				*ft_itoh(double n);
int					ft_ddtoi(char *str);
char				*ft_itodd(double n);
int					ft_otoi(int i);
int					ft_itoo(double n);
int					ft_round(int n, int h);
double				ft_fround(double n, int h);
void				ft_swap(int *a, int *b);
void				ft_putchar(char s);
void				ft_putstr(char *s);
void				ft_putendl(char *s);
void				ft_putnbr(int n);
void				ft_putznbr(int n, int e);
void				ft_putflo(double n);
void				ft_putzflo(double n, int e);
int					ft_varlen(int c, ...);
int					ft_max(int a, int b);
int					ft_vamax(int n, ...);
int					ft_min(int a, int b);
int					ft_vamin(int n, ...);
int					ft_chrstr(char c, char *s);
char				**ft_splits(char *s, char *c);

#endif
