#include "main.h"

/**
 * is_rel_path - check if the given filenname is short form
 * @cmd_info: the data strucct pointer
 *
 * Return: (Success)
 * ------- (Fail) otherwise
 */
void is_rel_path(CommandInfo *cmd_info)
{
	char *path, *token, *_path, *command;
	struct stat st;
	int flag = 0;

	path = _getenv(cmd_info, "PATH");
	_path = _strdup(path);
	if (!_path)
		_pute("Memory allocation error\n");

	token = _strtok(_path, ":");
	while (token)
	{
		command = malloc(_strlen(token) + _strlen(cmd_info->args[0]) + 2);
		if (!command)
		{
			_pute("Memory allocation error\n");
			break;
		}
		_strcpy(command, token);
		_strcat(command, "/");
		_strcat(command, cmd_info->args[0]);

		if (stat(command, &st) == 0)
		{
			flag = 1;
			break;
		}
		free(command);
		command = NULL;

		token = _strtok(NULL, ":");
	}
	cmd_info->command = command;

	if (flag == 0)
		cmd_info->command = _strdup(cmd_info->args[0]);
	free(_path);
}


/**
 * is_dot - check if the given filenname is short form
 * @cmd_info: the data strucct pointer
 *
 * Return: (Success)
 * ------- (Fail) otherwise
 */
void is_dot(CommandInfo *cmd_info)
{
	char *pwd, *ptr, *new_path;
	size_t len;

	ptr = (cmd_info->args[0]);
	pwd = _getenv(cmd_info, "PWD");
	if (!pwd)
		_pute("Error getting Env PWD\n");

	len = _strlen(pwd) + _strlen(ptr);
	cmd_info->command = new_path = malloc((len) * (sizeof(char)));
	if (!new_path)
		_pute("Memory allocation error\n");

	_strcpy(new_path, pwd);
	_strcat(new_path, ptr + 1);

}
