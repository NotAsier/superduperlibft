/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:37:45 by aarranz-          #+#    #+#             */
/*   Updated: 2023/09/20 14:48:04 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(va_list lst)
{
	char	character;
	int		count;

	character = va_arg(lst, int);
	count = write(1, &character, 1);
	return (count);
}

int	ft_printf_str(va_list lst)
{
	char	*str;

	str = va_arg(lst, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_printf_nbr(va_list lst)
{
	int		nbr;
	int		ret;
	char	*str;

	nbr = va_arg(lst, int);
	str = ft_itoa(nbr);
	ret = write(1, str, ft_strlen(str));
	return (free(str), ret);
}

int	ft_printf_u_nbr(va_list lst)
{
	unsigned int	nbr;
	unsigned int	nb;
	unsigned int	size;

	nbr = va_arg(lst, unsigned int);
	nb = nbr;
	size = 1;
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	ft_printf_putunbr_fd(nbr, 1);
	return (size);
}
