/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:02:05 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:26:45 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

/* int main() {
    char *str = "Hello, world!";
    char search_char = 'o';
    
    char *result = ft_strchr(str, search_char);

    if (result != NULL)
        printf("found at position: %ld\n", search_char, result - str);
    else
        printf("Character '%c' not found\n", search_char);
    return 0;
} */
/*
if c is not found in s, then it returns a pointer to
		the null byte at the end of s,
*/
