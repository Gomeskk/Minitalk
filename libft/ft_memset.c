/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:02:20 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:17:54 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int main() {
    char str[20];
    size_t size = 2; // Number of characters to set
    int character = '*'; // Character to set
    ft_memset(str, character, size);
    printf("Result: %s\n", str);
    return 0;
} */
/*
writes n bytes of value c to the string s. return first argument.
*/
