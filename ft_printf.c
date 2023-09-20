/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:38:51 by aarranz-          #+#    #+#             */
/*   Updated: 2023/09/20 14:48:09 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_starting(char c, va_list lst)
{
	if (c == 'c')
		return (ft_printf_char(lst));
	else if (c == 's')
		return (ft_printf_str(lst));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(lst, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_nbr(lst));
	else if (c == 'u')
		return (ft_printf_u_nbr(lst));
	else if (c == 'x')
		return (ft_printf_hex(va_arg(lst, unsigned int), 0));
	else if (c == 'X')
		return (ft_printf_hex(va_arg(lst, unsigned int), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	lst;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_starting(str[i + 1], lst);
			i++;
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(lst);
	return (count);
}
