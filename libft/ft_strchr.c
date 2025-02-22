/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <dgermano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:20 by dgermano          #+#    #+#             */
/*   Updated: 2024/05/21 11:37:20 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if ((char)s[i] == (char)c)
			return ((char *)(s + i));
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}
