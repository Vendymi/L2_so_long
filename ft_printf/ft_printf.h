/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmichali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:02:50 by vmichali          #+#    #+#             */
/*   Updated: 2023/02/25 18:02:58 by vmichali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

void	ft_put_hex(unsigned long nb, char format);
int		ft_print_char(int c);
int		ft_print_int(int n);
int		ft_check_cond(va_list args, const char c);
int		ft_printf(const char *format, ...);
int		len_check(unsigned int num);
int		ft_print_u(unsigned int n);
int		ft_hex_len(long long nb);
int		ft_print_hex(long long nb, char format);
int		ft_print_p(void *p);
int		ft_print_str(char *str);

#endif
