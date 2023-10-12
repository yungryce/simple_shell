#ifndef MAIN_H
#define MAIN_H

#define PROMPT "==> "
#define BUF_SIZE 1024
#define EXIT_LOOP -2

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <sys/types.h>



/**********      Global Environment      **********/
extern char **environ;


/**
 * struct CommandData - struct that contains all relevant data on runtime
 * @av: program arguments
 * @env: environment variable
 * @line: line input
 * @command: command to execute. parsed args[0]
 * @args: tokenized arguments
 * @status: shell status
 * @count: Process count
 */
typedef struct CommandData
{
	char **av;
	char **env;
	char *line;
	char *command;
	char **args;
	int status;
	int count;
} CommandInfo;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;


/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(CommandInfo *cmd_info);
} builtin_t;



/**********              MAIN           ***********/
int main(int ac, char **argv);
int set_data(CommandInfo *cmd_info);
int readline(CommandInfo *cmd_info);
int tokenizer(CommandInfo *cmd_info);
int run_args(CommandInfo *cmd_info);
int execute(CommandInfo *cmd_info);
void clean_up(CommandInfo *cmd_info);


/**********           List Handlers          **********/
int parser(CommandInfo *cmd_info);
list_t *create_path_list(CommandInfo *cmd_info, char *path_name);
list_t *create_dot_list(CommandInfo *cmd_info, char *path_name);
list_t *create_slash_list(CommandInfo *cmd_info);
list_t *find_executable_path(list_t *head);


/*********              Linked List             *********/
list_t *add_node_end(list_t *head, char *directory);
size_t print_list(list_t *h);
void free_list(list_t *head);


/*********        Builtins Functions          **********/
int (*get_builtin(char *command))(CommandInfo *);
int cd_builtin(CommandInfo *cmd_info);
int builtin_help(CommandInfo *cmd_info);
int builtin_exit(CommandInfo *cmd_info);


/* Builtin Env */
int print_env(CommandInfo *cmd_info);
int set_env(CommandInfo *cmd_info);
int unset_env(CommandInfo *cmd_info);
int setenv_c(CommandInfo *cmd_info, char *name, char *value);

/* Builtin CD*/
int cd_home(CommandInfo *cmd_info);
int cd_dot(CommandInfo *cmd_info);
int cd_to(CommandInfo *cmd_info);
int cd_subdir(CommandInfo *cmd_info);
int cd_switch(CommandInfo *cmd_info);
char *get_parent_directory(char *current_dir);

/* Builtin Help */
void help_unsetenv(void);
void help_setenv(void);
void help_env(void);
void help_gen(void);
void help_cd(void);
void help_help(void);
void help_exit(void);

/*********              env helpers              **********/
char *_getenv(CommandInfo *cmd_info, char *path_prefix);
char *copy_info(char *name, char *value, size_t new_var_len);
void free_env(CommandInfo *cmd_info);


/*********             Signal Handlers            **********/
void handle_SIGINT(int sig);


/**********              Errors                 **********/
int get_error(CommandInfo *cmd_info, int err_num);
char *error_exit(CommandInfo *cmd_info);
char *error_gen(CommandInfo *cmd_info, char *msg);
char *error_cd(CommandInfo *cmd_info);
char *concat_cd(CommandInfo *cmd_info, char *msg, char *error, char *num_str);


/*********               Helpers                **********/
char *_strtok(char *str, char *delim);
/* char *_realloc(char *ptr, size_t src, size_t dest); */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, size_t src, size_t dest);
int is_delimiter(char c, char *delim);
size_t token_delim_count(char *str, char *delim);
int cmp_chars(char str[], const char *delim);
int token_count(char **tokens);
int _atoi(char *s);
char *_itoa(int n);
int _isdigit(const char *s);
void _puts(char *str);
void _pute(char *str);
void _putchar(char c);
void print_args(char **args);
int _isspace(int c);
int is_whitespace(const char *str);


/**********      string handling functions       **********/
char *_strdup(char *str);
int _strlen(const char *s);
char *_strncpy(char *dest, char *src, size_t n);
char *_strchr(char *s, char c);
int cmp_chars(char str[], const char *delim);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, const char *src);
char *_strncpy(char *dest, char *src, size_t n);
char *_strcpy(char *dest, char *src);
char *_strrchr(char *s, int c);

/**     _getline      */
ssize_t init_buffer(char **lineptr, size_t *n);
ssize_t resize_buffer(char **lineptr, size_t *n, size_t new_size);
ssize_t process_input(char *buf, size_t pos, ssize_t bytes_read);
ssize_t _getline(char **lineptr, size_t *n, int fd);


void is_dot(CommandInfo *cmd_info);
void is_rel_path(CommandInfo *cmd_info);
void interactive(CommandInfo *cmd_info);
int parse_args(CommandInfo *cmd_info, int ac, char **av);
void non_interactive(CommandInfo *cmd_info);
int is_directory(const char *path);
void increment_shlvl(CommandInfo *cmd_info);

#endif /* MAIN_H */
