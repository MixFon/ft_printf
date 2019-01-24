#include "ft_printf.h"

void ft_printbit(int n)
{
	if (n >= 8)
		ft_printbit(n / 8);
	ft_putnbr(n % 8);
}

int main()
{
	char a;
	char *b;

	b = "asdf";
	a = 'E';
	ft_printbit(20);
	//ft_printf("Hello\n%0.2oH\n", 1234);
	printf("Hello\n%#10.5oH\n", 20);
	return 0;
}
