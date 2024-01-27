#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>




static void methods()
{
    printf("error_handler\n");
    printf("is_invalid\n");
    printf("signature\n");
    printf("usage\n");
}

static void vars()
{
    printf("ERRORS\n");
    printf("FULL\n");
    printf("FULL_ERRORS\n");
    printf("MODE\n");
    printf("RESTRICTED\n");
    printf("STATUSCODE\n");
}

extern void usage();
extern void vars();
extern void methods();
extern int signature(char* input, int len);
extern int is_invalid(const char* input, size_t len);
extern int* MODE;
extern int STATUSCODE;
extern int FULL;
extern int RESTRICTED;

void reverse_string(char* string) {
    char* startPtr = string;
    char* endPtr = string + strlen(string) - 1;

    while (startPtr < endPtr) {
        char temp = startPtr;
        startPtr =endPtr;
        endPtr = temp;

        startPtr++;
        endPtr--;
    }
}


int main(int argc, char argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Program needs at least one argument\n");
        return 1;
    }

    char arg = argv[1];
    if (!strcmp(arg, "methods")) {
        methods();
    }
    else if (!strcmp(arg, "vars")) {
        vars();
    }
    else if (!strcmp(arg, "help")) {
        usage();
    }
    else {
        if (is_invalid(arg, strlen(arg)) == 0)
        {
            MODE = &RESTRICTED;
        }
        else
        {
            MODE = &FULL;
        }
        int sig = signature(arg, strlen(arg));

        if (STATUSCODE == 0)
        {
            printf("%d", sig);
        }
        else
        {
            char reversed[strlen(arg) + 1];
            strcpy(reversed, arg);
            reverse_string(reversed);
            printf("%s", reversed);
        }
    }

    return 0;
}