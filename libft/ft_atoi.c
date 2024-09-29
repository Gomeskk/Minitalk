/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:10:56 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/28 23:35:14 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
		res = (res * 10) + (*str++ - 48);
	return (res * sign);
}

/* int main() {
    const char *test_string = "-1234567890";
    int result = ft_atoi(test_string);
    printf("Result: %d\n", result);
    return 0;
} */
/*
DESCRIPTION
		The  atoi()  function converts the initial portion of
        the string pointed to by nptr to int.  The behavior is
		the same as

			strtol(nptr, NULL, 10);

		except that atoi() does not detect errors.

		The atol() and atoll() functions behave the same as atoi(),
			except that they convert the initial portion  of
		the string to their return type of long or long long.

*/