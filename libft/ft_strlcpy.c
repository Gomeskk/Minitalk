/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:01:35 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:35:01 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/* int main() {
    char destination[20];
    const char *source = "Get good";
    size_t result = ft_strlcpy(destination, source, sizeof(destination));
    printf("Copied string: %s\n", destination);
    printf("Result: %ld\n", result);

    return 0;
} */