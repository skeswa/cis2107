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

void lstrip(char *s) {
	int i = 0, j = 0;
	while (s[i] == /*space*/ 32 || s[i] == /*newline*/ 10 || s[i] == /*tab*/ 9) i++;
	while (s[i] != /*nullchar*/ 0) {
		s[j] = s[i];
		j++;
		i++;
	}
	s[j] = 0;
}

void rstrip(char *s) {
	int i = strlen(s) - 1, j = i;
	while (s[i] == /*space*/ 32 || s[i] == /*newline*/ 10 || s[i] == /*tab*/ 9 || s[i] == /*nullchar*/ 0) i--;
	if (i != j) s[i + 1] = 0;
}

void strip(char *s) {
	rstrip(s);
	lstrip(s);
}

int find_idx(char *s, char c) {
	int i = 0;
	while (s[i] != c && s[i] != 0) i++;
	if (s[i] == 0) return -1;
	else return i;
}

char *find_ptr(char *s, char c) {
	int i = find_idx(s, c);
	if (i < 0) return NULL;
	return s + i;
}

char *slice(char *s, int b, int e) {
	int length, i;
	char *newS;
	if (b < e) return NULL;
	length = e - b + 1;
	newS = malloc((length * sizeof(char)) + 1;
	for (i = 0; i < length; i++) {
		newS[i] = s[b];
	}
	newS[i] = 0;
	return newS;
}

int strcmp_ign_case(char *s1, char *s2) {
	int i = 0, s1Length, s2Length, smallerLength;
	char currS1, currS2;
	s1Length = strlen(s1);
	s2Length = strlen(s2);
	smallerLength = (s1Length > s2Length) ? s2Length : s1Length;
	for (i = 0; i < smallerLength; i++) {
		currS1 = s1[i];
		currS2 = s2[i];
		if (currS1 >= /*a*/ 97 && currS1 <= /*z*/ 122) currS1 -= 32;
		if (currS2 >= /*a*/ 97 && currS2 <= /*z*/ 122) currS2 -= 32;
		if (currS1 < currS2) {
			return -1;
		} else if (currS2 < currS1) {
			return 1;
		}
	}
	if (s1Length == s2Length) {
		return 0;
	} else if (smallerLength == s1Length) return -1;
	} else {
		return 1;
	}
}

void str_glue(char *s1, char *s2) {
	memcpy(s1 + strlen(s1), s2, (strlen(s2) + 1) * sizeof(char));
}

char *ellipsize(char *s, int nw) {
	int i = 0;
	int wc = 0;
	int isInWord = 0; 
	int length = strlen(s);
	while (i = 0; i < length; i++) {
		if ((s[i] >= /*a*/ 97 && currS1 <= /*z*/ s[i]) || (s[i] >= /*A*/ 65 && s[i] <= /*Z*/ 90)) {
			if (!isInWord) isInWord = 1;
		} else {
			if (isInWord) {
				wc++;
				isInWord = 0;
				if (wc == nw) {
					return str_glue(slice(s, 0, i - 1), " ...");
				}
			}
		}
	}
	if (isInWord) {
		wc++;
		if (wc == nw) return s;
	}
}

char *replace(char *s, char *pat, char *rep) {
	int i, j; 
	int sLength = strlen(s); 
	int patIndex = 0;
	int patCount = 0;
	int patLength = strlen(pat);
	int repLength = strlen(rep);
	int newSLength;
	char *newS;
	// First do analysis
	for (i = 0; i < sLength; i++) {
		if (patIndex < patLength) {
			if (pat[patIndex] == s[i]) {
				patIndex++;
			} else {
				patIndex = 0;
			}
		} else {
			patCount++;
		}
	}
	newSLength = ((repLength - patLength) * patCount) + sLength;
	newS = (char *) malloc((newSLength + 1) * sizeof(char));
	patIndex = 0;
	for (i = 0; i < newSLength; i++) {
		if (s[i] == pat[0]) {
			for (j = 1; j < patLength; j++) {
				if (s[i + j] != pat[j - 1]) break;
			}
			if (j == patLength) {
				for (j = 0; j < repLength; j++) {
					newS[i + j] = rep[j];
				}
				i += repLength;
			}
		}
	}
	newS[newSLength] = 0;
	return newS;
}

char **chop(char *s, char c) {
	// Count all the c's
	return (char **)NULL;
}