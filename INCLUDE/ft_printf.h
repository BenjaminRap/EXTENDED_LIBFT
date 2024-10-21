/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:22:19 by brappo            #+#    #+#             */
/*   Updated: 2024/01/21 19:34:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define MINUS 0
# define PLUS 1
# define SPACE 2
# define HASH 3
# define ZERO 4
# define WIDTH 5
# define PRECISION 6
# define TYPE 7
# define CHAR 0
# define STRING 1
# define POINTER 2
# define DECIMAL 3
# define INTEGER 4
# define UNSIGNED 5
# define HEXA_MIN 6
# define HEXA_MAJ 7
# define PERCENTAGE 8

int				ft_is_in_set(char c, char *set);
int				ft_atoi(char *nptr);
int				ft_print_args(long nbr, char **result, int *flags);
int				ft_printf(const char *n, ...);
int				*ft_get_flags(va_list vl, char *str, size_t *i);
char			*ft_itoa_base(long n, char *base, int length_base, int nosign);
char			*ft_padding_left(int width, char *src, char c);
void			ft_padding(int *flags, char **result);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);
unsigned int	ft_cast_ul(unsigned int n);
unsigned long	ft_abs(int i);
char			*ft_precision(char *str, int precision, long nbr);
unsigned long	ft_cast_pointer(long n);
void			show_string(char *str, long *length);

#endif