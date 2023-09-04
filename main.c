/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:30:50 by fgonzale          #+#    #+#             */
/*   Updated: 2023/09/04 16:51:06 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

char    *get_env_path(char **envp)
{
    if (!envp || !*envp)
        return (NULL);
    while (*envp)
    {
        if (ft_strncmp(*envp, "PATH", 4) == 0)
            return (*envp + 5);
        envp++;
    }
    return (NULL);
}

int ft_skip_white_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] == ' ')
        i++;
    return (i);
}

/* void signal_handling(int signal) */
/* { */
    /* (void)signal; */
    /* rl_on_new_line(); */
/* } */

void	signal_cmd(int sig)
{
	g_exit_status += sig;
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		write(2, "Quit (core dumped)\n", ft_strlen("Quit (core dumped)\n"));
		exit (1);
	}
}

int main(int argc, char **argv, char **envp)
{
    char    *env_path;
    char    *input;
	g_exit_status = 0;
    (void)argc;
    (void)argv;
    
    env_path = get_env_path(envp);
    signal(SIGINT, signal_cmd);
    (void)env_path;
    while (1)
    {
        input = readline("$minishell : ");
        if (!*(input + ft_skip_white_spaces(input)))
            continue;
        add_history(input);
        
        //printf("%s\n", input);
        //if (!input || !is_line_empty(input))
        //    continue;
        //printf("Input ok\n");
        
    }
}
