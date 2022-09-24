#include "ft_fprintf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *i = "NULL";
	int a, b;

	a = ft_printf("%5.s\n", "123");
	b = printf("%5.s\n", "123");
	printf("%d - %d\n", a, b);
	
	//12-05-2022
	ft_printf("%50.2s", ((void*)0));
/* 1231.KO (Wrong output) (Wrong return)
   Expected: [                                                  ], return: 50
   Got:      [                                                ], return: 48
   You can rerun this test with sh test 1231
   The function was called like this:
   ft_printf("%50.2s", ((void*)0));
*/

	
	ft_printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42);
	ft_printf("3pointeur 1 %   p pointeur 2 % p\n\n", &c, &c);
	ft_printf("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42);
	
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
