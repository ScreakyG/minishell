/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:40:40 by fbesson           #+#    #+#             */
/*   Updated: 2023/09/13 16:52:13 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_error(int error)
{
	ft_putstr_fd("minishell: ", 2);
	if (error == 2)
			ft_putstr_fd("syntax error: unexpected end of file\n", 2);
	return (0);
}
