#include "shell.h"

void _check_path(char **tokens, char *filename, int counter)
{
        pid_t pid;
        int status;
        
        pid = fork();
        switch (pid)
        {
        case 0:
                execve(tokens[0], tokens, environ);
                exit(EXIT_SUCCESS);
                break;
        case -1:
                _print_error(filename, tokens[0], counter);
                break;
        default :
                wait(&status);
                break;
        }
}