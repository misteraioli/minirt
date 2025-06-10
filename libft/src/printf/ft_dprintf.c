/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:22:38 by niperez           #+#    #+#             */
/*   Updated: 2025/04/22 14:30:52 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dprint_char(int fd, char c, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	dprint_str(int fd, char *str, int *count)
{
	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		dprint_char(fd, *str, count);
		str++;
	}
}

static int	is_in(int c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static void	dprint_args(int fd, int c, va_list *args, int *count)
{
	if (c == 'c')
		dprint_char(fd, va_arg(*args, int), count);
	else if (c == 's')
		dprint_str(fd, va_arg(*args, char *), count);
	else if (c == 'p')
		dprint_pointer(fd, va_arg(*args, unsigned long long), count);
	else if (c == 'd' || c == 'i')
		dprint_integer(fd, va_arg(*args, int), count);
	else if (c == 'u')
		dprint_unsigned_int(fd, va_arg(*args, unsigned int), count);
	else if (c == 'x')
		dprint_hex(fd, va_arg(*args, unsigned int), 0, count);
	else if (c == 'X')
		dprint_hex(fd, va_arg(*args, unsigned int), 1, count);
	else if (c == '%')
		dprint_char(fd, '%', count);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str != '%')
			dprint_char(fd, *str, &count);
		else
		{
			str++;
			if (is_in(*str, "cspdiuxX%"))
				dprint_args(fd, *str, &args, &count);
			else
				return (va_end(args), -1);
		}
		str++;
	}
	va_end(args);
	return (count);
}
