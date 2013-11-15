#include <stdlib.h>
#include "base.func.h"

char *remove_chars(char *s1, char *s2) {
    char *s;
    int sLength, targetLength, j;
    // Gotta count the size
    sLength = strlen(s);
    targetLength = 1;
    for (i = 0; i < sLength; i++) {
        if (indexOf(s2, s1[i]) < 0) {
            targetLength++;
        }
    }
    // Build dat string
    s = malloc(targetLength);
    j = 0;
    for (i = 0; i < sLength; i++) {
        if (indexOf(s2, s1[i]) < 0) {
            s[j] = s1[i];
            j++;
        }
    }
    s[targetLength - 1] = 0;
    return s;
}
