/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparteep <jparteep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:45:38 by jparteep          #+#    #+#             */
/*   Updated: 2026/05/28 20:22:16 by jparteep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// int	main(void)
// {
// 	char	*c1;
// 	char	*c2;
// 	char	*c3;
// 	char	*c4;
// 	char	*c5;
// 	char	*c6;

// 	c1 = "42";
// 	printf("Case 1: %d\n\n", ft_atoi(c1));
// 	c2 = "-42";
// 	printf("Case 2: %d\n\n", ft_atoi(c2));
// 	c3 = " \t\n \r\v\f  42";
// 	printf("Case 3: %d\n\n", ft_atoi(c3));
// 	c4 = "---+--+1234ab567";
// 	printf("Case 4: %d\n\n", ft_atoi(c4));
// 	c5 = "42Bangkok";
// 	printf("Case 5: %d\n\n", ft_atoi(c5));
// 	c6 = "   ++--  ";
// 	printf("Case 6: %d\n\n", ft_atoi(c6));
// }
