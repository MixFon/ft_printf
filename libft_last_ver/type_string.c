#include "ft_printf.h"
/*
char *ft_copy_string_right(char *str1, char *str2)
{
	int	len1;
	int	len2;

	len1 = (int)ft_strlen(str1);
	len2 = (int)ft_strlen(str2);
	if (len1 >= len2)
	{
		ft_strdel(&str2);
		return (str1);
	}
	else
	{
		while (len2 >= 0 && len1 >= 0)
			str2[len2--] = str1[len1--];
		ft_strdel(&str1);
		return (str2);
	}
}
*/
/*
** Копирование str2 в str1 с начала обеих строк.
*/
/*
char *ft_copy_string_left(char *str1, char *str2)
{
	int	len1;
	int	len2;
	int i;

	i = 0;
	len1 = (int)ft_strlen(str1);
	len2 = (int)ft_strlen(str2);
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
*/
/*
** Функция для сокращения места в ft_put_str_without_size
*/

void	ft_sourse(char **arg, char **str_wid, int *flag, t_format *lst)
{
	if (*arg == NULL)
	{
		*arg = ft_strdup("(null)");
		*flag = 1;
	}
	*str_wid = ft_strnew_char(' ', lst->width);
}

void	ft_put_str_without_size(t_format *lst, va_list lst_arg)
{
	char	*str_wid;
	char	*str_exac;
	char	*str_res;
	char	*arg;
	int		flag;

	flag = 0;
	arg = va_arg(lst_arg, char*);
	ft_sourse(&arg, &str_wid, &flag, lst);
	if (lst->exactness == 0 && lst->dot == 0)
		str_exac = ft_strdup(arg);
	else
	{
		str_exac = ft_strnew_char(' ', lst->exactness);
		str_exac = ft_strncpy(str_exac, arg, lst->exactness);
	}
	if (ft_chack_flag(lst, '-'))
		str_res = ft_copy_string_left(str_exac, str_wid);
	else
		str_res = ft_copy_string_right(str_exac, str_wid);
	if (flag)
		ft_strdel(&arg);
	ft_putstr(str_res);
	lst->len_str = ft_strlen(str_res);
	ft_strdel(&str_res);
}

/*
** Функция для сокращения места в ft_put_str_without_size
*/

void	ft_sourse_wchar(wchar_t **arg, wchar_t **str_wid, int *flag, t_format *lst)
{
	if (*arg == NULL)
	{
		*arg = ft_strdup_wchar((const wchar_t*)"(null)");
		*flag = 1;
	}
	*str_wid = ft_strnew_char_wchar(' ', lst->width);
}
/*
** Обрабатывае формат wchar_t
*/
void ft_wchar_str(t_format *lst, va_list lst_arg)
{
	wchar_t	*str_wid;
	wchar_t	*str_exac;
	wchar_t	*str_res;
	wchar_t	*arg;
	int		flag;

	flag = 0;
	arg = va_arg(lst_arg, wchar_t*);
	ft_sourse_wchar(&arg, &str_wid, &flag, lst);
	if (lst->exactness == 0 && lst->dot == 0)
		str_exac = ft_strdup_wchar(arg);
	else
	{
		str_exac = ft_strnew_char_wchar(' ', lst->exactness);
		str_exac = ft_strncpy_wchar(str_exac, arg, lst->exactness);
	}
	if (ft_chack_flag(lst, '-'))
		str_res = ft_copy_string_left_wchar(str_exac, str_wid);
	else
		str_res = ft_copy_string_right_wchar(str_exac, str_wid);
	if (flag)
		ft_strdel_wchar(&arg);
	ft_putstr_wchar(str_res);
	lst->len_str = ft_strlen_wchar(str_res);
	ft_strdel_wchar(&str_res);
}

void ft_put_string(t_format *lst, va_list lst_arg, char s)
{
	//if (lst->size[0] == 'l' && lst->size[1] == '\0')
	//	lst->len_str = ft_put_str_with_size(lst, lst_arg);
	//else
	if (s == 's')
		 ft_put_str_without_size(lst, lst_arg);
	else	if (s == 'S')
		ft_wchar_str(lst, lst_arg);
}

/*int ft_put_str_without_size(t_format *lst, va_list lst_arg)
{
	char* str_wid;
	char* str_exac;
	char* str_res;

	str_wid = ft_strnew_char(' ', lst->width);
	if (lst->exactness == 0 && lst->dot == 0)
		str_exac = ft_strdup(va_arg(lst_arg, char*));
	else
	{
		str_exac = ft_strnew_char(' ', lst->exactness);
		str_exac = ft_strncpy(str_exac, va_arg(lst_arg, char*), lst->exactness);
	}
	if (ft_chack_flag(lst, '-'))
		str_res = ft_copy_string_left(str_exac, str_wid);
	else
		str_res = ft_copy_string_right(str_exac, str_wid);
	ft_putstr(str_res);
	return (ft_strlen(str_res));
}*/

//подумать
/*void ft_put_str_with_size(t_format *lst, va_list lst_arg)
{
	char* str_wid;
	char* str_exac;
	char* str_res;

	str_wid = ft_strnew_char(' ', lst->width);
	if (lst->exactness == -1)
		str_exac = ft_strdup(va_arg(lst_arg, char *));
	else
	{
		str_exac = ft_strnew_char(' ', lst->exactness);
		str_exac = ft_strncpy(str_exac, va_arg(lst_arg, char *), lst->exactness);
	}
	if (lst->flag == '-')
		str_res = ft_copy_string_left(str_exac, str_wid);
	else
		str_res = ft_copy_string_right(str_exac, str_wid);
	ft_putstr(str_res);
}*/


