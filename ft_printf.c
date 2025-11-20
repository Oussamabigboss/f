/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-all <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:15:16 by oait-all          #+#    #+#             */
/*   Updated: 2025/11/20 09:39:46 by oait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	check(char str)
{
	char		*s;
	int		i;

	s = "cspdiuxX%";
	i = 0 ;
	while (s[i])
	{
			if (str == s[i])
				return (1);
		i++;
	}
	return (0);
}

static int	handle_format(char c, va_list args)
{

	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_str(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (print_nbr(va_arg(args, int)));
	else if (c == '%')
		return (print_char('%'));
	else if (c == 'p')
		return (print_address(va_arg(args, unsigned long)));
	else if (c == 'u')
		return (print_unsigned_int(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_lower_hexa(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (print_upper_hexa(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *types, ...)
{
	va_list	args;
	int		count;

	if (types == NULL)
		return (-1);
	va_start(args, types);
	count = 0;
	while (*types)
	{
		if (*types == '%' && *(types + 1))
		{
            		if (check(*(types + 1)))
						count += handle_format(*(++types), args);
					else
						return (-1);
		}
		else if (*types == '%' &&  *(types + 1) == '\0')
			return (-1) ;
		else
			count += print_char(*types);
		types++;
	}
	va_end(args);
	return (count);
}

int main ()
{
	// int n = 10;
	// int ft = ft_printf("%  ");
	// printf("\n");
	// int or = printf("hello %  ");
	char *n = NULL ;
	int ft = ft_printf("hello %d %i %s %x %X %u  \n",0, 0 , n, 0, 0, 0);
	int or = printf("hello %d %i %s %x %X %u  \n",0, 0 , n, 0, 0, 0);
	printf("\n");
	printf("ft ==> %d\n" , ft  );
	printf("or ==> %d\n" , or  );



	// va_list args;
	  
	// printf("%d" , args ->fp_offset);
	// va_start(args , )
}