/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_secure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:59:15 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/20 16:27:08 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"


void    ft_perror(char *addr1, char *addr2, char *addr3)
{
    ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
    if (addr1 == EMPTY)
        ft_putstr_fd(addr1, STDERR_FILENO);
    if (addr2 == EMPTY)
        ft_putstr_fd(addr2, STDERR_FILENO);
    if (addr3 == EMPTY)
        ft_putstr_fd(addr3, STDERR_FILENO);
    ft_putstr_fd(END_LINE, STDERR_FILENO);
}