/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 02:27:41 by coder             #+#    #+#             */
/*   Updated: 2022/04/13 08:08:51 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_filter_flags(va_list ap, int flag);
int		ft_putchar_plus(int character);
int		ft_print_character(char c);
int		ft_print_string(char *str);
int		ft_print_pointer(unsigned long address);
int		ft_print_decimal(int number);
int		ft_print_positive_int(int number);
char	*ft_uitoa(unsigned int n);
int		ft_print_hex(unsigned int nbr, int xorX);

#endif
