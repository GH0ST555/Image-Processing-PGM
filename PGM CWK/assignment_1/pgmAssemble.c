
/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
//header code that includes struct definition and error codes
#include "readcodes.h"

//main function
int main(int argc, char **argv){
	/* check for correct number of arguments */
	if (argc == 1){
		// If no arguments given, print error message
		printf("Usage: ./pgmAssemble outputImage.pgm width height (row column inputImage.pgm)+\n");
		// Return appropriate error code
		return 0;
	}

	else if (argc < 6 && argc != 1)
	{
		// Print error message and return appropriate error code
    	printf("ERROR: Bad Argument Count");
    	return EXIT_WRONG_ARG_COUNT;
	}
	//integer to store the argument count
	int argumntNo = 3;
	//integer to calculate the argument number after each iteration in loop
	int count = 0;
	while(argumntNo<(argc+1)){
		//creates file pointer to and opens the argument in read
		FILE *inputFile = fopen(argv[argumntNo], "r");
		//checks if file is readable
		checkread(inputFile,argv[argumntNo]);
		//counter increases by 1
		count++;
		//argument increases by 3 times count + 3
		argumntNo = 3*count +3;
	}
	//create stutct to store data of 1st argument
	struct Fileinfo f1;
	struct Fileinfo *dataPointer=&f1;
	//open the file in write mode
	FILE *outputFile = fopen(argv[1], "w");
	//check if the file is writeable
	checkwrite(outputFile,argv[1],dataPointer);
	//close the file
	fclose(outputFile);
	//print success message
	printf("ASSEMBLED");
	//exit with proper code
	exit(0);
}
