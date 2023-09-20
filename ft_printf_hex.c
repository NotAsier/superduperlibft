/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:02:27 by aarranz-          #+#    #+#             */
/*   Updated: 2023/09/20 14:47:54 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_hex(unsigned long n, int up_low_case)
{
	int	i;

	i = 0;
	if (n > 15)
		i += ft_printf_hex (n / 16, up_low_case);
	if (up_low_case == 0)
		i += write (1, &"0123456789abcdef"[(n % 16)], 1);
	if (up_low_case == 1)
		i += write (1, &"0123456789ABCDEF"[(n % 16)], 1);
	return (i);
}
