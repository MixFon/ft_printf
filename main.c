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
#define LONG_MAX 9223372036854775807
#define ULLONG_MAX 18446744073709551615
int main()
{
	int	*i;
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
	ft_printf("%p", 0);
	ft_putstr("\n");
	printf("%p", 0);
	return 0;
}

