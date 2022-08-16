/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Abdu-Rashid <Abdu-Rashid@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:14:51 by cdell             #+#    #+#             */
/*   Updated: 2022/07/30 22:46:11 by Abdu-Rashid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_cmd_list t_cmd_list;

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
	void	*key;
	void	*value;
	struct s_sl_list	*next;
}	t_sl_list;

typedef struct s_env_var
{
	char	*key;
	char	*value;
}	t_env_var;

t_list	*env_var;

// Utils
void	ft_puterror(char *msg);
size_t	ft_substr_len(const char *start, const char *end);
//int		is_redirect(size_t key);
int		is_redirect(int key);

// Singly linked list operations
void	lst_append_node(t_sl_list **list, void *key, void *value);
void	lst_clear(t_sl_list **list);

// Env var setup
//t_sl_list	*get_env_var(char *env[]);
t_list	*get_env_var(char *env[]);
void	append_env_var(t_list **env_var_list, char *key, char *value);
void	clear_env_var(t_env_var *env_var_node);

// Lexer
t_list	*get_token_list(char *line);

// Parser
//t_cmd_list	*parse_input(t_list **token_list);
t_cmd_list	*parse_input(char *line);
void	clear_cmd_list(t_cmd_list **list);

#endif //MINISHELL_H
