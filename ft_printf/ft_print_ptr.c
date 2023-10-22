/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:59:12 by vmichali          #+#    #+#             */
/*   Updated: 2023/03/11 16:01:46 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd(nb + '0', 1);
		else
			ft_putchar_fd ('a' + (nb - 10), 1);
	}
}

int	ft_ptr_len(unsigned long long nb)
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

int	ft_print_ptr(unsigned long long nb)
{
	int	len;

	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		len = ft_ptr_len(nb);
		ft_put_ptr(nb);
	}
	return (len);
}

int	ft_print_p(void *p)
{
	int	len;

	len = 2;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		len += ft_print_ptr((unsigned long long)p);
	}
	return (len);
}
