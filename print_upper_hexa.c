/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upper_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-all <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:26:17 by oait-all          #+#    #+#             */
/*   Updated: 2025/11/18 12:26:28 by oait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_upper_hexa(unsigned int nb)
{
	int		count;
	char	*hex;
	int		fill_hex[17];
	int		i;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = 0;
	hex = "0123456789ABCDEF";
	i = 0;
	while (nb)
	{
		fill_hex[i] = nb % 16;
		nb = nb / 16;
		i++;
	}
	count = i;
	while (--i >= 0)
	{
		write(1, &hex[fill_hex[i]], 1);
	}
	return (count);
}
