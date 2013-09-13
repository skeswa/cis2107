#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define SLASH_CHAR 47
#define ASTERISK_CHAR 42
#define NEWLINE_CHAR 10

int main(void) {
	/* Instance Variables */
	int c, lineNumber = 1, commentLineNumber = 0, isLooking = FALSE, isInComment = FALSE;

	while((c = getchar()) > 0) {
		/* Check for comment characters in sequence */
		if (c == SLASH_CHAR) {
			if (isLooking) {
				isInComment = FALSE;
			} else {
				isLooking = TRUE;
			}
		} else if (c == ASTERISK_CHAR) {
			if (isLooking) {
				isInComment = TRUE;
				commentLineNumber = lineNumber;
			} else {
				isLooking = TRUE;
			}
		} else {
			if (isLooking) isLooking = FALSE;
			if (c == NEWLINE_CHAR) {
				lineNumber++;
			}

			if (!isInComment) {
				putchar(c);
			}
		}
	}
	
	if (isInComment) {
		printf("\n\n\n\nHouston we have a problem at line %d. You have an unterminating comment son.\n", commentLineNumber);
		return 1;
	} else {
		printf("\nDONE.\n");
		return 0;
	}
}
