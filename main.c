/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:30:40 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/22 17:55:36 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Проверяет, является ли символ специальным символом флага.
*/

int	ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	else
		return (0);
}

/*
** Проверяет, является ли символ специальным символом типа
** c,s,p,d,i,o,u,x,X,f,%
*/

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == '%' ||
		c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	else
		return (0);
}

/*
** Проверяет, является ли символ модификатором размера.
** h, hh, l, ll, L
*/

/*
** Считывает поле "ширина" (width) и записывает значение в структуру.
** Возваращает колличество считанных символов. 
*/

int	ft_read_width(char *c, t_format *lst, va_list lst_arg)
{
	int i;

	i = 0;
	if (*c == '*')
	{
		lst->width = va_arg(lst_arg, int);
		i = 1;
	}
	else 
	{
		lst->width = ft_atoi(c);
		while (ft_isdigit(*c++))
			i++;
	}
	return (i);
}

/*
** Считывает поле "точность" (exactness) и записывает значение в структуру
** Возваращает колличество считанных символов. 
*/

int	ft_read_exact(char *c, t_format *lst, va_list lst_arg)
{
	int	i;

	i = 0;
	if (*c == '*')
	{
		lst->exactness = va_arg(lst_arg, int);
		i++;
	}
	else 
	{
		lst->exactness = ft_atoi(c);
		while (ft_isdigit(*c++))
			i++;
	}
	return (i);
}

/*
** Считывает поле "флаг" (flag) и записывает флаг в структуру
** Возваращает колличество считанных символов. 
*/

int	ft_read_flag(char *c, t_format *lst)
{
	if (*c == '0' && *(c + 1) == '.')
		return (0);
	if (ft_isflag(*c))
		lst->flag = *c;
	return (1);
}

/*
** Читает формат и записывает его в струкруру. Возвращает колличество прочитан-
** ных символов.
*/

int	ft_read_format(char *iter, t_format *lst, va_list lst_arg)
{
	char	*c;

	c = iter;
	while (!ft_istype(*c))
	{
		if (ft_isflag(*c) && !lst->flag)
			ft_read_flag(c, lst);
		if (ft_isdigit(*c) || *c == '*')
			c += ft_read_width(c, lst, lst_arg);	
		if (*c == '.')
			c += ft_read_exact((c + 1), lst, lst_arg);	
		if (!ft_istype(*c))
		c++;
	}
	return (c - iter);
}

/*
** Печатает содержимое листа, использовал для тестов
*/

void ft_putlst(t_format *lst)
{
	ft_putstr("\n");
	ft_putchar(lst->flag);
	ft_putstr("\n");
	ft_putnbr(lst->width);
	ft_putstr("\n");
	ft_putnbr(lst->exactness);
	ft_putstr("\n");
	ft_putstr(lst->size);
}

/*
** Создает новую структуру и задает им стартовые значения 
*/

t_format *ft_newstruct(void)
{
	t_format *lst;
	
	if(!(lst = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	lst->flag = '\0';
	lst->width = 0;
	lst->exactness = 0;
	lst->size[0] = '\0';
	lst->size[1] = '\0';
	return (lst);
}

/*
** Считывает флаги и вызывает функцию, соответствуюшую типу
*/

int ft_sort_arg(char *iter, va_list lst_arg)
{
	t_format *lst;

	lst = ft_newstruct();
	ft_read_format(iter, lst, lst_arg);
	ft_putlst(lst);
	free(lst);
	return (1);
}

/*
** Функуия считывает строку формата и обрабатывает аргуменыт.
*/

int ft_printf(const char *restrict format, ...)
{
	char		*iter;	
	va_list		lst_arg;
	
	va_start(lst_arg, format);
	iter = (char *)format;
	while (*iter)
	{
		if (*iter == '%')
			ft_sort_arg(iter + 1, lst_arg);
		else 
			ft_putchar(*iter);
		iter++;
	}
	va_end(lst_arg);
	return (iter - format);	
}

int main()
{
	char a;
	char *b;

	b = "asdf";
	a = 'E';
	ft_printf("Hello%0.*c1H22",122, a);
	return 0;
}
