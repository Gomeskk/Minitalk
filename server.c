/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:08:44 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/03 15:30:03 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	*ft_calloc_exit(size_t count, size_t size)
{
	size_t	t_size;
	void	*ret;

	t_size = size * count;
	ret = malloc(t_size);
	if (!ret)
		exit(EXIT_FAILURE);
	ft_bzero(ret, t_size);
	return (ret);
}

static void	rec_strlen(int *curr_bit, char **str, int *rec, int j)
{
	static int	len_val = 0;

	if (j == SIGUSR2)
		len_val += ft_recur_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*rec = 1;
		*str = ft_calloc_exit(len_val + 1, sizeof(char));
		*curr_bit = 0;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}

static void	ft_restart_var(int *len_rec, char **str, int *s)
{
	*len_rec = 0;
	if (str)
	{
		ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
	*s = 0;
}

static void	ft_rec_info_from_client(int signal)
{
	static int	char_val = 0;
	static int	curr_bit = 0;
	static int	len_rec = 0;
	static int	i = 0;
	static char	*final_str = 0;

	if (!len_rec)
		rec_strlen(&curr_bit, &final_str, &len_rec, signal);
	else
	{
		if (signal == SIGUSR2)
			char_val += ft_recur_power(2, curr_bit);
		if (curr_bit == 7)
		{
			final_str[i++] = char_val;
			curr_bit = 0;
			if (char_val == 0)
				return (ft_restart_var(&len_rec, &final_str, &i));
			char_val = 0;
			return ;
		}
		curr_bit++;
	}
}
/*
** SIGUSR1 = 30 ---> defines the '0' bit
** SIGUSR2 = 31 --> defines the '1' bit
*/

int	main(void)
{
	int	id;

	id = (int)(getpid());
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_rec_info_from_client);
	signal(SIGUSR2, ft_rec_info_from_client);
	while (1)
		usleep(WAIT_TIME);
}
