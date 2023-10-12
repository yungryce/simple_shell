#include "main.h"


/**
 * builtin_help - function that retrieves help messages according builtin
 * @cmd_info: data structure (args and input)
 * Return: Return 0
*/
int builtin_help(CommandInfo *cmd_info)
{
	char *handle = cmd_info->args[1];

	if (handle == 0)
		help_gen();
	else if (_strcmp(handle, "setenv") == 0)
		help_setenv();
	else if (_strcmp(handle, "env") == 0)
		help_env();
	else if (_strcmp(handle, "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(handle, "help") == 0)
		help_help();
	else if (_strcmp(handle, "exit") == 0)
		help_exit();
	else if (_strcmp(handle, "cd") == 0)
		help_cd();
	else
		write(STDERR_FILENO, cmd_info->args[0],
		      _strlen(cmd_info->args[0]));

	cmd_info->status = 0;
	return (0);
}


/**
 * help_gen - Entry point for help information for the help builtin
 * Return: no return
 */
void help_gen(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}


/**
 * help_env - Help information for the builtin env
 * Return: no return
 */
void help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));

}
/**
 * help_setenv - Help information for the builtin setenv
 * Return: no return
 */
void help_setenv(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * help_unsetenv - Help information for the builtin unsetenv
 * Return: no return
 */
void help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
