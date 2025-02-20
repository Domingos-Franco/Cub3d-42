/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <dgermano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:29:10 by dgermano          #+#    #+#             */
/*   Updated: 2024/05/21 11:29:12 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*total;

	if (size != 0 && nmemb > (size_t) - 1 / size)
		return (NULL);
	total = malloc(nmemb * size);
	if (total == NULL)
		return (NULL);
	ft_memset(total, 0, (nmemb * size));
	return (total);
}
