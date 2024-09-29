/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:45:11 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:46:55 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
		else
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}

/* int main() {
    const char *string1 = "Hello";
    const char *string2 = "Hello, world!";
    size_t compare_size = 5;

    int result = ft_strncmp(string1, string2, compare_size);

    if (result == 0)
        printf("The first %zu characters are equal.\n", compare_size);
    else if (result < 0)
        printf("the first cha \"%s\" is before \"%s\".\n", string1, string2);
    else
        printf("the first cha\"%s\" is after \"%s\".\n", string1, string2);
    return 0;
} */