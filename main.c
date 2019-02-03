/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:43:38 by widraugr          #+#    #+#             */
/*   Updated: 2019/02/01 16:35:57 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_last_ver/ft_printf.h"
#define LONG_MAX 2147483647
#define ULLONG_MAX 18446744073709551615
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
	char  a;
	char  *b;

	a = 4;
	b = &a;
	ft_printf("{%p}",b);
	ft_putstr("\n");
	printf("{%p}",b);
	//printf("\t%llx", LONG_MAX);
	return 0;
}

