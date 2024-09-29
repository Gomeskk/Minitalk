/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42fr.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:00:57 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/29 00:54:29 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s);
	if (!(char)c)
		return ((char *)s + i);
	while (s && --i >= 0)
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (NULL);
}

/* int main() {
    const char *string = "Lets end this ok?!";
    int search_char = 'a';
    char *result = ft_strrchr(string, search_char);
    if (result != NULL)
        printf("found at position: %ld\n",result - string);
    else
        printf("Character '%c' not found in \"%s\"\n", search_char, string);
    return 0;
} */