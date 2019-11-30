#include "helloWorld.h"
#include <stdio.h>

void hello(void) {
    printf("Hello, automake!\n");
}

char* sayIt(char *input) {
    char *s = NULL;
    s = (char *)malloc(100);
    sprintf(s, "Name is %s, len is %d", input, strlen(input));
    free(s);
    return s;
}

