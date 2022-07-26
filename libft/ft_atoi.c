/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:55:49 by adouay            #+#    #+#             */
/*   Updated: 2022/10/13 18:01:06 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int			sign;
	long int	res;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
	nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			sign = -sign;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
	}
	if ((sign * res) <= INT_MAX && (sign * res) >= INT_MIN)
		return (sign * res);
	else
		return (LONG_MAX);
}
/*
int main()
{
    char *str = "   \t\n\r\v\f  -y1479 248\t2y3 12";
    printf("%d\n", atoi(str));
    printf("%d\n", ft_atoi(str));
    return (0);
}
*/
