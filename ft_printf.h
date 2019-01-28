/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:42:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/25 13:46:56 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "libft_last_ver/libft.h"

typedef struct	s_format
{
	char		flag[5];
	int			width;
	int			exactness;
	char		size[3];	
	size_t		len_str;
}				t_format;

int		ft_printf(const char *restrict format, ...);
void	ft_itoo(char *str, int n);

#endif
