/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdell <cdell@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:14:51 by cdell             #+#    #+#             */
/*   Updated: 2022/06/11 23:14:59 by cdell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_token t_token;

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "lexer/lexer.h"

typedef struct s_sl_list
{
	void*	key;
	void	*value;
	struct s_sl_list	*next;
}	t_sl_list;

void	lst_append_node(t_sl_list **list, void *key, void *value);
t_sl_list	*get_env_var(char *env[]);

t_sl_list	*get_token_list(void);

void	ft_puterror(char *msg);

#endif //MINISHELL_H
