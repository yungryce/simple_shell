#include "main.h"


/**
 * cd_builtin - changes current directory
 *
 * @cmd_info: data relevant
 * Return: 1 on success
 */
int cd_builtin(CommandInfo *cmd_info)
{
	char *path, *home;

	path = cmd_info->args[1];
	home = _getenv(cmd_info, "HOME");

	if (path == NULL || _strcmp(path, "~") == 0 || _strcmp(path, "--") == 0)
	{
		if (home)
			return (cd_home(cmd_info));
	}

	if (_strcmp(path, "-") == 0)
		return (cd_switch(cmd_info));

	if (_strcmp(path, ".") == 0 || _strcmp(path, "..") == 0)
		return (cd_dot(cmd_info));

	if (path[0] != '/')
		return (cd_subdir(cmd_info));

	return (cd_to(cmd_info));

	return (0);
}



/**
 * get_parent_directory - goes up one directory
 * @current_dir: current working directory
 * Return: pointer previous dir
*/
char *get_parent_directory(char *current_dir)
{
	char *last_slash, *parent_dir;

	parent_dir = _strdup(current_dir);
	if (parent_dir == NULL)
		return (NULL);

	last_slash = _strrchr(parent_dir, '/');
	if (last_slash == NULL)
	{
		free(parent_dir);
		return (NULL);
	}

	*last_slash = '\0';
	return (parent_dir);
}



