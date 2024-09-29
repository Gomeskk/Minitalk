/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:22:54 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:29:36 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;

	len = ft_strlen(s);
	dest = malloc(sizeof(*dest) * (len + 1));
	if (dest)
	{
		ft_memcpy(dest, s, len);
		dest[len] = '\0';
	}
	return (dest);
}

/* int main() {
    const char *original = "KEEP GOING MY BOY";
    char *duplicate;
    duplicate = ft_strdup(original);
    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);
    }
	else
		printf("Memory allocation failed.\n");
    return 0;
} */
/*
duplicates a new string, copy using malloc
ft_strlen stops when finding a null byte... so we add
that null byte at the end
memcpy to copy byte by byte
*/
