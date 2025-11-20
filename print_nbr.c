/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-all <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:21:37 by oait-all          #+#    #+#             */
/*   Updated: 2025/11/18 12:21:39 by oait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count_number(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	print_nbr(int nb)
{
	int	count;

	if (nb == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	count = count_number(nb);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 9)
		print_nbr(nb / 10);
	print_char(nb % 10 + '0');
	return (count);
}
