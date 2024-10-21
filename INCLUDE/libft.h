/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:40:42 by brappo            #+#    #+#             */
/*   Updated: 2024/01/25 11:24:35 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	void			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	int		length;
	t_node	*node;
}	t_list;

typedef struct s_dict
{
	t_node	*keys;
	t_node	*values;
	int		length;
}	t_dict;

t_node	*create_node(void *content);
t_node	*add_node(t_list **list, void *value);
void	free_list(t_list *list, void (*free_value)(void *));
void	print_list(t_list *list, char *str);
t_list	*create_list(void);
void	*to_array(t_list *list);
void	print_array(void **array, size_t length, char *str);
t_list	*to_list(void **array, int length);
t_node	*lst_element_at(t_list *lst, int index);
int		find_node_index(t_list *lst, t_node *node);
void	lst_remove_at(t_list *lst, int index, void (*free_value)(void *));
void	lst_remove(t_list *list, t_node *node, void (*free_value)(void *));
void	for_each(t_list *list, void (*f)(void *));
void	set_each(t_list *list, void *(*f)(void *));
int		lst_count_value(t_list *list, void *value, int (*f)(void *, void *));
int		*lst_find_all(t_list *list, void *value, int *count,
			int (*f)(void *, void *));
int		lst_find_first(t_list *list, void *value, int (*f)(void *, void*));
t_node	*lst_get_last(t_list *lst);
t_node	*insert(t_list **list, int index, void *value);
void	add_lst(t_list *start, t_list *end);
t_dict	*create_dict(void);
int		ft_atoi(char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		read_file(int fd, char **result);

#endif //!LIBFT_H