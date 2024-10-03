/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:31:02 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/03 11:24:25 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			write(fd, &s[i++], 1);
	}
}

/* int main() {
    char *message = "Hello, world!";
    int file_descriptor = STDOUT_FILENO;
    ft_putstr_fd(message, file_descriptor);
	printf("\n");
    return 0;
} */
/* Outputs the string ’s’ to the given file
descriptor. */