/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:09:44 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/29 16:32:16 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_recstr(char *str, long long int neg)
{
	int		i;
	size_t	n;
	char	cop[12];
	char	*rtnstr;

	n = 0;
	i = ft_strlen(str) - 1;
	if (neg < 0)
		cop[n++] = '-';
	if (i == -1)
		cop[n++] = '0';
	while (i >= 0)
	{
		cop[n] = str[i];
		n++;
		i--;
	}
	cop[n] = '\0';
	if (!(rtnstr = ft_strdup(cop)))
		return (NULL);
	return (rtnstr);
}

char		*ft_itoa(long long int n)
{
	size_t				i;
	unsigned int	num;
	int				neg;
	char			str[12];
	char			*rtnstr;

	i = 0;
	neg = 0;
	num = n;
	if (n < 0)
	{
		num = num * (-1);
		neg = -1;
	}
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	str[i] = '\0';
	if (!(rtnstr = ft_recstr(str, neg)))
		return (NULL);
	return (rtnstr);
}
