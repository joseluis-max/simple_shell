#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
extern char **environ;
/**
 * struct noBuiltIn - command no built in
 * @command: name of command
 * @command_function: function for to execute.
 */
typedef struct noBuiltIn
{
	char *command;
	void (*command_function)(void);

} t_noBuiltIn;
char *_getenv(char *var_env);
char **split_string(char *buffer, const char *del);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void _env(void);
void _exit_(void);
char *_strdup(char *str);
int _built_in(char **tokens, char *filename, int counter);
int _execute(char *new_path, char *filename, char **tokens, int counter);
int _execute_nb(char **tokens, char *buffer);
void _dot(void);
size_t _strlen(char *s);
void _print_error(char *filename, char *command, int counter);
void _check_path(char **tokens, char *filename, int counter);

#endif
