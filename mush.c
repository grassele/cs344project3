#include <stdio.h>  // for printf(), fgets(), perror()
#include <stdlib.h>  // for exit()
#include <string.h>  // strtok(), strcmp()
#include <unistd.h>  // for fork(), execvp()
#include <sys/wait.h>  // for wait()

// clang -Wall -Wextra mush.c

int main(void)
{
    for (int i = 0; ; i++) {  
        printf("mush$ ");
        fflush(stdout);
        char com_line[2048];
        fgets(com_line, 2048, stdin);

        char *args[1024];
        int i = 0;
        char *tok;
        if ((tok = strtok(com_line, " \t\n\r")) != NULL) {
            do {
                args[i] = tok;
                i++;
            } while ((tok = strtok(NULL, " \t\n\r")) != NULL);
            args[i] = NULL;
        }
        else { 
            printf("not a command\n");
        }

        if (!strcmp(args[0], "cd")) {
            int i = chdir(args[1]);
            if (i == -1) {
                perror("chdir");
            }
        }
        else if (!strcmp(args[0], "exit")) {
            exit(0);
        }
        else {
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                perror("exec");
                exit(1);
            } else {
                wait(NULL);
            }
        }

    }

}

// verify args array contains what it's supposed to
    // printf("number of arguments = %d\n", i+1);
    // for (int j = 0; j <= i; j++) {
    //     printf("arg %d: %s\n", j, args[j]);
    // }
