#include "minishell.h"

int	init_err(char *code, char *token, int exit, int exit_status)
{
	if (code)
		err_str->code = code;
	if (token)
		err_str->token = token;
	if (exit)
		err_str->exit = exit;
	err_str->exit_status = exit_status;
	return (1);
}

int	print_error(void)
{
	if (!err_str->code)
	{
		err_str->exit_status = 0;
		return (0);
	}
	else
	{
		printf("minishell$ %s: %s", err_str->code, err_str->token);
		err_str->code = NULL;
		err_str->token = NULL;
		if (err_str->exit)
		{
			err_str->exit = 0;
			exit(EXIT_FAILURE);
		};
		return (1);
	}
}
