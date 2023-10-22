/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:22:35 by vmichali          #+#    #+#             */
/*   Updated: 2023/02/25 18:22:37 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	len_check(unsigned int num)
{
	int	i;

	i = 1;
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_print_u(unsigned int n)
{
	unsigned int	num;

	num = n;
	if (num > 9)
	{
		ft_print_u(num / 10);
		ft_print_u(num % 10);
	}
	else
		ft_putchar_fd(num + '0', 1);
	return (len_check(n));
}
