#include "main.h"


/**
 * non_interactive - Non-interactive mode handler.
 * @data: Struct containing shell's state data.
 * @ac: number of command line arguments supplied.
 * @av: array of command line arrgument strings
 *
 * Return: 0 (Success)
 */
int non_interactive(CommandInfo *cmd_info, int ac, char **av)
{
	int pl;

	if (parse_args(cmd_info, ac, av))
	{
		clean_up(cmd_info);
		return (1);
	}
	pl = run_args(cmd_info);
	if (pl)
	{
		cmd_info->status = get_error(cmd_info, pl);
		return (1);
	}
	clean_up(cmd_info);

	return (0);
}



/**
 * parse_args - parses program arguments to shell commands
 * @data: a pointer to the struct of data
 * @ac: number of arguments passed to program
 * @av: null terminated array of argument strings
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int parse_args(CommandInfo *cmd_info, int ac, char **av)
{
	size_t size = ac + 1, i = 0, j;
	char **temp;

	cmd_info->args = malloc(size * sizeof(char *));
	temp  = malloc(size * sizeof(char *));
	if (!cmd_info->args || !temp)
		return (1);

	while (av[i])
	{
		temp[i] =  av[i];
		i++;
	}
	temp[i] = NULL;

	for (i = 0, j = 1; temp[j]; i++, j++)
		cmd_info->args[i] = temp[j];
	cmd_info->args[i] = NULL;

	free(temp);

	return (0);
}