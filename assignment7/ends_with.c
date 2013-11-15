#include <stdlib.h>
#include "base.func.h"

int ends_with(char *s, char *suff) {
    int suffLength, sLength, i;
    suffLength = strlen(suff);
    sLength = strlen(s);
    if (suffLength > sLength) return 0;
    else if (suffLength == sLength) return 1;
    for (i = sLength - suffLength; i < sLength; i++) {
        if (s[i] != suff[i]) {
            return 0;
        }
    }
    return 1;
}