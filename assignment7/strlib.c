#include <stdlib.h>

int strlen(char *s) {
	int i = 0;
	if (is_blank(s)) return 0;
	while (*s) {
		i++;
		s++;
	}
	return i;
}

int is_blank(char *s) {
	if (!s) return 1;
	if (!*s) return 1;
	return 0;
}

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
	
