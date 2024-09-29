/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:58:45 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/28 23:48:52 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, '\0', n);
}

/* int main() {
	char test_string[] = "Hello, this is crazy!";
	size_t length = strlen(test_string);
	printf("%s\n", test_string);
	ft_bzero(test_string, length);
	printf("ft_bzero: %s\n", test_string);
	return (0);
} */
