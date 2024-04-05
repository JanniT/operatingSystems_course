// I used this in help: https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {

    // printing the commandline parameters
    printf("\ncommandline parameters:\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    // printing the environment variables
    printf("\nenvironment variables:\n");
    for (char **env = envp; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}