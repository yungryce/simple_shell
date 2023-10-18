#include "main.h"

/**
 * handle_SIGINT - ctrl-C singnal
 * @sig: Signal number
 * Return: void
 */
void handle_SIGINT(int sig)
{
	(void)sig;
	_puts("\n");
	_puts(PROMPT);

}


/**
 * main - Parent Process of shell
 * @ac: shell argument count
 * @av: shell arguments
 *
 * Return: 0 (exit success)
 */
int main(int ac, char **av)
{
	int ret;
	CommandInfo cmd_info = {NULL, NULL, NULL, NULL, NULL, 0, 0};
	(void) ac;
	cmd_info.av = av;
	if (set_data(&cmd_info))
	{
		free_env(&cmd_info);
		return (get_error(&cmd_info, -1));
	}
	signal(SIGINT, handle_SIGINT);

	do {
		++(cmd_info.count);
		if (readline(&cmd_info) && isatty(STDIN_FILENO))
			continue;

		tokenizer(&cmd_info);
		if (!cmd_info.args)
			break;

		ret = run_args(&cmd_info);
		if (ret && ret != EXIT_LOOP)
		{
			cmd_info.status = get_error(&cmd_info, ret);
			if (isatty(STDIN_FILENO))
			{
				clean_up(&cmd_info);
				continue;
			}
			else
				break;
		}
		clean_up(&cmd_info);

	} while (ret != EXIT_LOOP);

	clean_up(&cmd_info);
	free_env(&cmd_info);
	return (cmd_info.status);
}

/**
 * readline - reads from tty stdin STREAM to a buffer
 * @cmd_info: data structure of shell
 * getline: man 3 getline
 * Return: pointer to buffer
 */

int readline(CommandInfo *cmd_info)
{
	char *input = NULL;
	size_t bufsize = BUF_SIZE;
	int chars_count;

	if (isatty(STDIN_FILENO))
		_puts(PROMPT);

	chars_count = getline(&input, &bufsize, stdin);

	if (chars_count == -1 || is_whitespace(input))
	{
		free(input);
		return (1);
	}
	if (chars_count > 0 && input[chars_count - 1] == '\n')
		input[chars_count - 1] = '\0';

	cmd_info->line = input;

	return (0);
}


/**
 * tokenizer -  tokenizes a string into words (man 3 strtok)
 * @cmd_info: shell cmd_info structure
 *
 * Return: a memory address with pointrs to each word
 */

int tokenizer(CommandInfo *cmd_info)
{
	char *token, *delim = " \n\t\r\a\v";
	char **tokens = NULL;
	size_t idx = 0;

	if (!cmd_info->line || cmd_info->line[0] == '\0')
		return (1);

	token = _strtok(cmd_info->line, delim);
	while (token)
	{
		tokens = _reallocdp(tokens, idx, idx + 1);
		if (!tokens)
			return (1);

		tokens[idx] = _strdup(token);
		if (!tokens[idx])
			return (1);

		idx++;
		token = _strtok(NULL, delim);
	}
	tokens = _reallocdp(tokens, idx, idx + 1);
	if (!tokens)
		return (1);

	tokens[idx] = NULL;
	cmd_info->args = tokens;

	return (0);
}


/**
 * execute - execute absolute path if execve
 * @cmd_info: shell data structure
 *
 * Return: exit status of the executed command
 */

int execute(CommandInfo *cmd_info)
{
	pid_t child_pid;
	int status;

	if (access(cmd_info->command, F_OK) != 0 || is_directory(cmd_info->command))
		return (127); /* File exists */
	if (access(cmd_info->command, X_OK))
		return (126); /* permission denied */


	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(cmd_info->command, cmd_info->args, cmd_info->env) == -1)
			return (127); /* Not found */
	}
	else
		do {
			waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));


	return (0);
}
