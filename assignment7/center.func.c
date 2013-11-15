#include <stdlib.h>
#include "strlib.h"
#include "base.func.h"

char *center(char *s, int width) {
    char *newS;
    int sWidth;
    int offset;
    int i;
    
    if ((sWidth = strlen(s)) >= width) {
        return xerox(s);
    }
    offset = (width - sWidth) / 2;
    newS = make_space(width);
    for (i = 0; i < sWidth; i++) {
        newS[i + offset] = s[i];
    }
    return newS;
}