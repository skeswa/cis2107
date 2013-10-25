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

int indexOf(char *s, char c) {
	int i = 0, sLength;
	if (is_blank(s)) return -1;
	sLength = strlen(s);
	for (i = 0; i < sLength; i++) {
		if (s[i] == c) return i;	
	}
	return -1;
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

char *make_space(int width) {
	int i = 0;
	char *s = malloc(width + 1);
	for (i = 0; i < width; i++) {
		s[i] = 32;
	}
	s[i] = 0;
	return s;
}

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
