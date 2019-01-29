/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:43:38 by widraugr          #+#    #+#             */
/*   Updated: 2019/01/29 16:32:19 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_last_ver/ft_printf.h"

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
	n = 128765398;
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
	ft_printf("%d %.d", -0, -0);
	ft_putstr("\n");
	printf("%d %.d", -0, -0);
	return 0;
}
