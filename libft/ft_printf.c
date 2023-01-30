/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:24:06 by anloisea          #+#    #+#             */
/*   Updated: 2022/09/05 14:10:30 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cases(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar_len(va_arg(args, int), len);
	if (c == 's')
		ft_putstr_len(va_arg(args, char *), len);
	if (c == 'p')
	{
		ft_putstr_len("0x", len);
		ft_putmem_len(va_arg(args, unsigned long int), len);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr_len(va_arg(args, int), len);
	if (c == 'u')
		ft_putunbr_len(va_arg(args, unsigned int), len);
	if (c == 'x' || c == 'X')
		ft_puthexa_len(va_arg(args, unsigned int), c, len);
	if (c == '%')
		ft_putchar_len('%', len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_cases(format[i + 1], args, &len);
			i++;
		}
		else
			ft_putchar_len(format[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
