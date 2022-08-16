//
// Created by Cristie Dell on 8/4/22.
//

/*
int (*find_builtin(char *name))(char **){
	if (ft_strncmp(“echo”, name, ft_strlen(name) + 1) == 0)
		return &b_echo;
	if (ft_strncmp(“pwd”, name, ft_strlen(name) + 1) == 0)
		return &b_pwd;
	if (ft_strncmp(“env”, name, ft_strlen(name) + 1) == 0)
		return &b_env;
	if (ft_strncmp(“export”, name, ft_strlen(name) + 1) == 0)
		return &b_export;
	if (ft_strncmp(“unset”, name, ft_strlen(name) + 1) == 0)
		return &b_unset;
	return NULL;
}

int   exec_builtin(t_cmd *cmd, int **pipes, int pipe_amount, int cmd_amount){
	int   code;
	int   save_fd;
	int   (*func)(char**);

	code = -42;
	save_fd = -1;

	func = find_builtin(cmd->argv[0]);
	if(func == NULL)
	        return code;

	save_fd = dup(1);
	//pre_exec(cmd, pipes, pipe_amount, cmd_amount);
	handle_redirects(cmd);
	if (pipe_amount > 0)
	        handle_pipes(cmd, pipes, cmd_amount);
	close_pipes(pipes, pipe_amount);

	code = func(cmd->argv);
	if (pipe_amount > 0)
	        exit(1);
	else
	    dup2(save_fd, 1);

	return code;
}
*/
