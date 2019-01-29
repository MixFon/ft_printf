/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 10:36:59 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/29 11:00:51 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Fill string number for ft_itoo
*/

static void	ft_fullstr_o(char *str, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_itoa(n);
	while (str[i] != '\0')
		i++;
	str[i] = *ptr;
	free(ptr);
}

/*
** Move decimal to octal and fill string
*/

void		ft_itoo(char *str, int n)
{
	if (n >= 8)
		ft_itoo(str, n / 8);
	ft_fullstr_o(str, n % 8);
}
