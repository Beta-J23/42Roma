/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:02:40 by alpelliz          #+#    #+#             */
/*   Updated: 2022/06/07 15:14:56 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		checktype(va_list arg, const char type);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putchar(int c);
char	*if_min(int n);
int		how_long(int n);
int		ft_putstr(char *s);
char	*ft_strcpy(char *dest, char *src);
int		ft_count(unsigned int nb, char type);
int		ft_hex(unsigned int nb, char type);
int		hex_converter(unsigned long long nb, char type);
int		ft_decimal_count(int nb);
int		ft_decimal_count_uns(unsigned int nb);
int		ft_count_p(unsigned long long nb);
void	ft_hex_g(unsigned long long nb);

#endif
