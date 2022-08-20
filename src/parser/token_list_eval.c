/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_eval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdell <cdell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:13:42 by cdell             #+#    #+#             */
/*   Updated: 2022/08/19 17:39:18 by cdell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_error_message(int key)
{
	if (key == 0)
		printf("maxishell: syntax error near unexpected token \'newline\'\n");
	else if (key == REDIRECT_IN)
		printf("maxishell: syntax error near unexpected token \'<\'\n");
	else if (key == REDIRECT_OUT)
		printf("maxishell: syntax error near unexpected token \'>\'\n");
	else if (key == REDIRECT_APPEND)
		printf("maxishell: syntax error near unexpected token \'>>\'\n");
	else if (key == REDIRECT_HEREDOC)
		printf("maxishell: syntax error near unexpected token \'<<\'\n");
	else if (key == PIPE)
		printf("maxishell: syntax error near unexpected token \'|\'\n");
}

static char	*get_error_msg(int key)
{
	if (key == 0)
		return (NEWLINE_STR);
	else if (key == REDIRECT_IN)
		return (REDIRECT_IN_STR);
	else if (key == REDIRECT_OUT)
		return (REDIRECT_OUT_STR);
	else if (key == REDIRECT_APPEND)
		return (REDIRECT_APPEND_STR);
	else if (key == REDIRECT_HEREDOC)
		return (REDIRECT_HEREDOC_STR);
	else if (key == PIPE)
		return (PIPE_STR);
}

//static void	evaluate_redirect(t_list *token_list)
//{
//	if (!token_list)
//		return ;
//	while (token_list)
//	{
//		if (is_redirect(get_token_node_key(token_list)))
//		{
//			if (!token_list->next)
//			{
//				printf("maxishell: syntax error near unexpected token \'newline\'\n");
//				exit(1);
//			}
//			if (get_token_node_key(token_list->next) != WORD)
//			{
//				print_error_message(get_token_node_key(token_list->next));
//				exit(1);
//			}
//		}
//		token_list = token_list->next;
//	}
//}
//
//static void	evaluate_pipes(t_list *token_list)
//{
//	if (!token_list)
//		return ;
//	if (get_token_node_key(token_list) == PIPE)
//	{
//		printf("bash: syntax error near unexpected token \'|\'\n");
//		exit(1);
//	}
//	while (token_list->next)
//	{
//		if (get_token_node_key(token_list) == PIPE
//			&& get_token_node_key(token_list->next) == PIPE)
//		{
//			printf("bash: syntax error near unexpected token \'|\'\n");
//			exit(1);
//		}
//		token_list = token_list->next;
//	}
//	if (get_token_node_key(token_list) == PIPE)
//	{
//		printf("bash: syntax error near unexpected token \'|\'\n");
//		exit(1);
//	}
//}
//
//void	evaluate_token_list(t_list *token_list)
//{
//	evaluate_pipes(token_list);
//	evaluate_redirect(token_list);
//}

static int	evaluate_redirect(t_list *token_list)
{
	while (token_list)
	{
		if (is_redirect(get_token_node_key(token_list)))
		{
			if (!token_list->next)
			{
				init_err( SYTAX_ERR, NEWLINE_STR, 0, 258);
				return (ERROR);
			}
			if (get_token_node_key(token_list->next) != WORD)
			{
				init_err( SYTAX_ERR, get_error_msg(
						get_token_node_key(token_list->next)), 0, 258);
				return (ERROR);
			}
		}
		token_list = token_list->next;
	}
	return (SUCCESS);
}

static int	evaluate_pipes(t_list *token_list)
{
	if (get_token_node_key(token_list) == PIPE)
	{
		init_err( SYTAX_ERR, PIPE_STR, 0, 258);
		return (ERROR);
	}
	while (token_list->next)
	{
		if (get_token_node_key(token_list) == PIPE
			&& get_token_node_key(token_list->next) == PIPE)
		{
			init_err( SYTAX_ERR, PIPE_STR, 0, 258);
			return (ERROR);
		}
		token_list = token_list->next;
	}
	if (get_token_node_key(token_list) == PIPE)
	{
		init_err( SYTAX_ERR, PIPE_STR, 0, 258);
		return (ERROR);
	}
	return (SUCCESS);
}

int	evaluate_token_list(t_list *token_list)
{
	if (!evaluate_pipes(token_list) || evaluate_redirect(token_list))
		return (ERROR);
	return (SUCCESS);
}
