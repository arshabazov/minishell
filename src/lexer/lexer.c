/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Abdu-Rashid <Abdu-Rashid@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:03:29 by cdell             #+#    #+#             */
/*   Updated: 2022/07/30 21:36:00 by Abdu-Rashid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static char	*get_token_value(size_t token_key, char *start, const char *end)
{
	char	*token_value;

	token_value = NULL;
	if (token_key == SINGLE_QUOTE || token_key == DOUBLE_QUOTE)
		token_value = get_quotes_value(start, *start);
	else if (token_key == EXIT_STATUS)
		token_value = get_exit_status();
	else if (token_key == ENV_VAR)
		token_value = get_env_var_value(start, end);
	else
		token_value = get_word_value(start, end);
	return (token_value);
}

static int	get_token_key(char **line, char **tk_start, char **tk_end)
{
	char	*str;
	int		token;

	str = *line;
	if (tk_start)
		*tk_start = str;
	if (*str == '|' || *str == '(' || *str == ')')
	{
		token = (int) *str;
		str++;
	}
	else if (*str == '<' || *str == '>')
		token = get_redirect_token(&str);
	else if (ft_strchr(WHITE_SPACE_CHARS, *str))
		token = get_space_token(&str);
	else if (*str == '\'' || *str == '"')
		token = get_quote_tk(&str, *str);
	else if (*str == '$')
		token = get_dollar_token(&str);
	else
		token = get_word_token(&str);
	if (tk_end)
		*tk_end = str;
	*line = str;
	return (token);
}

void	build_token_list(char **line, t_list **token_list)
{
	int		token_key;
	char	*token_value;
	char	*t_start;
	char	*t_end;

	while (**line)
	{
		token_value = NULL;
		token_key = get_token_key(line, &t_start, &t_end);
		if (token_key == 0)
		{
			ft_lstclear(token_list, clear_token);
			return ;
		}
		if (token_key == WORD || token_key == ENV_VAR
			|| token_key == SINGLE_QUOTE || token_key == DOUBLE_QUOTE
			|| token_key == EXIT_STATUS)
			token_value = get_token_value(token_key, t_start, t_end);
		append_token(token_list, token_key, token_value);
	}
}

t_list	*get_token_list(char *line)
{
	t_list	*token_list;
	char	*tmp;

	token_list = NULL;
	tmp = ft_strtrim(line, WHITE_SPACE_CHARS);
	free (line);
	if (!tmp)
		ft_puterror("Failed to allocate memory *get_token_list(void)");
	line = tmp;
	build_token_list(&tmp, &token_list);
	free(line);
	return (token_list);
}
