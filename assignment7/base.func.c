#include "base.func.h"

int blank(char *s) {
    if (!s) return 1;
    if (!*s) return 1;
    return 0;
}

int strlen(char *s) {
    int i = 0;
    if (blank(s)) return 0;
    while (*s) {
        i++;
        s++;
    }
    return i;
}

int indexOf(char *s, char c) {
    int i = 0, sLength;
    if (is_blank(s)) return -1;
    sLength = strlen(s);
    for (i = 0; i < sLength; i++) {
        if (s[i] == c) return i;    
    }
    return -1;
}