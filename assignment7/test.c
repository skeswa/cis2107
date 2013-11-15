#include "stdlib.h"
#include <string.h>
#include <stdio.h>

int main() {
    char *str1, *str2;
    char *blankString1 = "";
    char *blankString2 = NULL;
    char *bananaString = "banana";
    char *bananaCenteredString = "   banana   ";
    // Testing int is_blank(char *s);
    if (!is_blank(blankString1)) printf("Failure at ln 10.");
    if (!is_blank(blankString2)) printf("Failure at ln 10.");
    if (is_blank(bananaString)) printf("Failure at ln 10.");
    // Testing char *xerox(char *s);
    str2 = xerox(bananaString);
    if (strcmp(str2, bananaString)) printf("Failure at ln 10.");
    free(str2);
    str2 = NULL;
    // Testing char *center(char *s, int width);
    str2 = center(bananaString, 12);
    if (strcmp(str2, bananaCenteredString)) printf("Failure at ln 10.");
    free(str2);
    str2 = NULL;
    str2 = center(bananaString, 6);
    if (strcmp(str2, bananaString)) printf("Failure at ln 10.");
    free(str2);
    str2 = NULL;
    // Testing int begins_with(char *s, char *pre);
    // Testing int ends_with(char *s, char *suff);
    // Testing char *remove_chars(char *s1, char *s2);
    // Testing int index_of_first_difference(char *s1, char *s2);
    // Testing void lstrip(char *s);
    // Testing void rstrip(char *s);
    // Testing void strip(char *s);
    // Testing int find_idx(char *s, char c);
    // Testing char *find_ptr(char *s, char c);
    // Testing char *slice(char *s, int b, int e);
    // Testing int strcmp_ign_case(char *s1, char *s2);
    // Testing void str_glue(char *s1, char *s2);
    // Testing char *ellipsize(char *s, int nw);
    // Testing char *replace(char *s, char *pat, char *rep);
    // Testing char **chop(char *s, char c);
}
