
/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "readcodes.h"

/*************/
/* main routine                    */
/*                                 */
/* CLI parameters:                 */
/* argv[0]: executable name        */
/* argv[1]: input file name        */
/* argv[2]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/*************/
int main(int argc, char **argv)
	{ /* main() */
		/* check for correct number of arguments */
		if (argc == 1)
		{
			// If no arguments given, print error message
			printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
			// Return appropriate error code
			return 0;
		}

		if (argc != 3)
			{ /* wrong arg count */
				/* print an error message        */
				printf("ERROR: Bad Argument Count\n");
				/* and return an error code      */
				return EXIT_WRONG_ARG_COUNT;
			}
		//define struct to store values of the input file
		struct Fileinfo f1;
		//assign file pointer for input file
		struct Fileinfo *dataPointer=&f1;
		//open the input file
		FILE *inputFile = fopen(argv[1], "r");

		//checks to see if the given file exits and opens correctly
		checkread(inputFile,argv[1]);

		//opens the file just to retrieve the magic number and then closes it
		getmno(inputFile,argv[1],dataPointer);
		chkcom(inputFile,argv[1],dataPointer);
		chkstructure(inputFile,argv[1],dataPointer);
		unsigned short *magic_Number = (unsigned short *) dataPointer->magic_number;
		//checks if the magic number is magic number for ASCII PGM FILE
		// if so it reads the file and writes it into a new file
		if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){
			//the file has an ASCII magic number
			//read pixel data
			readfile(inputFile,argv[1],dataPointer);

			//open file pointer to write image data
			FILE* out = fopen(argv[2], "w");
			//check if the file is writeable
			checkwrite(out,argv[2],dataPointer);
			//writes data into the file
			writefile(out,argv[2],dataPointer);
			//close the output file
			fclose(out);
			//print successful file echo message
			printf("ECHOED\n");
			//return appropriate code
			exit(0);
		}

		//checks if the magic number is magic number for BINARY PGM FILE
		// if so it reads the file and writes it into a new file
		else if (*magic_Number == MAGIC_NUMBER_RAW_PGM){
			//the file has the binary magic number
			//reads image data in binary mode
			readbfile(inputFile,argv[1],dataPointer);
			//open file pointer to write image data
			FILE* out = fopen(argv[2], "w");
			//check if file is writeable
			checkwrite(out,argv[2],dataPointer);
			//write pixel data
			writebfile(out,argv[2],dataPointer);
			//close the output file
			fclose(out);
			//print successful file echo message
			printf("ECHOED\n");
			//return appropriate code
			exit(0);
		}
	}
