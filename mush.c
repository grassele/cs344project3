#include <stdio.h>  // for printf(), fgets(), perror()
#include <stdlib.h>  // for exit()
#include <string.h>  // strtok(), strcmp()
#include <unistd.h>  // for fork(), execvp()
#include <sys/wait.h>  // for wait()

int main(int argc, char *argv[])
{
    // (void) argc;

    for (int i = 0; i < 2; i++) {  // TODO: delete condition for infinite loop
        printf("mush$ ");
        fflush(stdout);
        char com_line[2048];
        fgets(com_line, 2048, stdin);

        char *args[1024];
        int i = 0;
        args[i] = strtok(com_line, " \t\n");
        char tok[128] = strtok(NULL, " \t\n");
        while (tok != NULL) {
            tok = strtok(NULL, " \t\n");
            args[i] = tok;
            i++;
        }

        printf("number of arguments = %d\n", i+1);
        printf("AAAAA\n");
        for (int j = 0; j < i; j++) {
            printf("BBBBB\n");
            printf("arg %d: %s\n", j, args[j]);
        }


    }

}
