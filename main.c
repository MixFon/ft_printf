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

/*
** Заполняет строку числами для ft_itoo
** Добавить в библиотеку
*/

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

/*
** Переводит из десятичной в восмеричную систему
*/

void ft_itoo(char *str, int n)
{
	if (n >= 8)
		ft_itoo(str, n / 8);
	ft_fullstr(str, n % 8);
}

int main()
{
	char a;
	char *b;
	char *c;

	//b = "asdf";
	a = 'E';
/*	b = ft_strnew(12);
	c = ft_strnew(4);
	ft_itoo(b, -1);
	ft_putendl(b);
	ft_itoo(c, 49);
	ft_putendl(c);
	free(b);
	free(c);*/
	ft_putnbr(ft_printf("Hello\n%+-9.4iH", 21));
	ft_putstr("\n");
	ft_putnbr(printf("Hello\n%+-9.4iH", 21));
	return 0;
}
