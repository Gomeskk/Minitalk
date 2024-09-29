/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:41:43 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/19 20:51:25 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		a;

	i = 0;
	a = 0;
	res = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (res == 0)
		return (NULL);
	while (s1 && s1[i])
		res[a++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		res[a++] = s2[i++];
	res[a] = 0;
	return (res);
}

/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*result;

	s1 = "Hello, ";
	s2 = "world!";
	result = ft_strjoin(s1, s2);
	if (result == NULL)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}
	printf("Joined string: %s\n", result);
	free(result); // Don't forget to free allocated memory
	return (0);
}
*/