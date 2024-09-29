/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:39:25 by joafaust          #+#    #+#             */
/*   Updated: 2024/04/23 00:24:40 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	function_f_striteri(unsigned int nr, char *str)
{
	if (str)
		*str = ft_toupper(*str);
}

int main()
{
    char str_striteri[12] = "-?ABCDefg.h";
    printf("New: %s\n", str_striteri);
    ft_striteri(str_striteri, function_f_striteri);
    printf("New: %s\n", str_striteri);
    return 0;
} */

/* Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary. */
