#include "main.h"


/**
 * run_args - executes builtin or command
 * @cmd_info: shell data structure
 *
 * Return: void
*/
int run_args(CommandInfo *cmd_info)
{
	int ret;
	int (*builtin)(CommandInfo *cmd_info);

	if (!cmd_info->args[0])
		_pute("Args[0] missing\n");

	builtin = get_builtin(cmd_info->args[0]);
	if (builtin)
		ret = (builtin(cmd_info));
	else
	{
		parser(cmd_info);
		ret = (execute(cmd_info));
	}
	free(cmd_info->command);
	cmd_info->command = NULL;
	return (ret);
}




/**
 * parser - handles input stream
 * @cmd_info: shell data structure
 * Return: count
 */

int parser(CommandInfo *cmd_info)
{
	char *command = cmd_info->args[0];

	if (command[0] == '.' && command[1] == '/')
		is_dot(cmd_info);

	else if (command[0] ==  '/')
	{
		cmd_info->command = _strdup(command);
		if (!cmd_info->command)
			_pute("Memory allocation error\n");
	}

	else
		is_rel_path(cmd_info);

	return (0);
}


/**
 * get_builtin - checks if the command is a builtin
 * @command: pointer to vector argv
 * Return: function pointer to builtin
 */

int (*get_builtin(char *command))(CommandInfo *)
{
	builtin_t funcs[] = {
		{ "exit", builtin_exit },
		{ "env", print_env },
		{ "setenv", set_env },
		{ "unsetenv", unset_env },
		{ "cd", cd_builtin },
		{ "help", builtin_help },
		{ NULL, NULL },
	};
	int i;

	for (i = 0; funcs[i].name; i++)
	{
		if (_strcmp(funcs[i].name, command) == 0)
			return (funcs[i].f);
	}

	return (NULL);
}


/**
 * is_directory - checks to see if path is a directory
 * @path: path to parse
 * Return: success or fail
*/
int is_directory(const char *path)
{
	struct stat path_stat;

	if (stat(path, &path_stat) == 0)
		return ((S_ISDIR(path_stat.st_mode)) ? 1 : 0);
	return (0);
}
