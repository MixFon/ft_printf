/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:43:38 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/25 14:00:52 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_fullstr(char *str, int n)
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
void ft_printbit(char *str, int n)
{
	if (n >= 8)
		ft_printbit(str, n / 8);
	ft_fullstr(str, n % 8);
//	ft_putnbr(n % 8);
}

int main()
{
	char a;
	char *b;
	char *c;

	//b = "asdf";
	a = 'E';
	b = ft_strnew(12);
	c = ft_strnew(4);
	ft_printbit(b, -1);
	ft_putendl(b);
	ft_printbit(c, 49);
	ft_putendl(c);
	free(b);
	free(c);
	//ft_printf("Hello\n%0.5dH\n", 20);
	printf("Hello\n%oH\n", -3);
	return 0;
}
