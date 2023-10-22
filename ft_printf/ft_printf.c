/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:02:41 by vmichali          #+#    #+#             */
/*   Updated: 2023/02/25 18:02:45 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	ft_print_str(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_check_cond(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (c == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		len = ft_print_p(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len = ft_print_int(va_arg(args, int));
	else if (c == 'u')
		len = ft_print_u(va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len = ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len += ft_check_cond(args, format[i + 1]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
