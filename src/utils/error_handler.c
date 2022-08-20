/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdell <cdell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:50:15 by cdell             #+#    #+#             */
/*   Updated: 2022/08/19 17:50:17 by cdell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//int	print_error(void)
//{
//	if (!err_str->code)
//		return (0);
//	else
//	{
//		printf("minishell$ %s: %s", err_str->code, err_str->token);
//		err_str->code = NULL;
//		err_str->token = NULL;
//		if (err_str->exit)
//		{
//			err_str->exit = 0;
//			exit(EXIT_FAILURE);
//		}
//		return (1);
//	}
//}

//static char	*get_error_msg(int code)
//{
//	char	*msg;
//
//	msg = NULL;
//	if (code == SYNTAX_ERROR)
//		msg = ft_strdup(SYTAX_ERR);
//	return (msg);
//}
//
//void	print_error(int code, char *msg)
//{
//	char	*error_msg;
//
//	error_msg = get_error_msg(code);
//	printf("maxishell: %s %s\n", error_msg, msg);
//	free(error_msg);
//}