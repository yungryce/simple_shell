#include "main.h"



/**
  * _getenv - Searches env string pointed to by arg
 * @cmd_info: shell data structure
  * @path_prefix: The arg of the env
  * Return: Pointer to the env arg
  *		NULL if env does not exist
  */
char *_getenv(CommandInfo *cmd_info, char *path_prefix)
{
	char *env_value;
	int len = _strlen(path_prefix);
	char **env = cmd_info->env;

	while (env != NULL)
	{
		if (_strncmp(path_prefix, *env, len) == 0)
		{
			env_value = *env + len;
			return (env_value + 1);
		}
		env++;
	}
	return (NULL);
}


/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 * @new_var_len: allocation size
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value, size_t new_var_len)
{
	char *new;

	new = malloc(sizeof(char) * new_var_len);
	if (!new)
		return (NULL);
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);

	return (new);
}


/**
 * free_env - Frees the the environment copy.
 * @cmd_info: argument vector
 * Return: void
 */
void free_env(CommandInfo *cmd_info)
{
	int i;

	for (i = 0; cmd_info->env[i]; i++)
		free(cmd_info->env[i]);
	free(cmd_info->env);
}

