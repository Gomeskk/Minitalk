/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:15:30 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/09 23:20:55 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	found_errors(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (1);
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (1);
	}
	return (0);
}

static void	send_nextchar_bit_bit(unsigned char len, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(WAIT_TIME);
	}
}

static void	ft_s_strlen_bit_bit(int len, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(WAIT_TIME);
	}
}

static void	ft_signal(int sig)
{
	static int	bit;
	static int	byte;

	(void)sig;
	if (sig == SIGUSR2)
	{
		bit++;
		if (bit == 8)
		{
			byte++;
			bit = 0;
		}
	}
	else if (sig == SIGUSR1)
	{
		ft_printf("\nBytes received with success: %d\n", byte + 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str_send;
	int		len;
	int		i;

	signal(SIGUSR1, &ft_signal);
	signal(SIGUSR2, &ft_signal);
	if (found_errors(argc, argv))
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
		return (-1);
	str_send = argv[2];
	len = ft_strlen(str_send);
	i = -1;
	ft_s_strlen_bit_bit(len, pid);
	while (str_send[++i])
		send_nextchar_bit_bit(str_send[i], pid);
	send_nextchar_bit_bit(str_send[i], pid);
	while (1)
		pause();
	return (0);
}
