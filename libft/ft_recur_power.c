/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur_power.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:06:26 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/03 15:07:39 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** int	ft_recur_power(int nb, int power)
** This function returns the result of nb ^ power
** Example: ft_recur_power(2, 3) = 2 ^ 3 = 8
*/

int	ft_recur_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && nb != 0)
		return (1);
	else
		return (nb * ft_recur_power(nb, power - 1));
}
