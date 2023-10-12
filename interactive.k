#include "main.h"

/**
 * interactive - interactive shell
 * @cmd_info: data struct containing shell's state data
 * @av: array of comman line argument strings
 *
 * Return:
 */
void interactive(CommandInfo *cmd_info)
{
	int ret;

	do {
		++(cmd_info->count);
		if (readline(cmd_info))
			continue;

		if (tokenizer(cmd_info))
		{
			_pute("Memory allocation error\n");
			continue;
		}

		ret = run_args(cmd_info);
		if (ret && ret != EXIT_LOOP)
			cmd_info->status = get_error(cmd_info, ret);

		clean_up(cmd_info);

	} while (ret != EXIT_LOOP);

	clean_up(cmd_info);
}

