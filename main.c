/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:07:15 by fbesson           #+#    #+#             */
/*   Updated: 2023/08/31 11:09:14 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void) //test libft + printf + makefile
{
	char *result = ft_itoa(42);
	ft_printf("%s\n", result);
	return (0);
}
