/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdell <cdell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:01:56 by cdell             #+#    #+#             */
/*   Updated: 2022/08/19 17:45:36 by cdell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void	print_env_list_(t_list *env_var_list)
//{
//	t_env_var	*node;
//
//	if (!env_var_list)
//	{
//		printf("ENV var list is empty\n");
//		exit(EXIT_FAILURE);
//	}
//	while (env_var_list)
//	{
//		node = (t_env_var *)env_var_list->content;
//		printf("%s=%s\n", node->key, node->value);
//		env_var_list = env_var_list->next;
//	}
//}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd_list	*cmd_list;
	char		*line;

	(void) argc;
	(void) argv;
	g_env_var = get_env_var(envp);
	while (1)
	{
		printf("maxishell$ ");
		line = readline("");
		cmd_list = parse_input(line);
		if (!cmd_list)
		{
			printf("\n");
			continue;
		}
		clear_cmd_list(&cmd_list);
		free(line);
//		break;
	}
	return (0);
}
