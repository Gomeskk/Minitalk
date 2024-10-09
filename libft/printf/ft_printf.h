/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:47:13 by joafaust          #+#    #+#             */
/*   Updated: 2024/05/23 13:10:42 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# define DECIMAL "0123456789"
# define HEXA "0123456789abcdef"
# define HEXA2 "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	conversions(const char *str, va_list p);
int	ft_putdigit(long long int n, int base, char	*bstr);
int	ft_putstr(char *s);
int	ft_putpointer(unsigned long int n, int flag, char	*basestr);

#endif