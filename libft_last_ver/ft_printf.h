/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:42:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/04 12:15:49 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_format
{
	char		flag[5];
	int			width;
	int			dot;
	int			exactness;
	char		size[3];	
	size_t		len_str;
}				t_format;

int		ft_printf(const char *restrict format, ...);
//void	ft_itoo(char *str, int n);
//void	ft_itox(char *str, int n);
char 	*ft_strnew_char(int c, size_t len);
void 	ft_put_string(t_format *lst,va_list lst_arg);
int 	ft_chack_flag(t_format *lst, char flag);
char 	*ft_copy_string_left(char *str1, char *str2);
char 	*ft_copy_string_right(char *str1, char *str2);
void 	ft_put_char(t_format *lst,va_list lst_arg);
char	*ft_concat_str(char *str1, char *str2);
char*	ft_float_str(double num, int exact);
char*	ft_fraction_exact(char* fract_str, int exact);
void	ft_put_float(t_format *lst,va_list lst_arg);
char*	ft_round(char* fract_str);

#endif
