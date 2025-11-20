/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-all <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:01:03 by oait-all          #+#    #+#             */
/*   Updated: 2025/11/18 12:09:31 by oait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	hex(unsigned long nb)
{
	int		count;
	char	*hex;
	int		fill_hex[17];
	int		i;

	count = 0;
	hex = "0123456789abcdef";
	i = 0;
	while (nb)
	{
		fill_hex[i] = nb % 16;
		nb = nb / 16;
		count++;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &hex[fill_hex[i] % 16], 1);
	}
	return (count);
}

int	print_address(unsigned long nb)
{
	int	i;

	if (nb == 0)
	{
		i = write(1, "(nil)", 5);
		return (i);
	}
	i = write(1, "0x", 2);
	return (hex(nb) + i);
}
