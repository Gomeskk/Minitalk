/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:03:40 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:07:06 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else
			return ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]));
	}
	return (0);
}

/* int main() {
    char str1[] = "Hello";
    char str2[] = "HellO";
    size_t compare_size = 5; // Size of the strings to compare
    int result = ft_memcmp(str1, str2, compare_size);
    if (result == 0)
        printf("The strings are equal up to %zu characters.\n", compare_size);
    else if (result < 0)
        printf("The first differing character in str1 comes before the str2.\n");
    else
        printf("The first differing character in str1 comes after the str2.\n");
    return 0;
} */
