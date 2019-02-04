/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:43:38 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/04 12:29:19 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_last_ver/ft_printf.h"
#define LONG_MAX 2147483647
#define ULLONG_MAX 18446744073709551613
int main()
{
	int	*t;
//	char	*b;
//	char	*c;
//	unsigned int	n;
//	char	*str; 

	//str = ft_strnew(20);
	//b = "asdf";
//	n = 10;
//	n = 4294967295;
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
//	str = ft_itoa(n);
//	ft_putendl(str);
	/*size_t Gb = 1024*1024;
	char *a = (char *)malloc(2 * Gb * sizeof(char));
	char *b = (char *)malloc(2 * Gb * sizeof(char));
	printf("use %%X: a=%X\n", a);
	printf("use %%X: b=%X\n", b);
	printf("use %%p: a=%p\n", a);
	printf("use %%p: b=%p\n", b); 
	*/
/*	int i;
	printf("int\t%p\n", &i);

	unsigned long l;
	printf("u long\t%p\n", &l);

	char *str;

	printf("char *\t%p\n", &str);

	printf("strlen\t%p\n", &strlen);

	printf("%p\n", (char*)0);
*/
	/*
	ft_printf("\\n");
	ft_printf("%%\\n");
	ft_printf("%d\\n", 42);
	ft_printf("%d%d\\n", 42, 41);
	ft_printf("%d%d%d\\n", 42, 43, 44);
	ft_printf("%ld\\n", 2147483647);
	ft_printf("%lld\\n", 9223372036854775807);
	ft_printf("%x\\n", 505);
	ft_printf("%X\\n", 505);
	ft_printf("%p\\n", &ft_printf);
	ft_printf("%20.15d\\n", 54321);
	ft_printf("%-10d\\n", 3);
	ft_printf("% d\\n", 3);
	ft_printf("%+d\\n", 3);
	ft_printf("%010d\\n", 1);
	ft_printf("%hhd\\n", 0);
	ft_printf("%jd\\n", 9223372036854775807);
	ft_printf("%zd\\n", 4294967295);
	ft_printf("%\\n");
	ft_printf("%U\\n", 4294967295);
	ft_printf("%u\\n", 4294967295);
	ft_printf("%o\\n", 40);
	ft_printf("%%#08x\\n", 42);
	ft_printf("%x\\n", 1000);
	ft_printf("%#X\\n", 1000);
//	ft_printf("%s\\n", NULL);
	ft_printf("%S\\n", L"ݗݜशব");
//	ft_printf("%s%s\\n", "test", "test");
//	ft_printf("%s%s%s\\n", "test", "test", "test");
	ft_printf("%C\\n", 15000);
	*/
	ft_printf("%10.24lf", 123.234);
	ft_putstr("\n");
	printf("%10.24lf", 123.234);
	return 0;
}

