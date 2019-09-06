#include "headers.h"


void fore(char **token)
{
    pid_t pid; 

    pid=fork();

    if(pid<0)
        perror("Error: Fork Failed\n");
    else if(pid==0) 
    {
        int f=execvp(token[0],token);
        if(f<0)
        {
            perror("Error: exec failed\n");
            printf("myshell: command not found: %s\n", token[0]);
        }
        exit(0);
    }
    else
    {
        wait(NULL);    
        // while (wait(&status) != pid)       /* wait for completion  */
        //        ;
    }
    
}