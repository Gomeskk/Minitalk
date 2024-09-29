/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:57:47 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:57:47 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= i)
		len = 0;
	else if (len > (i - start))
		len = i - start;
	substr = malloc(len + 1);
	if (substr == 0)
		return (NULL);
	substr[len] = '\0';
	i = -1;
	while (++i < len)
	{
		substr[i] = s[start + i];
	}
	return (substr);
}

/* int main() {
	const char *string = "Hello, world!";
	unsigned int start_index = 7;
	size_t substring_length = 5;
	char *result = ft_substr(string, start_index, substring_length);
	if (result != NULL)
	{
		printf("Substring from index %u with length %zu: %s\n", start_index,
			substring_length, result);
		free(result); // Don't forget to free the memory allocated by ft_substr
	}
	else
		printf("Memory allocation failed or invalid input.\n");
	return (0);
} */