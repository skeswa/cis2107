#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

unsigned int lengthOf(FILE *fp);
void readTo(FILE *fp, char *s);
char *nextWord(FILE *fp);
int contains(char* src, char* str);

int main(int argc, char **argv) {
    char *filePath, *dictionaryPath = "/usr/share/dict/words", *dictionaryBlob, *word;
    FILE *file, *dictionary;
    // Do check for parameter checking
    if (argc < 2) {
        printf("At least ONE argument is needed: the name of the file to check.\n");
        exit(1);
    }
    if (argc > 3) {
        printf("At most TWO arguments are required: the name of the file to check, and the dictionary to reference.\n");
        exit(1);
    }
    // Now we grab the arguments
    if (argc == 2 || argc == 3) {
        // We got the file name then
        filePath = argv[1];
    } if (argc == 3) {
        // We got the dictionary overidden
        dictionaryPath = argv[2];
    }
    // Now we open both files
    file = fopen(filePath, "r");
    if (!file) {
        printf("Could not read from file \"%s\". The problem was: %s.\n", filePath, strerror(errno));
        exit(1);
    }
    dictionary = fopen(dictionaryPath, "r");
    if (!dictionary) {
        printf("Could not read from dictionary \"%s\". The problem was: %s.\n", dictionaryPath, strerror(errno));
        exit(1);
    }
    // Allocate the dict blob
    dictionaryBlob = malloc((lengthOf(dictionary) * sizeof(char)) + 1);
    // Read the contents
    readTo(dictionary, dictionaryBlob);
    // Cycle through words
    while ((word = nextWord(file)) != NULL) {
        if (contains(dictionaryBlob, word)) {
            printf("%s OK\n", word);
        } else {
            printf("%s MISSPELLED\n", word);
        }
        // Avoid the memory leak
        free(word);
    }
    // FINISH IT
    printf("done!\n");
}

unsigned int lengthOf(FILE *fp) {
    unsigned int i = 0;
    while (fgetc(fp) != EOF) {
        i++;
    }
    rewind(fp);
    return i;
}

void readTo(FILE *fp, char *s) {
    char c;
    while ((c = fgetc(fp)) != EOF) {
        *s = c;
        s++;
    }
    *s = 0;
    rewind(fp);
}

char *nextWord(FILE *fp) {
    char c, *s = NULL;
    int i = 0, inWord = 0;
    while (1) {
        c = fgetc(fp);
        if (isspace(c) || ispunct(c) || c == EOF) {
            if (!inWord && (c == EOF)) return NULL;
            else if (inWord && (s == NULL)) {
                s = malloc(i + 1);
                fseek(fp, (c == EOF ? i : (i + 1)) * -1, SEEK_CUR);
                i = 0;
            } else if (s != NULL) {
                s[i] = 0;
                return s;
            }
        } else {
            if (s != NULL) {
                s[i] = c;
            } else {
                if (!inWord) inWord = 1;
            }
            if (inWord) i++;
        }
    }
    // Uh, the file is at the end already
    return NULL;
}

int indexOf(char* src, char* str, int begin) {
    int result;
    int srclen = strlen(src);
    if (strlen(str) > srclen || begin > srclen) {
        result = -1;
    } else {
        if (begin < 0) {
            begin = 0;
        }
        char* pos = strstr(src + begin, str);
        if (pos == NULL) {
            result = -1;
        } else {
            result = pos - src;
        }
    }
    return result;
}

int contains(char* src, char* str) {
    return (indexOf(src, str, 0) != -1);
}