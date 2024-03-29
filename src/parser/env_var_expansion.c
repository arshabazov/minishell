/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdell <cdell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:49:22 by cdell             #+#    #+#             */
/*   Updated: 2022/08/19 17:44:57 by cdell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*lookup_env_var_val(const char *start, const char *end)
{
	t_list		*env_var_list;
	t_env_var	*env_var_node;
	size_t		length;
	char		*str;

	env_var_list = g_env_var;
	str = NULL;
	length = ft_substr_len(start, end);
	while (env_var_list)
	{
		env_var_node = (t_env_var *)env_var_list->content;
		if (strncmp(start, env_var_node->key, length) == 0)
		{
			str = ft_strdup(env_var_node->value);
			break ;
		}
		env_var_list = env_var_list->next;
	}
	return (str);
}

char	*substitute_env_var_val(const char *start, const char *end)
{
	char	*str;

	str = lookup_env_var_val(start, end);
	return (str);
}
