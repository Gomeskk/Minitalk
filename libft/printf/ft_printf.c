/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:55:50 by joafaust          #+#    #+#             */
/*   Updated: 2024/05/17 10:49:32 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		retn;
	va_list	i;

	if (!str)
		return (-1);
	retn = 0;
	va_start(i, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			retn += conversions(&*str, i);
		}
		else
			retn += write(1, &*str, 1);
		str++;
	}
	va_end (i);
	return (retn);
}

int	conversions(const char *str, va_list p)
{
	int	retn;
	int	i;

	retn = 0;
	i = 0;
	if (*str == 'c')
	{
		i = va_arg(p, int);
		retn += write(1, &i, 1);
	}
	else if (*str == 's')
		retn += ft_putstr(va_arg(p, char *));
	else if (*str == 'd' || *str == 'i')
		retn += ft_putdigit(va_arg(p, int), 10, DECIMAL);
	else if (*str == 'u')
		retn += ft_putdigit(va_arg(p, unsigned int), 10, DECIMAL);
	else if (*str == 'x')
		retn += ft_putdigit(va_arg(p, unsigned int), 16, HEXA);
	else if (*str == 'X')
		retn += ft_putdigit(va_arg(p, unsigned int), 16, HEXA2);
	else if (*str == 'p')
		retn += ft_putpointer(va_arg(p, unsigned long int), 1, HEXA);
	else if (*str == '%')
		retn += write(1, "%%", 1);
	return (retn);
}

int	ft_putstr(char *s)
{
	int	retn;

	retn = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (*s)
	{
		retn += write(1, &*s, 1);
		s++;
	}
	return (retn);
}

int	ft_putdigit(long long int n, int base, char	*bstr)
{
	int		retn;

	retn = 0;
	if (n < 0 && base == 10)
	{
		retn += write(1, "-", 1);
		n *= -1;
	}
	if (n >= base)
		retn += ft_putdigit(n / base, base, bstr);
	retn += write(1, &bstr[n % base], 1);
	return (retn);
}

int	ft_putpointer(unsigned long int n, int flag, char	*basestr)
{
	int		retn;

	retn = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (flag == 1)
		retn += write(1, "0x", 2);
	if (n >= 16)
		retn += ft_putpointer(n / 16, 0, basestr);
	retn += write(1, &basestr[n % 16], 1);
	return (retn);
}

/* int	main(void)
{
	ft_printf("%d \n", ft_printf("%%"));
	//printf("%d \n", printf("%%"));

	int teste = printf("hello world\n");
	printf("imprimiu: %d\n", teste);
	int teste2 = ft_printf("hello world\n");
	ft_printf("imprimiu: %d\n", teste2);
	printf("\n");
	int x = 42;
	int x2 = 34;
	void *ptrx2 = &x2;
	void *ptr = &x;

	
	ft_printf("HELLO\n");
	ft_printf("%d \n", ft_printf(""));
	ft_printf("%d \n", ft_printf(NULL));
	ft_printf("CHARACTERS: %c %c\n", 'a', 'b');
	ft_printf("STRINGS: %s %s\n", "Good", "bye");
	ft_printf("DECIMAL: %i %d\n", 2, 123);
	printf("DECIMAL: %i %d\n", 2, 123);
	ft_printf ("DECIMALS: %d %d\n", 1977, 650000L);
	ft_printf("POINTER NULO: %p \n", NULL );
	ft_printf("POINTER DE x é: %p\n", ptr);
	ft_printf("POINTER 0: %p %p \n", (void *)0, (void *)0);
	ft_printf ("DECIMAL e HEXADECIMAL: %d %x %X \n", 255, 255, 255);
	ft_printf ("HEXADECIMAL 0: %x %X\n", 0, 0);
	ft_printf ("Unsigned int: %u %u\n",  2147483647, UINT_MAX);
	ft_printf ("Unsigned int: %u \n", UINT_MAX);
	ft_printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A',
		"Mix", ptrx2, 34, 34, 255, 255, UINT_MAX);


	ft_printf("\n");
	
	printf("Hello\n");
	printf("%d \n", printf(""));
	printf("%d \n", printf(NULL));
	printf("Characters: %c %c\n", 'a', 'b');
	printf("Strings: %s %s\n", "Good", "bye");
	printf("Decimal: %d %d\n", 42, 123);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf("Pointer nulo: %p \n", NULL );
	printf("Pointer de x é: %p\n", ptr);
	printf("Pointer 0: %p %p \n", (void *)0, (void *)0);
	printf ("Decimal e hexadecimal: %d %x %X \n", 255, 255, 255);
	printf (" Hexadecimal 0: %x %X\n", 0, 0);
	printf ("Unsigned int: %u %u\n", 2147483647, UINT_MAX);
	printf ("Unsigned int: %u \n", UINT_MAX);
	printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A', "Mix",
		ptrx2, 34, 34, 255, 255, UINT_MAX);
	return (0); 
}*/