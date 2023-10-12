#include "main.h"


/**
 * set_data - Initialize data structure
 * @cmd_info: shell data structure
 * Return: no return
 */
int set_data(CommandInfo *cmd_info)
{
	unsigned int i;

	for (i = 0; environ[i]; i++)
		;

	cmd_info->env = malloc(sizeof(char *) * (i + 1));
	if (!cmd_info->env)
	{
		_puts("Memory allocation error\n");
		return (1);
	}

	for (i = 0; environ[i]; i++)
	{
		cmd_info->env[i] = _strdup(environ[i]);
		if (!cmd_info->env)
		{
			_puts("Memory allocation error\n");
			return (1);
		}
	}
	increment_shlvl(cmd_info);

	cmd_info->env[i] = NULL;

	return (0);
}


/**
 * increment_shlvl - shlvl incrementer
 * @cmd_info: data structure of shell
 * Return: void
*/
void increment_shlvl(CommandInfo *cmd_info)
{
	char *shlvl_str = _getenv(cmd_info, "SHLVL");
	char *new_shlvl = _strdup(shlvl_str);
	int shlvl = _atoi(new_shlvl);
	char *str;

	shlvl++;
	str = _itoa(shlvl);
	setenv_c(cmd_info, "SHLVL", str);
	free(new_shlvl);
}




/**
 * clean_up - exit call for child process
 * @cmd_info: data stuct for shell
 *
 * Return: exit success
*/
void clean_up(CommandInfo *cmd_info)
{

	/* Free allocated memory for line */
	if (cmd_info->line)
	{
		free(cmd_info->line);
		cmd_info->line = NULL;
	}

	/* Free allocated memory for args */
	if (cmd_info->args)
	{
		free(cmd_info->args);
		cmd_info->args = NULL;
	}

}

