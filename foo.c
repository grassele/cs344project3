#include <stdio.h>
// #include <

int main (void)
{
    char s[] = "exit";
    if (strcmp(s, "exit") == 0) // use strcmp! remember that strcmp returns the difference between strings
        printf("exiting!\n");  
}

// int main (void)
// {
//     char s[] = "exit";
//     printf("%d\n", s == "exit");  // DIFFERENT S IN MEMORY - identical houses, but different address so not same
// }