#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stego.h"

unsigned int lineLengthCache[MAX_REAL_LINES];
char *lineCache[MAX_REAL_LINES - 1];
unsigned int currLineSize[MAX_REAL_LINES - 1];

char *fileFormat;
unsigned int fileWidth = 0, fileHeight = 0, fileColorDepth = 0; 

void doLineRead(FILE *filePointer) {
	unsigned int index = 0, i = 0;
	int c;
	unsigned int inComment = FALSE;
	// Zero the lineLengthCache
	for (i = 0; i < MAX_REAL_LINES; i++) {
		lineLengthCache[i] = 0;
	}
	// Go back to the beginning of the file
	rewind(filePointer);
	// Do the line analysis
	printf("Doing line read...\n");
	do {
		c = fgetc(filePointer);
		if (c == HASH_CHAR_ID) {
			printf("\tEntered comment.\n");
			inComment = TRUE;
		} else if (c == NEWLINE_CHAR_ID || c == EOF) {
			if (inComment) {
				printf("\tExited comment.\n");
				inComment = FALSE;
			} else {
				printf("\tLine #%u of length %u identified.\n", index + 1, lineLengthCache[index]);
				index++;
			}
		} else {
			if (!inComment) {
				lineLengthCache[index]++;
			}
		}
	} while (c != EOF && index < MAX_REAL_LINES);
	printf("Line read complete...\n");
}

void doStringRead(FILE *filePointer) {
	unsigned int index = 0, i = 0;
	char c;
	unsigned int inComment = FALSE;
	// Do the string allocation
	for (i = 0; i < MAX_REAL_LINES - 1; i++) {
		lineCache[i] = (char *) malloc(sizeof(char) * (lineLengthCache[i] + 1));	
		currLineSize[i] = 0;
	}
	// Go back to the beginning of the file
	rewind(filePointer);
	// Do the line analysis
	printf("Doing string read...\n");
	while (index < MAX_REAL_LINES - 1) {
		c = fgetc(filePointer);

		if (c == HASH_CHAR_ID) {
			printf("\tEntered comment.\n");
			inComment = TRUE;
		} else if (c == NEWLINE_CHAR_ID || c == EOF) {
			if (inComment) {
				printf("\tExited comment.\n");
				inComment = FALSE;
			} else {
				// Capping off the string
				lineCache[index][currLineSize[index]] = 0;
				// Printing the string
				printf("\tLine #%u read in as string \"%s\".\n", index + 1, lineCache[index]);
				index++;
			}
		} else {
			if (!inComment) {
				lineCache[index][(currLineSize[index])++] = c;
			}
		}
	}
	printf("String read complete...\n");
}

void doAnalysis(FILE *filePointer) {
	unsigned int i = 0;
	// Do the string allocation
	for (i = 0; i < MAX_REAL_LINES - 1; i++) {
		switch (i) {
		case 0:
			fileFormat = lineCache[i];
			break;		
		case 1:
			sscanf(lineCache[i], "%u %u", &fileWidth, &fileHeight);
			break;
		case 2:
			sscanf(lineCache[i], "%u", &fileColorDepth);
			break;
		}
	}
	// Report the results
	printf("Doing analysis...\n\tFile Format: %s\n\tWidth in Pixels: %upx\n\tHeight in Pixels: %upx\n\tColor Depth: %u\nAnalysis complete...\n", fileFormat, fileWidth, fileHeight, fileColorDepth);
	// Do error checks
	if (strcmp(fileFormat, STANDARD_FILE_FORMAT) != 0) {
		// This isn't the right format
		printf("The file format was \"%s\", which is currently unsupported. Please use \"P6\" formatted files.\n");
		exit(2);
	}
}


int main(int argc, char **argv) {
	char *fileName; // Name of the file
	FILE *filePointer; // Pointer to the file specified by fileName
	// First assert that there is exactly one parameter
	if (argc != 2) {
		printf("ReadMsg requires exactly one paramter: the name of the file containing the message.\n");
		return 1;
	}
	// Ok, we good - lets read the file name
	fileName = argv[1];
	// Cool, lets turn that into an actual file pointer or something
	filePointer = fopen(fileName, "r");
	// Now we read :D
	doLineRead(filePointer);
	doStringRead(filePointer);
	doAnalysis(filePointer);
	// Kill file pointer
	fclose(filePointer);
	return 0;
}
