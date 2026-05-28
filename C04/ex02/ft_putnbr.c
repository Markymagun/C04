/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparteep <jparteep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:45:22 by jparteep          #+#    #+#             */
/*   Updated: 2026/05/28 20:22:19 by jparteep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char		c;
	long int	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	c = ((n % 10) + '0');
	write(1, &c, 1);
}

// int	main(void)
// {
// 	ft_putnbr(2147483648);
// 	printf("\n");
// }
