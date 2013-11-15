#include <stdlib.h>

char *make_space(int width) {
    int i = 0;
    char *s = malloc(width + 1);
    for (i = 0; i < width; i++) {
        s[i] = 32;
    }
    s[i] = 0;
    return s;
}