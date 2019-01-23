/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:42:41 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/22 16:19:04 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft_last_ver/libft.h"

typedef struct	s_format
{
	char		flag;
	int			width;
	int			exactness;
	char		size[3];	
}				t_format;

#endif
