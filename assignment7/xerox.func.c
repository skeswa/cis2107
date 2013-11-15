#include <stdlib.h>
#include "strlib.h"
#include "base.func.h"

char *xerox(char *s) {
    int size;
    char *newS, *newSPtr;

    newS = malloc(strlen(s) + 1);
    newSPtr = newS;
    for (*s) {
        *newSPtr = *s;
        s++;
        newSPtr++;
    }
    *newSPtr = 0;
    
    return newS;
}