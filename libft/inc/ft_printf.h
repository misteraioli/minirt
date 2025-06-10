/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:57:37 by niperez           #+#    #+#             */
/*   Updated: 2025/04/22 14:35:50 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	print_char(char c, int *count);
void	print_str(char *str, int *count);
void	print_pointer(unsigned long long ptr, int *count);
void	print_integer(int n, int *count);
void	print_unsigned_int(unsigned int n, int *count);
void	print_hex(unsigned int n, int is_upper_case, int *count);
void	print_number(unsigned long long n, char *base, int *count);

int		ft_dprintf(int fd, const char *format, ...);
void	dprint_char(int fd, char c, int *count);
void	dprint_str(int fd, char *str, int *count);
void	dprint_pointer(int fd, unsigned long long ptr, int *count);
void	dprint_integer(int fd, int n, int *count);
void	dprint_unsigned_int(int fd, unsigned int n, int *count);
void	dprint_hex(int fd, unsigned int n, int is_upper_case, int *count);
void	dprint_number(int fd, unsigned long long n, char *base, int *count);

#endif
