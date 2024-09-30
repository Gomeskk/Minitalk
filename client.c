/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:08:40 by joafaust          #+#    #+#             */
/*   Updated: 2024/09/30 14:50:47 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int  found_errors(int argc, char **argv)
{
    int i;

    if (argc !=3)
        return(1);
    i = -1;
    while (argv[i][++i])
    {
        if (!ft_strchr("0123456789", argv[1][i]))
            return(1);
    }
    return(0);
}