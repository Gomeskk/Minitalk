/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:59:09 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/22 15:58:47 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdc(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static size_t	ft_word_size(const char *str, int n, char c)
{
	size_t	i;

	i = 0;
	while (str[n] && str[n] != c)
	{
		n++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	int		a;
	int		i;
	char	**r;

	i = 0;
	a = 0;
	size = ft_wdc(s, c);
	r = (char **)malloc(sizeof(char *) * (size + 1));
	if (r == 0)
		return (NULL);
	r[size] = NULL;
	while (a < size)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			r[a] = ft_substr(s, i, ft_word_size(s, i, c));
		while (s[i] && s[i] != c)
			i++;
		a++;
	}
	return (r);
}

/* #include <stdio.h>
int	main(void)
{
	char const*str_split = "such a pity";
	char sep_split = ' ';
	char **result_split =   ft_split(str_split, sep_split);

	for(int i = 0; result_split[i]; i++)
		printf("Print: %s\n", result_split[i]);
	for(int a = 0; result_split[a]; a++)
	{
		free(result_split[a]);
	}
	free(result_split);
} */

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/