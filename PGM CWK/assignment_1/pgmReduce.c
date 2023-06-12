/*************/
/* Main Routine                    */
/*************/

/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include "readcodes.h"

/*************/
/* main routine                    */
/*                                 */
/* CLI parameters:                 */
/* argv[0]: executable name        */
/* argv[1]: input file name        */
/* argv[2]: reduction factor      */
/* argv[3]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/*************/
int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	if (argc == 1){
		// If no arguments given, print error message
		printf("Usage: %s inputImage.pgm reduction_factor outputImage.pgm\n", argv[0]);
		// Return appropriate error code
		return 0;
	}
	if (argc != 4){
		/* wrong arg count */
		/* print an error message        */
		printf("ERROR: Bad Argument Count\n");
		/* and return an error code      */
		return EXIT_WRONG_ARG_COUNT;
	}
	//assign array to hold reduction factor
	char *reductionFactor = argv[2];
	//integer to store the length of reduction factor
	int lengthStr = strlen(argv[2]);
	//integer to store charcter index
	int i = 0;

	//checking for negative reduction factpr
	if (reductionFactor[0] == '-'){
		//redction factor is Negative
		//print error message
		printf("ERROR: Miscellaneous (Negative Scaling Factor)\n");
		//return appropriate code
		exit(100);
	}
	else if (!isdigit(reductionFactor[0])){
		//reduction factor is not an integer
		//print appropriate error message
		printf("ERROR: Miscellaneous (Non Numeric Scaling Factor)\n");
		//return appropriate exit code
		exit(100);
	}
	for (i = 1; i < lengthStr ; i++)
	{
		//if (number[i] > '9' || number[i] < '0')
		if (!isdigit(reductionFactor[i])){
			//the character in recution factor is non Numeric
			//print error message
			printf("ERROR: Miscellaneous (Non Numeric Scaling Factor)\n");
			//return appropriate error code
			exit(100);
		}
	}
	int reductionF = atoi(reductionFactor);
	//assign struct to store file info
	struct Fileinfo f1;
	struct Fileinfo *dataPointer=&f1;

	struct Fileinfo f2;
	struct Fileinfo *dataPointer2=&f2;
	//assign file pointer to open the input file
	FILE *inputFile = fopen(argv[1], "r");

	//checks to see if the given file exits and opens correctly
	checkread(inputFile,argv[1]);

	//opens the file just to retrieve the magic number and then closes it
	getmno(inputFile,argv[1],dataPointer);
	//checks file comment
	chkcom(inputFile,argv[1],dataPointer);
	//checks file dimensions and maxgray
	chkstructure(inputFile,argv[1],dataPointer);
	//assign filename pointer to input file
	dataPointer->filename = argv[1];
	//close the file
	unsigned short *magic_Number = (unsigned short *) dataPointer->magic_number;
	//checks if the magic number is magic number for ASCII PGM FILE
	// if so it reads the file and writes it into a new file
	if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){
		//read file data
		readfile(inputFile,argv[1],dataPointer);

		//open file pointer for output file
	}
	//checks if the magic number is magic number for BINARY PGM FILE
	// if so it reads the file and writes it into a new file
	else if (*magic_Number == MAGIC_NUMBER_RAW_PGM){
		//read file data in binary mode
		readbfile(inputFile,argv[1],dataPointer);
		//write into file
	}
	FILE* out = fopen(argv[3], "w");
	//checks writablity of output file
	checkwrite(out,argv[3],dataPointer);
	//reads the reduced pixels into file
	reducedRead(dataPointer, dataPointer2,reductionF);
	//write into file
	if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){
		writefile(out,argv[3],dataPointer2);
		fclose(out);
		//print success message
		printf("REDUCED\n");
		//return success code
		exit(0);
	}
	else if (*magic_Number == MAGIC_NUMBER_RAW_PGM){
		writebfile(out,argv[3],dataPointer);
		fclose(out);
		//print success message
		printf("REDUCED\n");
		//return success code
		exit(0);
	}

}
