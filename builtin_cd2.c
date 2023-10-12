#include "main.h"

/**
 * cd_home - changes to home directory
 *
 * @cmd_info: data relevant (environ)
 * Return: error
 */
int cd_home(CommandInfo *cmd_info)
{
	char *old_pwd, *new_pwd, *home;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		_pute("Memory allocation error\n");

	home = _getenv(cmd_info, "HOME");

	if (chdir(home) == -1)
	{
		free(old_pwd);
		return (2);
	}
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		_pute("Memory allocation error\n");

	setenv_c(cmd_info, "OLDPWD", old_pwd);
	setenv_c(cmd_info, "PWD", new_pwd);

	free(old_pwd);
	free(new_pwd);

	cmd_info->status = 0;
	return (0);
}

/**
 * cd_dot - changes to the parent directory
 *
 * @cmd_info: data relevant (environ)
 *
 * Return: error
 */
int cd_dot(CommandInfo *cmd_info)
{
	char *dir = cmd_info->args[1];
	char *old_pwd, *new_pwd;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		_pute("Memory allocation error\n");

	setenv_c(cmd_info, "OLDPWD", old_pwd);

	if (_strcmp(".", dir) == 0)
	{
		setenv_c(cmd_info, "PWD", old_pwd);
		free(old_pwd);
		cmd_info->status = 0;
		return (0);
	}

	new_pwd = get_parent_directory(old_pwd);
	if (!new_pwd)
	{
		free(old_pwd);
		return (0);
	}
	if (chdir(new_pwd) == -1)
	{
		free(old_pwd);
		free(new_pwd);
		return (2);
	}

	setenv_c(cmd_info, "PWD", new_pwd);
	free(old_pwd);
	free(new_pwd);
	cmd_info->status = 0;
	return (0);
}

/**
 * cd_to - changes to a directory given
 * by the user
 *
 * @cmd_info: data relevant (directories)
 * Return: error
 */
int cd_to(CommandInfo *cmd_info)
{
	char *dir = cmd_info->args[1];
	char *old_pwd, *new_dir;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		_pute("Memory allocation error\n");

	if (chdir(dir) == -1)
	{
		free(old_pwd);
		return (2);
	}

	new_dir = getcwd(NULL, 0);
	if (!new_dir)
		_pute("Memory allocation error\n");

	setenv_c(cmd_info, "OLDPWD", old_pwd);
	setenv_c(cmd_info, "PWD", new_dir);
	free(old_pwd);
	free(new_dir);

	cmd_info->status = 0;
	return (0);
}


/**
 * cd_switch - handles cd <->
 * @cmd_info: Data structure of shell
 * Return: error
*/
int cd_switch(CommandInfo *cmd_info)
{
	char *old_pwd, *p_oldpwd, *cp_oldpwd;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		_pute("Memory allocation error\n");

	p_oldpwd = _getenv(cmd_info, "OLDPWD");

	cp_oldpwd = _strdup(p_oldpwd);
	if (!cp_oldpwd)
		_pute("Memory allocation error\n");

	setenv_c(cmd_info, "OLDPWD", old_pwd);
	if (chdir(cp_oldpwd) == -1)
	{
		setenv_c(cmd_info, "PWD", old_pwd);
		free(old_pwd);
		free(cp_oldpwd);
		return (0);
	}

	setenv_c(cmd_info, "PWD", cp_oldpwd);
	free(old_pwd);
	free(cp_oldpwd);
	cmd_info->status = 0;
	return (0);
}


/**
 * cd_subdir - changes to a subdirectory specified by a relative path
 *
 * @cmd_info: data relevant (environ)
 * Return: 0 on success, 1 on failure
 */
int cd_subdir(CommandInfo *cmd_info)
{
	size_t new_len;
	char *old_pwd, *new_dir, *current_dir;
	char *path = cmd_info->args[1];

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		_pute("Memory allocation error\n");

	current_dir = _getenv(cmd_info, "PWD");

	new_len = _strlen(current_dir) + _strlen(path) + 2;
	new_dir = malloc(new_len);
	if (!new_dir)
		_pute("Memory allocation error\n");

	_strcpy(new_dir, current_dir);
	_strcat(new_dir, "/");
	_strcat(new_dir, path);
	if (chdir(new_dir) == -1)
	{
		free(old_pwd);
		free(new_dir);
		return (2);
	}
	setenv_c(cmd_info, "OLDPWD", old_pwd);
	setenv_c(cmd_info, "PWD", new_dir);

	free(old_pwd);
	free(new_dir);

	cmd_info->status = 0;
	return (0);
}
