#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


static void methods()
{
    // TODO printf all global and weak functions in lib.o
    //      one per line, in alphabetic order
    //      your code should be something like:
    //        printf("some_function\n");
    //        printf("some_other_function\n");
    //      you should have exactly one \n in each printf

    assert(0); // Not implemented, when you have, remove this line.
}


static void vars()
{
    // TODO printf all global and static variables in lib.o
    //      one per line, in alphabetic order
    //      your code should be something like:
    //        printf("some_variable\n");
    //        printf("some_other_variable\n");
    //      you should have exactly one \n in each printf

    assert(0); // Not implemented, when you have, remove this line.
}

// TODO define functions and variables you found in lib.o


int main(int argc, char * argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Program needs at least one argument\n");
        return 1;
    }

    char * arg = argv[1];
    if (!strcmp(arg, "methods")) {
        methods();
    } else if (!strcmp(arg, "vars")) {
        vars();
    } else if (!strcmp(arg, "help")) {
        assert(0); // NOT IMPLEMENTED remove this line once implemented
    } else {
        const int result = -1;
        assert(0); // NOT IMPLEMENTED remove this line once implemented
    }

    return 0;
}
