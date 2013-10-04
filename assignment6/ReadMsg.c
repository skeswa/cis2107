#include <stdio.h>

#include "stego.h"

#define BUFFER_SIZE 100

// Reading flags
int isReadingComment = FALSE;
int isSkippingWhitespace = FALSE;
int isReadingMagicNumber = FALSE;
int isReadingPixelWidth = FALSE;
int isReadingPixelHeight = FALSE;

int skipWhitespace(char *buffer, int bufferSize, FILE *filePointer, int index) {
	if (index < 0) return -1;
	while (TRUE) {
		// Check out boundary condition
		if (index >= bufferSize) {
			if (fgets(buffer, bufferSize, filePointer) == NULL) {
				return -1;
			}
			index = 0;
		}
		// Skip dat whitespace
		if (buffer[index] == SPACE_CHAR_ID || buffer[index] == NEWLINE_CHAR_ID || buffer[index] == TAB_CHAR_ID) {
			index++;		
		} else {
			// Dis ain't no whiespace
			return index;
		}
	}
	return -1;
}

int skipComment(char *buffer, int bufferSize, FILE *filePointer, int index) {
	if (index < 0) return -1;
	while (TRUE) {
		// Check out boundary condition
		if (index >= bufferSize) {
			if (fgets(buffer, bufferSize, filePointer) == NULL) {
				return -1;
			}
			index = 0;
		}
		// Continue until the next line
		if (buffer[index] == NEWLINE_CHAR_ID) {
			return ++index;		
		} else {
			// We still in dat young comment
			index++;
		}
	}
	return -1;
}

int advance(char *buffer, int bufferSize, FILE *filePointer, int index) {
	if (index < 0) return -1;
	while (TRUE) {
		// Check out boundary condition
		if (index >= bufferSize) {
			if (fgets(buffer, bufferSize, filePointer) == NULL) {
				return -1;
			}
			index = 0;
		} else if (index < 0) {
			return -1;
		}
		// Skip dat whitespace
		if (buffer[index] == HASH_CHAR_ID || (buffer[index] == SPACE_CHAR_ID || buffer[index] == NEWLINE_CHAR_ID || buffer[index] == TAB_CHAR_ID)) {
			if (buffer[index] == HASH_CHAR_ID) {
				index = skipComment(buffer, bufferSize, filePointer, index);
			} else {
				index = skipWhitespace(buffer, bufferSize, filePointer, index);
			}
		} else {
			// We're in the clear
			return index;
		}
	}
	return -1;
}

int readMagicNumber(char *buffer, int bufferSize, FILE *filePointer, int index) {
	int start = index;
	if (index < 0) return -1;
	while (TRUE) {
		// Check out boundary condition
		if (index >= bufferSize) {
			if (fgets(buffer, bufferSize, filePointer) == NULL) {
				return -1;
			}
			index = 0;
		}
		// Continue until the next line
		if (buffer[index] == NEWLINE_CHAR_ID) {
			// We reached the end of the magic number
			return ++index;		
		} else {
			// We still in dat young comment
			return index++;
		}
	}
	return -1;
}

int readPixelWidth(char *buffer, int bufferSize, FILE *filePointer, int index) {
	// TODO
	int start = index;
	if (index < 0) return -1;
	while (TRUE) {
		// Check out boundary condition
		if (index >= bufferSize) {
			if (fgets(buffer, bufferSize, filePointer) == NULL) {
				return -1;
			}
			index = 0;
		}
		// Continue until the next line
		if (buffer[index] == NEWLINE_CHAR_ID) {
			// We reached the end of the magic number
			return ++index;		
		} else {
			// We still in dat young comment
			return index++;
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	char *fileName; // Name of the file
	char buffer[BUFFER_SIZE]; // The buffer for reading the file
	FILE *filePointer; // Pointer to the file specified by fileName
	int index;

	// First assert that there is exactly one parameter
	if (argc != 2) {
		printf("ReadMsg requires exactly one paramter: the name of the file containing the message.");
		return 1;
	}
	// Ok, we good - lets read the file name
	fileName = argv[1];
	// Cool, lets turn that into an actual file pointer or something
	filePointer = fopen(fileName, "r");
	// Now we read :D
	index = 0;
	skipWhitespace(buffer, BUFFER_SIZE, filePointer, index);
	while(fgets(buffer, BUFFER_SIZE, filePointer) != NULL) {
		
		// Get a line, up to 100 chars from filePointer - done if NULL
		sscanf(buffer, "%ld", &elapsed_seconds);
		// Convert the string to a long int
		printf ("%ld\n", elapsed_seconds);
	}
	// Kill file pointer
	fclose(filePointer);
	return 0;
}
