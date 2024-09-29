/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:34:18 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:11:28 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return (((unsigned char *)(s + i)));
		i++;
	}
	return (NULL);
}

/* int main() {
    char str[] = "this is fucking amazing!";
    char *result;
    int search_char = 'a';
    size_t search_size = 26; // Size of the string including the null terminator
    result = ft_memchr(str, search_char, search_size);
    if (result != NULL)
        printf("%ld\n", search_char, (size_t)(result - str));
    else 
        printf("Character '%c' not found\n", search_char);
    return 0;
} */