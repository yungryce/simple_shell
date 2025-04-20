#include "main.h"


/**
 * print_env - prints the current environ
 * @cmd_info: Data structure - env
 * Return: void
 */
int print_env(CommandInfo *cmd_info)
{
	int i;

	for (i = 0; cmd_info->env[i]; i++)
	{
		_puts(cmd_info->env[i]);
		_puts("\n");
	}
	cmd_info->status = 0;
	return (0);
}


/**
 * set_env - sets an environment variable
 * @cmd_info: Data structure - env
 *
 * Return: 0 on success, 1 on failure.
 */
int set_env(CommandInfo *cmd_info)
{
	char *name = cmd_info->args[1];
	char *value = cmd_info->args[2];

	if (!name)
		return (-1);

	if (name && value)
		return (setenv_c(cmd_info, name, value));
	else
		return (unset_env(cmd_info));
	return (0);
}


/**
 * setenv_c - Wrapper function for set_env with cmd_info.
 * with the name passed.
 * @cmd_info: Data structure - env
 * @var_key: variable key
 * @var_value: variable value
 * Return: 0 on success, 1 on failure.
 */
int setenv_c(CommandInfo *cmd_info, char *var_key, char *var_value)
{
	int i;
	char *var_env, *name_env, *env_i;
	size_t new_var_len = _strlen(var_key) + _strlen(var_value) + 2;

	for (i = 0; cmd_info->env[i]; i++)
	{
		env_i = cmd_info->env[i];
		var_env = _strdup(env_i);
		if (!var_env)
			_pute("Memory allocation error\n");

		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, var_key) == 0 && env_i[_strlen(var_key)] == '=')
		{
			free(env_i);
			cmd_info->env[i] = copy_info(var_key, var_value, new_var_len);
			if (!cmd_info->env[i])
				_pute("Memory allocation error\n");
			free(var_env);
			return (0);
		}
		free(var_env);
	}
	i = 0;
	while (cmd_info->env[i])
		i++;
	cmd_info->env = _reallocdp(cmd_info->env, i, sizeof(char *) * (i + 2));
	cmd_info->env[i] = copy_info(var_key, var_value, new_var_len);
	if (!cmd_info->env[i])
		_pute("Memory allocation error\n");

	cmd_info->env[i + 1] = NULL;
	cmd_info->status = 0;
	return (0);
}



/**
 * unset_env - deletes a environment variable
 * @cmd_info: Data structure - env
 *
 * Return: 0 on success, 1 on failure.
 */
int unset_env(CommandInfo *cmd_info)
{
	char **new_env;
	char *var_env, *name_env;
	int i, k = -1, j = 0;

	if (!cmd_info->args[1])
		return (-1);
	for (i = 0; cmd_info->env[i]; i++)
	{
		var_env = _strdup(cmd_info->env[i]);
		if (!var_env)
			_pute("Memory allocation error\n");
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, cmd_info->args[1]) == 0)
			k = i;
		free(var_env);
	}
	if (k == -1)
		return (0);

	new_env = malloc(sizeof(char *) * (i));
	if (!new_env)
		_pute("Memory allocation error\n");

	for (i = 0; cmd_info->env[i]; i++)
	{
		if (i != k)
		{
			new_env[j] = cmd_info->env[i];
			j++;
		}
		else
			free(cmd_info->env[i]);
	}

	new_env[j] = NULL;
	free(cmd_info->env);
	cmd_info->env = new_env;
	cmd_info->status = 0;
	return (0);
}



