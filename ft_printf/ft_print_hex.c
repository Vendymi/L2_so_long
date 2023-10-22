/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:41:51 by vmichali          #+#    #+#             */
/*   Updated: 2023/03/11 15:52:46 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_put_hex(unsigned long nb, char format)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, format);
		ft_put_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd ('a' + (nb - 10), 1);
			else if (format == 'X')
				ft_putchar_fd ('A' + (nb - 10), 1);
		}
	}
}

int	ft_hex_len(long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(long long nb, char format)
{
	int	len;

	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		len = ft_hex_len(nb);
		ft_put_hex(nb, format);
	}
	len = ft_hex_len(nb);
	return (len);
}
