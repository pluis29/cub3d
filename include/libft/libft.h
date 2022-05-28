/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:58:46 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/26 15:42:42 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

typedef struct s_variable
{
	ssize_t		index;
	char		*buf;
	char		*tmp;
}	t_variable;

char	*ft_free_null(char **string);
void	ft_free_pointer(void **ptr);
char	*ft_free_doublePtr(char **str);
char	*ft_free_triplePtr(char ***str);
int		ft_checkIsNumber(const char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memset(void *dest, int str, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_cmp(const void *string1, const void *string2);
int		ft_cmp_byStart(const void *string1, const void *string2, int start);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
