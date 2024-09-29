/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:39:20 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/28 23:47:36 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	nb;

	nb = n;
	size = ft_size(nb);
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	while (size > 0)
	{
		str[--size] = (nb % 10) + 48;
		nb /= 10;
	}
	if (*str == 48)
		*str = '-';
	if (!n)
		*str = 48;
	return (str);
}

/* int	main(void)
{
	char result_itoa[] = ft_itoa(0);
	printf("%s \n", result_itoa);
	free(result_itoa);
} */

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/