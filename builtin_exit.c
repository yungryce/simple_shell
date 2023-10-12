#include "main.h"


/**
 * builtin_exit - Exit the shell.
 * @cmd_info: shell data structure
 * Return: Nothing.
 */

int builtin_exit(CommandInfo *cmd_info)
{
	char *h;
	int status;

	if (cmd_info->args[1])
	{
		h = _strdup(cmd_info->args[1]);
		status = _atoi(h);
		if (status == 0)
			return (2);
		cmd_info->status = (status + 256) % 256;
		free(h);
	}
	else
		cmd_info->status = 0;

	return (EXIT_LOOP);
}
