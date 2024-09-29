/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:16:13 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/22 23:36:02 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	n;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	str = malloc(n + 1);
	if (!str)
		return (NULL);
	while (n > i)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* char add_one(unsigned int index, char c)
{
    return c + 1;
}

int	main(void)
{
	char	input[] = "Hello, world!";
	char	*result;

	result = ft_strmapi(input, add_one);
	if (result == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Original string: %s\n", input);
	printf("Modified string: %s\n", result);
	free(result);
	return (0);
} */

/* Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f. */