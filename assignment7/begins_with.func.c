#include <stdlib.h>
#include "base.func.h"

int begins_with(char *s, char *pre) {
    int preLength, sLength, i;
    preLength = strlen(pre);
    sLength = strlen(s);
    if (preLength > sLength) return 0;
    else if (preLength == sLength) return 1;
    for (i = 0; i < preLength; i++) {
        if (s[i] != pre[i]) {
            return 0;
        }
    }
    return 1;
}