/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:41:36 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/05 13:12:30 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		find_specifier(char c, va_list args);
int		ft_printchar(char c);
int		ft_printstr(const char *str);
int		ft_printaddress(void *ptr);
char	*base10tohexa(unsigned long n);
int		ft_printint(int n);
int		ft_print_hex(unsigned int n, char c);
int		ft_print_uppercase_str(char *str);
int		ft_print_unsigned(unsigned int n);

#endif