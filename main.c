#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *i = "NULL";
	int a, b;

	a = ft_printf("%5.s\n", "123");
	b = printf("%5.s\n", "123");
	printf("%d - %d\n", a, b);
//
//
//	a = ft_printf("%5.d\n", 123);
//	b = printf("%5.d\n", 123);
//	printf("%d - %d\n", a, b);

//	a = ft_printf("%5.p\n", i);
//	b = printf("%5.p\n", i);
//	printf("%d - %d\n", a, b);

//	int a = ft_printf("%5.3s", i);
//	printf(".\n");
//	int b = printf("%5.3s", i);
//	printf(".\n");
//	printf("%d - %d", a, b);

//	int a = ft_printf("%%%");
//	printf("\n");
//	int b = printf("%%%");
//	printf("\n");
//	printf("%d - %d", a, b);

	



//	ft_printf(NULL);
	//printf(NULL);
//	int	i = 123;
//	ft_printf("%--4.1s", "for");
//	ft_printf(".\n");
//	printf("%--4.1s", "for");
//	printf(".\n");
//	printf("%ld", SSIZE_MAX); // -9223372036854775806



}
