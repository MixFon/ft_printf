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

void ft_fullstr_o(char *str, int n)
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
	ft_fullstr_o(str, n % 8);
}

/*
** Заполняет строку числами для ft_itoo
** Добавить в библиотеку
*/

void ft_fullstr_x(char *str, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_itoa(n);
	while (str[i] != '\0')
		i++;
	if (n == 10)
		str[i] = 'a';
	else	if (n == 11)
		str[i] = 'b';
	else	if (n == 12)
		str[i] = 'c';
	else	if (n == 13)
		str[i] = 'd';
	else	if (n == 14)
		str[i] = 'e';
	else	if (n == 15)
		str[i] = 'f';
	else	str[i] = *ptr;
	free(ptr);
}
/*
** Переводит из десятичной в шеснадцатиричную систему
*/

void ft_itox(char *str, int n)
{
	if (n >= 16)
		ft_itox(str, n / 16);
	ft_fullstr_x(str, n % 16);
}

int main()
{
	char	a;
	char	*b;
	char	*c;
	int		n;
	char	*str; 

	str = ft_strnew(20);
	//b = "asdf";
	n = 10;
	a = 'E';
	n = 12398;
	/*while (++n < 300)
	{
		b = ft_strnew(12);
		c = ft_strnew(12);
		ft_itox(b, n);
		ft_putendl(b);
		ft_itox(c, n);
		ft_putendl(c);
		free(b);
		free(c);
		printf("%#10x\n", n);
	}
	*/
	str = "Hello\n%# 9.4oH";
	ft_putnbr(ft_printf("Hello\n%-#10.6XH", n));
	ft_putstr("\n");
	ft_putnbr(printf("Hello\n%-#10.6XH", n));
	return 0;
}
