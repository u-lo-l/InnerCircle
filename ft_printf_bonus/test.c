#include <stdio.h>
#include "ft_printf.h"
int main()
{
	int a;
	printf("==========================\n");
	printf("[%1c]\n", 97);
	ft_printf("[%1c]\n", 97);
	printf("==========================\n");
	printf("[%1s]\n", "ABC");
	ft_printf("[%1s]\n", "ABC");
	printf("==========================\n");
	printf("[%-15p]\n", &a);
	ft_printf("[%-15p]\n", &a);
	printf("==========================\n");
	printf("[%+5d]\n", 97);
	ft_printf("[%+5d]\n", 97);
	printf("==========================\n");
	printf("[%+.5d]\n", 97);
	ft_printf("[%+.5d]\n", 97);
	printf("==========================\n");
	printf("[%01i]\n", 97);
	ft_printf("[%01i]\n", 97);
	printf("==========================\n");
	printf("[%01u]\n", 97);
	ft_printf("[%01u]\n", 97);
	printf("==========================\n");
	printf("[%01x]\n", 97);
	ft_printf("[%01x]\n", 97);
	printf("==========================\n");
	printf("[%01X]\n", 97);
	ft_printf("[%01X]\n", 97);
	printf("==========================\n");
	printf("[%%]\n");
	ft_printf("[%%]\n");
	printf("==========================\n");
	printf("[%8.6d]\n", 1234);
	ft_printf("[%8.6d]\n", 1234);
	printf("==========================\n");
	printf("[% 8.6d]\n", 1234);
	ft_printf("[% 8.6d]\n", 1234);
	printf("==========================\n");
	printf("[%+8.6d]\n", 1234);
	ft_printf("[%+8.6d]\n", 1234);
	printf("==========================\n");
	printf("[%-8.6d]\n", 1234);
	ft_printf("[%-8.6d]\n", 1234);
	printf("==========================\n");
	printf("[%+8.6d]\n", 0);
	ft_printf("[%+8.6d]\n", 0);
	printf("==========================\n");
	printf("[%.d]\n", 0);
	ft_printf("[%.d]\n", 0);
	printf("==========================\n");
	printf("[%.x]\n", 0);
	ft_printf("[%.x]\n", 0);
	printf("==========================\n");
	printf("[%.X]\n", 0);
	ft_printf("[%.X]\n", 0);
	printf("==========================\n");
	printf("[%s]\n", "STRING");
	ft_printf("[%s]\n", "STRING");
	printf("==========================\n");
	printf("[%10s]\n", "STRING");
	ft_printf("[%10s]\n", "STRING");
	printf("==========================\n");
	printf("[%.5s]\n", "STRING");
	ft_printf("[%.5s]\n", "STRING");
	printf("==========================\n");
	printf("[%-10s]\n", "STRING");
	ft_printf("[%-10s]\n", "STRING");
	printf("==========================\n");
	printf("[%10.5s]\n", "STRING");
	ft_printf("[%10.5s]\n", "STRING");
	printf("==========================\n");
	printf("[%-10.5s]\n", "STRING");
	ft_printf("[%-10.5s]\n", "STRING");
	printf("==========================\n");
	printf("[%p]\n", (void *)0);
	ft_printf("[%p]\n", (void *)0);
	printf("==========================\n");
	printf("[%0d]\n", 0);
	ft_printf("[%0d]\n", 0);
	printf("==========================\n");
	// printf("[%5-czd]\n", 'a');
	printf("a    z\n"); // for MAC not for Ubuntu.
	ft_printf("[%5-czd]\n", 'a');
	printf("==========================\n");
	// printf("[%.2.3d]\n", -2);	//invalide
	// ft_printf("[%.2.3d]\n", -2);
	// printf("==========================\n");

	printf("[%.3s]\n", (char *)0);
	printf("==========================\n");
	printf("[%-.3s]\n", (char *)0);
	printf("==========================\n");
	printf("[%8.3s]\n", (char *)0);
	printf("==========================\n");
	printf("[%-8.3s]\n", (char *)0);
	printf("==========================\n");

	printf("[%3p]\n", (void *)0);
	printf("==========================\n");
	printf("[%-3p]\n", (void *)0);
	printf("==========================\n");
	printf("[%8p]\n", (void *)0);
	printf("==========================\n");
	printf("[%-8p]\n", (void *)0);
	printf("==========================\n");

	printf("[%x]\n", 1);
	ft_printf("[%x]\n", 1);
	printf("==========================\n");
	printf("[%#x]\n", 1);
	ft_printf("[%#x]\n", 1);
	printf("==========================\n");
	printf("[%.16x]\n", 1);
	ft_printf("[%.16x]\n", 1);
	printf("==========================\n");
	printf("[%#.16x]\n", 1);
	ft_printf("[%#.16x]\n", 1);
	printf("==========================\n");
	printf("[%8p]\n", (void *)0);
	ft_printf("[%8p]\n", (void *)0);
	printf("==========================\n");
	printf("[%#.0X]\n", 0);
	ft_printf("[%#.0X]\n", 0);
	printf("==========================\n");
	printf("[%.0x]\n", 0);
	ft_printf("[%.0x]\n", 0);
	printf("==========================\n");
	printf("[%.0u]\n", 0);
	ft_printf("[%.0u]\n", 0);
	printf("==========================\n");
	printf("[%.0d]\n", 0);
	ft_printf("[%.0d]\n", 0);
	printf("==========================\n");
	printf("==========================\n");
	printf("[%8p]\n", (void *)0);
	ft_printf("[%8p]\n", (void *)0);
	printf("==========================\n");
	printf("[%#x]\n", 0);
	ft_printf("[%#x]\n", 0);
	printf("==========================\n");
}