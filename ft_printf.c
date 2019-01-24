/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:30:40 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/24 16:20:21 by widraugr         ###   ########.fr       */
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

int	ft_issize(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	else
		return (0);
}

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
** Считывает поле "размер" (size) и записывает флаг в структуру
** Возваращает колличество считанных символов. 
** h, hh, l, ll, L
*/

int	ft_read_size(char *c, t_format *lst)
{
	if (ft_issize(*c) && ft_issize(*(c + 1)))
	{
		lst->size[0] = *c;
		lst->size[1] = *(c + 1);
		return (2);
	}
	if (ft_issize(*c))
	{
		lst->size[0] = *c;
		return (1);
	}
	return (0);
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
			c += ft_read_flag(c, lst);
		if (ft_isdigit(*c) || *c == '*')
			c += ft_read_width(c, lst, lst_arg);	
		if (*c == '.')
			c += ft_read_exact((c + 1), lst, lst_arg);	
		if (ft_issize(*c))
			c += ft_read_size(c , lst);
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
	ft_putstr("\n");
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
	lst->size[2] = '\0';
	return (lst);
}

/*
** Создание новой строки, заполненую нужным символом.
*/

char *ft_strnew_char(int c, size_t len)
{	
	char *ptr;

	ptr = ft_strnew(len);
	ptr =(char *)ft_memset((char *)ptr, c, len);
	return (ptr);
}

/*
** Устранавливает знак + или - в ft_cop_str_right.
*/
void ft_sign_str(char *str1, char *str2)
{
	if (str1[0] == '-' && str2[0] == '0')
	{
		str1[0] = '0';
		str2[0] = '-';
	}
	if (str1[0] == '+' && str2[0] == '0')
	{
		str1[0] = '0';
		str2[0] = '+';
	}
	if (str1[0] == ' ' && str2[0] == '0')
	{
		str1[0] = '0';
		str2[0] = ' ';
	}
}

/*
** Копирование str1 в str2 с конца обеих строк, если str2 больше.
*/

char *ft_cop_str_right(char *str1, char *str2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 >= len2)
	{
		ft_strdel(&str2);
		return (str1);
	}
	else 
	{
		ft_sign_str(str1, str2);
		while (len2 >= 0 && len1 >= 0)
			str2[len2--] = str1[len1--];
		ft_strdel(&str1);
		return (str2);
	}
}

/*
** Копирование str2 в str1 с начала обеих строк.
*/

char *ft_cop_str_left(char *str1, char *str2)
{
	int	len1;
	int	len2;
	int i;

	i = 0;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 >= len2)
	{
		ft_strdel(&str2);
		return (str1);
	}
	else 
	{
		while (i < len1 && i < len2)
		{
			str2[i] = str1[i];
			i++;
		}
		ft_strdel(&str1);
		return (str2);
	}
}

/*
** Вывдит отрицательное десятичное число
*/

void ft_negative_decimal(t_format *lst, int arg)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (lst->flag == '0' && lst->exactness == 0)
		str_wid = ft_strnew_char('0', lst->width + 1);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
	ft_putendl(str_wid);
	str_exa = ft_strnew_char('0', lst->exactness + 1);
	ft_putendl(str_exa);
	str = ft_itoa(arg);
	ft_putendl(str);
	str = ft_cop_str_right(str, str_exa);
	ft_putendl(str);
	if (lst->flag == '-')
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
	ft_putendl(str);
	ft_strdel(&str);
}
/*
** Вставлят знак + перед положительным числом если есть флаг "+"
** Вставлят знак ' ' перед положительным числом если есть флаг " "(пробел)
*/

void ft_plus_or_space(t_format *lst, char **str)
{
	char *s;

	if (lst->flag == '+')
	{
		s = ft_strnew_char('+', ft_strlen(*str) + 1);
		*str = ft_cop_str_right(*str, s);
	}
	else
	{
		s = ft_strnew_char(' ', ft_strlen(*str) + 1);
		*str = ft_cop_str_right(*str, s);
	}
}

/*
** Вывдит отрицательное десятичное число
*/

void ft_positive_decimal(t_format *lst, int arg)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (lst->flag == '0' && lst->exactness == 0)
		str_wid = ft_strnew_char('0', lst->width);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
	ft_putendl(str_wid);
		str = ft_itoa(arg);
	if (lst->flag == '+' || lst->flag == ' ')
	{
		ft_plus_or_space(lst, &str);
		str_exa = ft_strnew_char('0', lst->exactness + 1);
	}
	else 
		str_exa = ft_strnew_char('0', lst->exactness);
	ft_putendl(str_exa);
	ft_putendl(str);
	str = ft_cop_str_right(str, str_exa);
	ft_putendl(str);
	if (lst->flag == '-')
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
	ft_putendl(str);
	ft_strdel(&str);
}

/*
** Определяет знак числа и отпровляет на вывод, согласно знаку
*/

void ft_put_decimal(t_format *lst, va_list lst_arg)
{
	int		arg;

	arg = va_arg(lst_arg, int);
	if (arg >= 0)
		ft_positive_decimal(lst, arg);
	else
		ft_negative_decimal(lst, arg);
}

/*
** Вывод целого числа без знака в шестнадцетеричной систем счисления.
** Дополнить функциями.
*/

void ft_put_hexadecimal(t_format *lst, va_list lst_arg)
{
	ft_putnbr(va_arg(lst_arg, int));
}

/*
** Вывод целого числа без знака в восьмеричной систем счисления.
** Дополнить функциями. Можно ли исправить int??
*/

void ft_put_octal(t_format *lst, va_list lst_arg)
{
	//ft_putchar((char)va_arg(lst_arg, int));
}

/*
** Вывод целого числа без знака в восьмеричной систем счисления.
** Дополнить функциями. Можно ли исправить int??
*/

void ft_put_foat(t_format *lst, va_list lst_arg)
{
	//ft_putchar((char)va_arg(lst_arg, int));
}

/*
** Вывод целого числа без знака в десятичной систем счисления.
** Дополнить функциями. Можно ли исправить int??
*/

void ft_put_unsigned(t_format *lst, va_list lst_arg)
{
	//ft_putchar((char)va_arg(lst_arg, int));
}

/*
** Выводит на печать форматированную строку.
** Дополнить функциями.
*/

void ft_put_string(t_format *lst, va_list lst_arg)
{
	ft_putstr(va_arg(lst_arg, char *));
}

/*
** Вывод символа, соответстветсвующего числу указанному в аргументе функции.
** Дополнить функциями. Можно ли исправить int??
*/

void ft_put_char(t_format *lst, va_list lst_arg)
{
	ft_putchar((char)va_arg(lst_arg, int));
}

/*
** Распределяет строку, согдласно типу.
** Типы: c,s,p,d,i,o,u,x,X,f,%
*/

int ft_sotr_type(char *iter, t_format *lst, va_list lst_arg)
{
	if (*iter == 'i' || *iter == 'd')
		ft_put_decimal(lst, lst_arg);
	if (*iter == 'x' || *iter == 'X')
		ft_put_hexadecimal(lst, lst_arg);
	if (*iter == 'o')
		ft_put_octal(lst, lst_arg);
	if (*iter == 'f')
		ft_put_foat(lst, lst_arg);
	if (*iter == 'u')
		ft_put_unsigned(lst, lst_arg);
	if (*iter == 's')
		ft_put_string(lst, lst_arg);
	if (*iter == 'c')
		ft_put_char(lst, lst_arg);
	return (1111); //Поправить!
}

/*
** Считывает флаги и вызывает функцию, соответствуюшую типу
*/

int ft_sort_arg(char *iter, va_list lst_arg)
{
	t_format	*lst;
	int			i;		//Использует для пропускания символов формата
	char		*ptr;

	ptr = iter;
	lst = ft_newstruct();
	ptr += ft_read_format(iter, lst, lst_arg);
	ft_sotr_type(ptr, lst, lst_arg);
	ft_putlst(lst);
	free(lst);
	return (i);
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
