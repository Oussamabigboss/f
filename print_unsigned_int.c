/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-all <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:30:50 by oait-all          #+#    #+#             */
/*   Updated: 2025/11/18 12:31:00 by oait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count_number(unsigned int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	print_unsigned_int(unsigned int nb)
{
	if (nb > 9)
	{
		print_unsigned_int(nb / 10);
	}
	print_char(nb % 10 + '0');
	return (count_number(nb));
}
