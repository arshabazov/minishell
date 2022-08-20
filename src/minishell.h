/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdell <cdell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:14:51 by cdell             #+#    #+#             */
/*   Updated: 2022/08/19 16:31:09 by cdell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "lexer/lexer.h"

# define SYTAX_ERR "syntax error near unexpected token"
# define INVALID_ARG_FOR_UNSET "not a valid identifier"
# define NOT_SET "not set"
# define ERR_CMD_NOT_FOUND "command not found"
# define MEM_ERR "memory allocation error"

typedef struct s_cmd_list	t_cmd_list;
t_list						*g_env_var;
t_error						*err_str;

//typedef enum s_error_code
//{
//	NO_ERROR = 0,
//	SYNTAX_ERROR = 258
//}	t_error_code;
//
//typedef struct s_error
//{
//	t_error_code	code;
//	char			*msg;
//}	t_error;

typedef struct s_error
{
	char	*code;
	char	*token;
	int		exit;
	int		exit_status;
}	t_error;

typedef struct s_sl_list
{
	void				*key;
	void				*value;
	struct s_sl_list	*next;
}	t_sl_list;

//typedef enum e_result_type
//{
//	ERROR,
//	SUCCES
//}	t_result_type;
//
//typedef struct s_error
//{
//	int		error_no;
//	char	*msg;
//}	t_error;
//
//typedef struct s_result
//{
//	t_result_type	type;
//	void			*result;
//}	t_result;
//
typedef struct s_env_var
{
	char	*key;
	char	*value;
}	t_env_var;

// Utils
void		ft_puterror(char *msg);
size_t		ft_substr_len(const char *start, const char *end);
int			is_redirect(int key);
//void		print_error(int code, char *msg);
int			print_error(void);
int			init_err(char *code, char *token, int exit, int exit_status);

// Singly linked list operations
void		lst_append_node(t_sl_list **list, void *key, void *value);
void		lst_clear(t_sl_list **list);

// Env var setup
//t_sl_list	*get_env_var(char *env[]);
t_list		*get_env_var(char *env[]);
void		append_env_var(t_list **env_var_list, char *key, char *value);
//void		clear_env_var(t_env_var *env_var_node);

// Lexer
t_list		*get_token_list(char *line);

// Parser
void		clear_cmd_list(t_cmd_list **list);
t_cmd_list	*parse_input(char *line);

// Printing
void		print_cmd_list(t_cmd_list *cmd_list);

#endif //MINISHELL_H
