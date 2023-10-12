#include "main.h"


/**
 * get_error - calls the error according the builtin, syntax or permission
 * @cmd_info: shell data structure
 * @err_num: error value
 * Return: error
 */
int get_error(CommandInfo *cmd_info, int err_num)
{
	char *error, *msg;

	switch (err_num)
	{
	case -1:
		msg = ": Unable to add/remove from environment\n";
		error = error_gen(cmd_info, msg);
		break;
	case 126:
		if (!is_directory(cmd_info->args[0]))
			msg = ": Permission denied\n";
		else
			msg = ": Is a directory\n";
		error = error_gen(cmd_info, msg);
		break;
	case 127:
		if (access(cmd_info->command, F_OK) != 0)
			msg = ": No such file or directory\n";
		else
			msg = ": Command not found\n";
		error = error_gen(cmd_info, msg);
		break;
	case 2:
		if (_strcmp("exit", cmd_info->args[0]) == 0)
			error = error_exit(cmd_info);
		else if (_strcmp("cd", cmd_info->args[0]) == 0)
			error = error_cd(cmd_info);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
		return (err_num);
	}

	return (0);
}


/**
 * error_gen - generate error message
 * @cmd_info: shell data structure
 * @msg: message tp print
 *
 * Return: error message.
 */

char *error_gen(CommandInfo *cmd_info, char *msg)
{
	int len;
	char *error, *num_str;
	char *name = cmd_info->av[0];
	char *command = cmd_info->args[0];

	num_str = _itoa(cmd_info->count);
	if (!num_str)
		return (NULL);

	len = _strlen(name) + _strlen(num_str) + _strlen(command) + _strlen(msg) + 9;

	error = malloc(sizeof(char) * len);
	if (!error)
	{
		free(num_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": line ");
	_strcat(error, num_str);
	_strcat(error, ": ");
	_strcat(error, command);
	_strcat(error, msg);
	_strcat(error, "\0");

	free(num_str);

	return (error);
}


/**
 * error_exit - generic error message for exit in get_exit
 * @cmd_info: shell data structure
 *
 * Return: Error message
 */
char *error_exit(CommandInfo *cmd_info)
{
	int len;
	char *error, *num_str, *msg;
	char *name = cmd_info->av[0];
	char *command = cmd_info->args[0];
	char *handle = cmd_info->args[1];

	msg = ": Illegal number: ";

	num_str = _itoa(cmd_info->count);
	if (!num_str)
		return (NULL);

	len = _strlen(name) + _strlen(num_str) + _strlen(command);
	len += _strlen(msg) + _strlen(handle) + 5;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(num_str);
		return (NULL);
	}
	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, num_str);
	_strcat(error, ": ");
	_strcat(error, command);
	_strcat(error, msg);
	_strcat(error, handle);
	_strcat(error, "\n\0");
	free(num_str);

	return (error);
}


/**
 * error_cd - error message for cd command in get_cd
 * @cmd_info: data relevant (directory)
 * Return: Error message
 */
char *error_cd(CommandInfo *cmd_info)
{
	int len, len_id;
	char *error, *num_str, *msg;
	char *name = cmd_info->av[0];
	char *command = cmd_info->args[0];
	char *handle = cmd_info->args[1];


	num_str = _itoa(cmd_info->count);
	if (*handle == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(handle);
	}

	len = _strlen(name) + _strlen(command);
	len += _strlen(num_str) + _strlen(msg) + len_id + 5;

	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(num_str);
		return (NULL);
	}

	error = concat_cd(cmd_info, msg, error, num_str);

	free(num_str);

	return (error);
}


/**
 * concat_cd - function that concatenates the message for cd error
 *
 * @cmd_info: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @num_str: counter lines
 * Return: error message
 */
char *concat_cd(CommandInfo *cmd_info, char *msg, char *error, char *num_str)
{
	char *illegal_flag;
	char *name = cmd_info->av[0];
	char *command = cmd_info->args[0];
	char *handle = cmd_info->args[1];

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, num_str);
	_strcat(error, ": ");
	_strcat(error, command);
	_strcat(error, msg);
	if (*handle == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = *(handle + 1);
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, handle);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

