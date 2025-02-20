/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <dgermano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:32:22 by dgermano          #+#    #+#             */
/*   Updated: 2024/05/21 11:32:23 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long n)
{
	int	strlen;

	strlen = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		strlen++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		strlen++;
	}
	return (strlen);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	if (nbr == 0)
	{
		*(str + 0) = '0';
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		*(str + 0) = '-';
	}
	while (nbr > 0)
	{
		*(str + len--) = (48 + (nbr % 10));
		nbr /= 10;
	}
	return (str);
}

/*int	main(void)
{
	int	n = -12-3;
	printf("%s\n", ft_itoa(n));
}*/