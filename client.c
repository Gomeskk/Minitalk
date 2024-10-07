/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:08:40 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/07 16:37:06 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static volatile int	g_ack_received = 0;

static void	ack_handler(int signal)
{
	if (signal == SIGUSR1)
		g_ack_received = 1;
}

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
		//printf("Client: Acknowledgment received\n");
	}
}

static void	ft_s_strlen_bit_bit(int len, int pid)
{
	int	i;

	i = -1;
	//printf("Client: Sending message length %d (in bits):\n", len);
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

int	main(int argc, char **argv)
{
	int					pid;
	char				*str_send;
	int					len;
	int					i;
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	if (found_errors(argc, argv))
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	str_send = argv[2];
	len = ft_strlen(str_send);
	i = -1;
	ft_s_strlen_bit_bit(len, pid);
	while (str_send[++i])
		send_nextchar_bit_bit(str_send[i], pid);
	send_nextchar_bit_bit(str_send[i], pid);
}
