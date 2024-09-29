/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:35:27 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:49:46 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!len && little[i])
		return (NULL);
	if (ft_strlen(big) >= ft_strlen(little) && len >= ft_strlen(little))
	{
		while (i <= len - ft_strlen(little))
		{
			if (!ft_strncmp(&big[i], little, ft_strlen(little)))
				return ((char *)&big[i]);
			i++;
		}
	}
	return (NULL);
}

/* int	main(void)
{
	const char	*big_string = "Hello, world!";
	const char	*little_string = "world";
	char		*result;
	size_t search_len = strlen(big_string); // Length of big_string to search
	result = ft_strnstr(big_string, little_string, search_len);
	if (result != NULL)
		printf("Found \"%s\" in \"%s\" at position: %ld\n", little_string,
			big_string, result - big_string);
	else
		printf("Substring \"%s\" not found in \"%s\"\n", little_string,
			big_string);
	return (0);
} */

/*
Description:
	locates the first instance of str little on str big on the
	first n bytes of big.
Return Value:
	pointer to the first instance of needle in haystack if found.
	NULL if not found.
	pointer to haystack if needle is empty.
*/