#include <stdlib.h>
#include "base.func.h"

int index_of_first_difference(char *s1, char *s2) {
    int i = 0, s1Length, s2Length, smallerLength;
    s1Length = strlen(s1);
    s2Length = strlen(s2);
    smallerLength = (s1Length > s2Length) ? s2Length : s1Length;
    for (i = 0; i < smallerLength; i++) {
        if (s1[i] != s2[i]) {
            return i;
        }
    }
    if (slLength != s2Length) return i;
    else return -1;
}