/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:44:56 by fgonzale          #+#    #+#             */
/*   Updated: 2023/09/18 14:20:45 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../includes/minishell.h"

/* SAUTE LES ESPACES DANS UNE STRING ET RENVOIE DE COMBIEN IL A AVANCE */
int ft_skip_white_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'))
        i++;
    return (i);
}

void    stack_add_bottom(t_lexer **head, t_lexer *new)
{
    t_lexer *tmp;

    if (*head == NULL)
        *head = new;
    else
    {
        tmp = *head;
        while (tmp && tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->previous = tmp;
    }
}

t_lexer *new_node(char *input, t_token token)
{
    t_lexer *new;

    new = malloc(sizeof(*new));
    new->next = NULL;
    new->previous = NULL;
    new->token = token;
    new->word = input;
    return (new);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ws(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}
