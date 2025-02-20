/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <dgermano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:38:29 by dgermano          #+#    #+#             */
/*   Updated: 2024/05/21 11:38:30 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*newstr;

	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	i = -1;
	j = -1;
	if (newstr == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		newstr[i] = s1[i];
	while (s2[++j] != '\0')
		newstr[i++] = s2[j];
	newstr[i] = '\0';
	return (newstr);
}
