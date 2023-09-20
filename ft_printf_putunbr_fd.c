/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putunbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:28:13 by aarranz-          #+#    #+#             */
/*   Updated: 2023/09/20 14:48:01 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	num;

	if (n >= 10)
	{
		ft_printf_putunbr_fd(n / 10, fd);
		ft_printf_putunbr_fd(n % 10, fd);
	}
	else
	{
		num = n + 48;
		write(fd, &num, 1);
	}
}
