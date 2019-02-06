/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:30:40 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/04 16:36:01 by widraugr         ###   ########.fr       */
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
		c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'C' || c == 'U' ||
		c == 'S' || c == 'C' || c == 'D' || c == 'O' || c == 'f' || c == 'F')
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
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == 'L')
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
	if (*c == '*' )
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
	lst->dot = 1;
	return (i);
}

/*
** Считывает поле "флаг" (flag) и записывает флаг в структуру
** Возваращает колличество считанных символов. 
*/

int	ft_read_flag(char *c, t_format *lst)
{
	static int	i;

	//if (*c == '0' && *(c + 1) == '.')
	//	return (0);
	if (ft_isflag(*c))
		lst->flag[i] = *c;
	i++;
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
	while (!ft_istype(*c) && *c != '\0' )
	{
		//ft_putchar(*c);
		//ft_putchar('\n');
		while(ft_isflag(*c))
			c += ft_read_flag(c, lst);
		while (ft_isdigit(*c) || *c == '*')
			c += ft_read_width(c, lst, lst_arg);	
		if (*c == '.')
			c += ft_read_exact((c + 1), lst, lst_arg);	
		if (ft_issize(*c))
			c += ft_read_size(c , lst);
		//while(ft_isflag(*c))
		//	c += ft_read_flag(c, lst);
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
	ft_putendl("Flags in flag[5]:");
	ft_putchar(lst->flag[0]);
	ft_putstr("\n");
	ft_putchar(lst->flag[1]);
	ft_putstr("\n");
	ft_putchar(lst->flag[2]);
	ft_putstr("\n");
	ft_putchar(lst->flag[3]);
	ft_putstr("\n");
	ft_putchar(lst->flag[4]);
	ft_putstr("\n");
	ft_putendl("Width, exactness, dot, size, len_str in lst:");
	ft_putnbr(lst->width);
	ft_putstr("\n");
	ft_putnbr(lst->exactness);
	ft_putstr("\n");
	ft_putnbr(lst->dot);
	ft_putstr("\n");
	ft_putstr(lst->size);
	ft_putstr("\n");
	ft_putnbr(lst->len_str);
	ft_putstr("\n");
}

/*
** Создает новую структуру и задает им стартовые значения 
*/

t_format *ft_newstruct(void)
{
	t_format	*lst;
	int			i;
	
	i = -1;
	if(!(lst = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	while (++i < 5)
		lst->flag[i] = '\0';
	lst->width = 0;
	lst->exactness = 0;
	lst->dot = 0;
	lst->size[0] = '\0';
	lst->size[1] = '\0';
	lst->size[2] = '\0';
	lst->len_str = 0;
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
** Устранавливает знак +, - или ox в ft_cop_str_right.
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
	if (str1[0] == '0' && str1[1] == 'x' && str2[0] == '0')
	{
		str1[0] = '0';
		str1[1] = '0';
		str2[0] = '0';
		str2[1] = 'x';
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
** Проверяет есть ли в массиве flag[5] нужный символ флага 
*/

int ft_chack_flag(t_format *lst, char flag)
{
	int i;

	i = -1;
	while (++i < 5)
		if (lst->flag[i] == flag)
			return (1);
	return (0);
}
/*
** Вывдит отрицательное десятичное число
*/

void ft_negative_decimal(t_format *lst, intmax_t arg)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (ft_chack_flag(lst, '0') && !ft_chack_flag(lst, '-') && lst->exactness == 0)
		str_wid = ft_strnew_char('0', lst->width);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
//	ft_putendl(str_wid);
	str = ft_itoa(arg);
	str_exa = ft_strnew_char('0', lst->exactness + 1);
//	ft_putendl(str_exa);
//	ft_putendl(str);
	str = ft_cop_str_right(str, str_exa);
//	ft_putendl(str);
	if (ft_chack_flag(lst, '-'))
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
//	ft_putendl("Final str:");
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

/*
** Вставлят знак + перед положительным числом если есть флаг "+"
** Вставлят знак ' ' перед положительным числом если есть флаг " "(пробел)
*/

void ft_plus_or_space(t_format *lst, char **str)
{
	char *s;

	if (ft_chack_flag(lst, '+'))
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

void ft_positive_decimal(t_format *lst, uintmax_t  arg)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (ft_chack_flag(lst, '0') && !ft_chack_flag(lst, '-') && lst->exactness == 0)
		str_wid = ft_strnew_char('0', lst->width);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
//	ft_putendl(str_wid);
	if (arg == 0 && lst->dot == 1 && !ft_chack_flag(lst, '+'))
		str = ft_strnew_char(' ', 0);
	else
		str = ft_itoa(arg);
	if (ft_chack_flag(lst, '+') || ft_chack_flag(lst, ' '))
	{
		ft_plus_or_space(lst, &str);
		str_exa = ft_strnew_char('0', lst->exactness + 1);
	}
	else 
		str_exa = ft_strnew_char('0', lst->exactness);
//	ft_putendl(str_exa);
//	ft_putendl(str);
	str = ft_cop_str_right(str, str_exa);
//	ft_putendl(str);
	if (ft_chack_flag(lst, '-'))
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
//	ft_putendl("Final str:");
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}
/*
** Определяет размерность типа по модификатору (size) 
** у БЕЗзнакового числа o, u, x, X
*/

uintmax_t ft_check_un_dimension(t_format *lst, va_list lst_arg)
{
	uintmax_t	arg;

	arg = va_arg(lst_arg, uintmax_t);
	//ft_putnbr(arg);
	if (lst->size[0] == 'h' && lst->size[1] == '\0')
	{
		arg = (unsigned short int)arg;
		//ft_putendl("1");
	}
	else	if (lst->size[0] == 'h' && lst->size[1] == 'h')
	{
	   arg = (unsigned char)arg;	
		//ft_putendl("2");
	}
	else	if (lst->size[0] == 'l' && lst->size[1] == '\0')
	{
	   arg = (unsigned long )arg;
	   //ft_putendl("3");
	}
	else	if (lst->size[0] == 'l' && lst->size[1] == 'l')
	{
	   arg = (unsigned long long int)arg;
	   //ft_putendl("4");
	}
	else	if (lst->size[0] == 'j' && lst->size[1] == '\0')
	{
	   arg = (uintmax_t)arg;	
		//ft_putendl("5");
	}
	else	if (lst->size[0] == 'z' && lst->size[1] == '\0')
	{
	   arg = (size_t)arg;	
		//ft_putendl("6");
	}
	else
	{
		arg = (unsigned int)arg;	
		//ft_putendl("7");
	}
	//ft_putnbr(arg);
	return (arg);
}

/*
** Определяет размерность типа по модификатору (size) 
** у знакового числа i и d
*/

intmax_t ft_check_dimension(t_format *lst, va_list lst_arg)
{
	intmax_t	arg;

	arg = va_arg(lst_arg, intmax_t);
	//ft_putnbr(arg);
	//ft_putendl("BBB\n");
	if (lst->size[0] == 'h' && lst->size[1] =='\0' )
	   arg = (short int)arg;	
	else	if (lst->size[0] == 'h' && lst->size[1] == 'h')
	   arg = (signed char)arg;	
	else	if (lst->size[0] == 'l' && lst->size[1] == '\0')
	   arg = (long int)arg;	
	else	if (lst->size[0] == 'l' && lst->size[1] == 'l')
	{
	   arg = (long long int)arg;	
	 //  ft_putendl("EEE\n");
	}
	else	if (lst->size[0] == 'j' && lst->size[1] == '\0')
	   arg = (intmax_t)arg;	
	else	if (lst->size[0] == 'z' && lst->size[1] == '\0')
	   arg = (size_t)arg;	
	else
	   arg = (int)arg;	
	//ft_putendl("\n");
	//ft_putnbr(arg);
//	ft_putendl("CCC\n");
	return (arg);
}

/*
** Определяет знак числа и отпровляет на вывод, согласно знаку
*/

void ft_put_decimal(t_format *lst, va_list lst_arg)
{
	intmax_t	arg;

	arg = ft_check_dimension(lst, lst_arg);
	//ft_putendl("\n");
	//ft_putnbr(arg);
	if (arg >= 0)
	{
	//	ft_putendl("1");
		ft_positive_decimal(lst, arg);
	}
	else
	{
	//	ft_putendl("2");
		ft_negative_decimal(lst, arg);
	}
}

/*
** Вставлят 0x перед восьмиричным числом, если есть флаг #
** Проверить на утечки! 
*/

void ft_octotorp_hex(char **str)
{
	char *s;

	s = *str;
	*str = ft_strjoin("0x", *str);
	free(s);
}
/*
** Переволит все буквы в верхний регистр
*/

void ft_str_toupper(char *str)
{
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		str++;
	}
}

/*
** Работа с положительным шеснацетиричным числом
** Флаги + и ' ' не учитываются
*/

void	ft_hexadecimal(t_format *lst, uintmax_t  arg, char char_x)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (ft_chack_flag(lst, '0') && lst->exactness == 0 &&
			!ft_chack_flag(lst, '-'))
		str_wid = ft_strnew_char('0', lst->width);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
//	ft_putendl(str_wid);
	if (arg == 0 && lst->dot == 1)
		str = ft_strnew_char(' ', 0);
	else
	{
		str = ft_strnew(23);
		ft_itox(str, arg);
	}
	if (ft_chack_flag(lst, '#') && arg != 0)
	{
		ft_octotorp_hex(&str);
		str_exa = ft_strnew_char('0', lst->exactness + 2);
	}
	else 
		str_exa = ft_strnew_char('0', lst->exactness);
//	ft_putendl(str_exa);
//	ft_putendl(str);
	str = ft_cop_str_right(str, str_exa);
//	ft_putendl(str);
	if (ft_chack_flag(lst, '-'))
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
	if (char_x == 'X')
		ft_str_toupper(str);
//	ft_putendl("Final str:");
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

/*
** Вывод целого числа без знака в шестнадцетеричной систем счисления.
** Дополнить функциями.
*/

void ft_put_hexadecimal(t_format *lst, va_list lst_arg, char char_x)
{
	intmax_t	arg;

	arg = ft_check_un_dimension(lst, lst_arg);
	ft_hexadecimal(lst, arg, char_x);
}

/*
** Вставлят 0 перед восьмиричным числом, если есть флаг #
*/

void ft_octotorp_octal(char **str)
{
	char *s;

	s = ft_strnew_char('0', ft_strlen(*str) + 1);
	*str = ft_cop_str_right(*str, s);
}

/*
** Работа с положительным восьмиричным числом
** Флаги + и ' ' не учитываются
*/

void	ft_octal(t_format *lst, uintmax_t arg)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (ft_chack_flag(lst, '0') && lst->exactness == 0 &&
			!ft_chack_flag(lst, '-'))
		str_wid = ft_strnew_char('0', lst->width);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
//	ft_putendl(str_wid);
	if (arg == 0 && lst->dot == 1)
		str = ft_strnew_char(' ', 0);
	else
	{
		str = ft_strnew(23);
		ft_itoo(str, arg);
	}
	if (ft_chack_flag(lst, '#'))
		ft_octotorp_octal(&str);
	str_exa = ft_strnew_char('0', lst->exactness);
//	ft_putendl(str_exa);
//	ft_putendl(str);
	str = ft_cop_str_right(str, str_exa);
//	ft_putendl(str);
	if (ft_chack_flag(lst, '-'))
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
//	ft_putendl("Final str:");
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

/*
** Вывод целого числа без знака в восьмеричной систем счисления.
** Дополнить функциями. Можно ли исправить int??
*/

void ft_put_octal(t_format *lst, va_list lst_arg)
{
	//ft_putchar((char)va_arg(lst_arg, int));
	uintmax_t	arg;

	arg = ft_check_un_dimension(lst, lst_arg);
	ft_octal(lst, arg);
}

/*
** Вывод целого числа без знака в восьмеричной систем счисления.
** Дополнить функциями. Можно ли исправить int??
*/
/*
void ft_put_foat(t_format *lst, va_list lst_arg)
{
	//ft_putchar((char)va_arg(lst_arg, int));
}
*/

/*
** Обрабатывает беззаковое число, не выводит пробел и +
*/

void ft_unsigned(t_format *lst, uintmax_t  arg)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (ft_chack_flag(lst, '0') && !ft_chack_flag(lst, '-') && lst->exactness == 0)
		str_wid = ft_strnew_char('0', lst->width);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
//	ft_putendl(str_wid);
	if (arg == 0 && lst->dot == 1 && !ft_chack_flag(lst, '+'))
		str = ft_strnew_char(' ', 0);
	else
		str = ft_un_itoa(arg);
	str_exa = ft_strnew_char('0', lst->exactness);
//	ft_putendl(str_exa);
//	ft_putendl(str);
	str = ft_cop_str_right(str, str_exa);
//	ft_putendl(str);
	if (ft_chack_flag(lst, '-'))
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
//	ft_putendl("Final str:");
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}


/*
** Вывод целого числа без знака в десятичной систем счисления.
** Дополнить функциями. Можно ли исправить int??
*/

void ft_put_unsigned(t_format *lst, va_list lst_arg)
{
	uintmax_t	arg;

	arg = ft_check_un_dimension(lst, lst_arg);
	ft_unsigned(lst, arg);
}

/*
** Выводит на печать форматированную строку.
** Дополнить функциями.
*/
/*
void ft_put_string(t_format *lst, va_list lst_arg)
{
	ft_putstr(va_arg(lst_arg, char *));
}
*/
/*
** Вывод символа, соответстветсвующего числу указанному в аргументе функции.
** Дополнить функциями. Можно ли исправить int??
*/
/*
void ft_put_char(t_format *lst, va_list lst_arg)
{
	ft_putchar((char)va_arg(lst_arg, int));
}
*/

/*
** Выводит знак процента %
*/

void	ft_put_percent(t_format *lst)
{
	char	*str_wid;
	char	*str;

	if (ft_chack_flag(lst, '0') && lst->exactness == 0 &&
			!ft_chack_flag(lst, '-'))
		str_wid = ft_strnew_char('0', lst->width);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
//	ft_putendl(str_wid);
		str = ft_strnew_char('%', 1);
	if (ft_chack_flag(lst, '-'))
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);

}

/*
** Проверяет является символ типа кобинированным символом SCDOU.
*/

void ft_check_special_type(char *iter, t_format *lst)
{
	if (*iter == 'U' || *iter == 'D' || *iter == 'O')
	{
		lst->size[0] = 'l';
		lst->size[1] = 'l';
	}
}

/*
** Выводит на экран поинтер в шеснацетиричной форме
*/

void ft_pointer(t_format *lst, uintmax_t arg)
{
	char	*str_wid;
	char	*str_exa;
	char	*str;

	if (ft_chack_flag(lst, '0') && lst->exactness == 0 &&
			!ft_chack_flag(lst, '-'))
		str_wid = ft_strnew_char('0', lst->width);
	else 
		str_wid = ft_strnew_char(' ', lst->width);
//	ft_putendl(str_wid);
	if (arg == 0 && lst->dot == 1)
		str = ft_strnew_char(' ', 0);
	else
	{
		str = ft_strnew(23);
		ft_itox(str, arg);
	}
		ft_octotorp_hex(&str);
		str_exa = ft_strnew_char('0', lst->exactness + 2);
//	ft_putendl(str_exa);
//	ft_putendl(str);
	str = ft_cop_str_right(str, str_exa);
//	ft_putendl(str);
	if (ft_chack_flag(lst, '-'))
		str = ft_cop_str_left(str, str_wid);
	else
		str = ft_cop_str_right(str, str_wid);
//	ft_putendl("Final str:");
	lst->len_str = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	
}

/*
** Выводит на экран поинтер в шеснацетиричной форме
*/

void ft_put_pointer(t_format *lst, va_list lst_arg)
{
	uintmax_t	arg;

	arg = va_arg(lst_arg, long long int);
	ft_pointer(lst, arg);
}
/*
** Распределяет строку, согдласно типу.
** Типы: c,s,p,d,i,o,u,x,X,f,%
*/

int ft_sotr_type(char *iter, t_format *lst, va_list lst_arg)
{
	ft_check_special_type(iter, lst);
	if (*iter == 'i' || *iter == 'd' || *iter == 'D')
		ft_put_decimal(lst, lst_arg);
	if (*iter == 'x' || *iter == 'X')
		ft_put_hexadecimal(lst, lst_arg, *iter);
	if (*iter == 'o' || *iter == 'O')
		ft_put_octal(lst, lst_arg);
	if (*iter == '%')
		ft_put_percent(lst);
	if (*iter == 'u' || *iter == 'U' )
		ft_put_unsigned(lst, lst_arg);
	if (*iter == 'f' || *iter == 'F')
		ft_put_float(lst, lst_arg, *iter);
	if (*iter == 's' || *iter == 's')
		ft_put_string(lst, lst_arg);
	if (*iter == 'c' || *iter == 'c')
		ft_put_char(lst, lst_arg);
	if (*iter == 'p')
		ft_put_pointer(lst, lst_arg);
	return (1); //Поправить!
}

/*
** Проверяет фалидность строки формата (символы после %
*/

int ft_chack_valid_format(char *iter, char **iter_ptr, int *len)
{
	int	i;

	i = 0;
	if (*iter == '\0')
	{
		(*len)++;
		return (0);
	}
	while (!ft_istype(*iter))
	{
		if ((!ft_isflag(*iter) && !ft_issize(*iter) &&
				!ft_isdigit(*iter) && *iter != '.' && *iter != '*')
				|| *(iter + 0) == '\0')
		{
			*iter_ptr += i;
			//ft_putnbr(*len);
			*len = i + 1;
			return (0);
		}
		i++;
		iter++;
	}
	//*iter_ptr += i;
	return (1);
}

/*
** Считывает флаги и вызывает функцию, соответствуюшую типу
*/

int ft_sort_arg(char *iter, va_list lst_arg, size_t *len_str,
		size_t *len_format)
{
	t_format	*lst;
	char		*ptr;

	ptr = iter;
	lst = ft_newstruct();
	ptr += ft_read_format(iter, lst, lst_arg);
	ptr += ft_sotr_type(ptr, lst, lst_arg);
	*len_str += lst->len_str;
	*len_format += (ptr - iter + 1);
	//ft_putlst(lst);
	free(lst);
	return (ptr - iter);
}

/*
** Функуия считывает строку формата и обрабатывает аргуменыт.
*/

int ft_printf(const char *restrict format, ...)
{
	char		*iter;	
	va_list		lst_arg;
	size_t		len_str;
	size_t		len_format;
	int			len;
	
	len = 0;
	len_str = 0;
	len_format = 0;
	va_start(lst_arg, format);
	iter = (char *)format;
	while (*iter != '\0')
	{
		if (*iter == '%')
		{
		  if(ft_chack_valid_format((iter + 1), &iter, &len))
			  iter += ft_sort_arg(iter + 1, lst_arg, &len_str, &len_format);
		}
		else 
			ft_putchar(*iter);
		iter++;
	}
	va_end(lst_arg);
	return ((iter - format) - len + len_str - len_format);	
}
