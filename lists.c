#include "main.h"

/**
 * create_dot_list - handles execution absolute for path in current directory
 * @path_name: environ PATH variables to search execution path
 * @cmd_info: shell data structure
 *
 * Return: full execution path
 */

list_t *create_dot_list(CommandInfo *cmd_info, char *path_name)
{
	list_t *dirs = NULL;
	char *pwd, *full_path, *path_copy;
	size_t full_path_size;
	char *command = cmd_info->args[0];

	if (!command)
		return (NULL);

	pwd = _getenv(cmd_info, path_name);
	if (!pwd)
		return (NULL);

	path_copy = _strdup(pwd);
	if (!path_copy)
		return (NULL);

	full_path_size = _strlen(path_copy) + _strlen(command);

	full_path = (char *)malloc(full_path_size);
	if (!full_path)
		return (NULL);

	_strcpy(full_path, path_copy);
	_strcat(full_path, command + 1);

	dirs = add_node_end(dirs, full_path);

	free(path_copy);
	free(full_path);

	return (dirs);
}


/**
 * create_path_list - create a list of directories from PATH variable
 * @path_name: environ PATH variables to search execution path
 * @cmd_info: shell data structure
 *
 * Return: list of directories
*/

list_t *create_path_list(CommandInfo *cmd_info, char *path_name)
{
	list_t *dirs = NULL;
	char *path, *path_copy;
	char *token, *new_dir;
	char *command = cmd_info->args[0];

	if (!command)
		return (NULL);

	path = _getenv(cmd_info, path_name);
	if (!path)
		return (NULL);

	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);

	token = _strtok(path_copy, ":");
	while (token)
	{
		new_dir = (char *)malloc(_strlen(token) + _strlen(command) + 2);
		if (!new_dir)
		{
			if (dirs)
				free_list(dirs);
			return (NULL);
		}

		_strcpy(new_dir, token);
		_strcat(new_dir, "/");
		_strcat(new_dir, command);
		dirs = add_node_end(dirs, new_dir);
		free(new_dir);
		token = _strtok(NULL, ":");
	}
	free(path_copy);
	return (dirs);
}




/**
 * create_slash_list - create a list of directories from PATH variable
 * @cmd_info: shell data structure
 *
 * Return: list of directories
*/

list_t *create_slash_list(CommandInfo *cmd_info)
{
	list_t *dirs = NULL;
	size_t path_len;
	char *full_path;
	char *command = cmd_info->args[0];

	if (!command)
		return (NULL);

	path_len = _strlen(command);

	full_path = (char *)malloc(sizeof(char) * (path_len + 1));
	if (!full_path)
		return (NULL);

	_strcpy(full_path, command);

	dirs = add_node_end(dirs, full_path);

	free(full_path);
	return (dirs);
}

