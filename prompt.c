#include "shell.h"
/**
 * prompt - Function
 *
 * Description: prints "$ ", wait for the user to enter a command.
 * prints it on the next line.
 *
 * Return:
 */
char *prompt(void)
{
    char *buffer;
    size_t bufsize = 32;

    /*allocate memory and check if NULL*/
    buffer = (char * )malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Error:Unable to allocate buffer");
        exit(1);
    }

    printf("$ ");
    getline(&buffer,&bufsize,stdin);
    return(buffer);
}

