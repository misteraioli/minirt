/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:12:32 by niperez           #+#    #+#             */
/*   Updated: 2025/04/22 15:04:40 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dprint_pointer(int fd, unsigned long long ptr, int *count)
{
	if (!ptr)
		dprint_str(fd, "(nil)", count);
	else
	{
		dprint_str(fd, "0x", count);
		dprint_number(fd, ptr, "0123456789abcdef", count);
	}
}

void	dprint_integer(int fd, int n, int *count)
{
	if (n < 0)
	{
		dprint_char(fd, '-', count);
		dprint_number(fd, (unsigned int)(-n), "0123456789", count);
	}
	else
		dprint_number(fd, (unsigned int)n, "0123456789", count);
}

void	dprint_unsigned_int(int fd, unsigned int n, int *count)
{
	dprint_number(fd, n, "0123456789", count);
}

void	dprint_hex(int fd, unsigned int n, int is_upper_case, int *count)
{
	if (is_upper_case)
		dprint_number(fd, n, "0123456789ABCDEF", count);
	else
		dprint_number(fd, n, "0123456789abcdef", count);
}

void	dprint_number(int fd, unsigned long long n, char *base, int *count)
{
	size_t	size;

	size = 0;
	while (base[size])
		size++;
	if (n < size)
		dprint_char(fd, base[n], count);
	else
	{
		dprint_number(fd, n / size, base, count);
		dprint_char(fd, base[n % size], count);
	}
}
