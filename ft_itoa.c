/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstupar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:43:37 by fstupar           #+#    #+#             */
/*   Updated: 2021/11/04 12:19:59 by fstupar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	g;

	g = 1;
	while (n >= 10)
	{
		n = n / 10;
		g++;
	}
	return (g);
}

static char	*function(char *number, int n, int g)
{
	int	f;

	f = numlen(n);
	number[f] = '\0';
	if (g == 0)
		f--;
	while (n >= 10)
	{
		number[f] = (n % 10) + '0';
		f--;
		n = n / 10;
	}
	number[f] = n + '0';
	if (g == 1)
		number[0] = '-';
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		g;
	int		i;

	i = 1;
	g = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		g = 1;
		i = 2;
	}
	number = (char *)malloc(sizeof(char) * numlen(n) + i);
	if (number == NULL)
		return (NULL);
	number = function(number, n, g);
	return (number);
}
/*
int main()
{
	printf("%s\n", ft_itoa(42));
}*/
