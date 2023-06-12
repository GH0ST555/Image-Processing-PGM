/*************/
/* Main Routine                    */
/*************/

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
/* argv[2]: integer factor         */
/* argv[3]: output file            */
/* returns 0 on success            */
/* non-zero error code on fail     */
/*************/
int main(int argc, char **argv)
	{ /* main() */
		/* check for correct number of arguments */
		if (argc == 1)
		{
			// If no arguments given, print error message
			printf("Usage: ./pgmTile inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm\n");
			// Return appropriate error code
			return 0;
		}

		if (argc != 4)
		{ /* wrong arg count */
			/* print an error message        */
			printf("ERROR: Bad Argument Count\n");
			/* and return an error code      */
			return EXIT_WRONG_ARG_COUNT;
		}
		//initialize struct for input file
		struct Fileinfo f1;
		//initialize pointer for the input file
		struct Fileinfo *dataPointer=&f1;
		//file pointer for input file
		FILE *inputFile = fopen(argv[1], "r");

		//checks to see if the given file exits and opens correctly
		checkread(inputFile,argv[1]);

		//retrieves the magic number of input file
		getmno(inputFile,argv[1],dataPointer);
		//checks commentline of input file
		chkcom(inputFile,argv[1],dataPointer);
		//checks structure of input file
		chkstructure(inputFile,argv[1],dataPointer);
		//variable to store magic number of inputfile
		unsigned short *magic_Number = (unsigned short *) dataPointer->magic_number;
		//checks if the magic number of input is magic number for ASCII PGM FILE
		// if so it reads the file and writes it into a new file
		if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){
			//read pixel data in ascii mode
			readfile(inputFile,argv[1],dataPointer);
			//file pointer for output file
			FILE* out = fopen(argv[3], "w");
			//checks writablilty of output file
			checkwrite(out,argv[3],dataPointer);
			//writes pixel data into output file
			writefile(out,argv[3],dataPointer);
			//close the output file
			fclose(out);
			//print success message
			printf("TILED\n");
			//return success code
			exit(0);
		}

		//checks if the magic number is magic number for BINARY PGM FILE
		// if so it reads the file and writes it into a new file
		else if (*magic_Number == MAGIC_NUMBER_RAW_PGM){
			//read file info in binray mode
			readbfile(inputFile,argv[1],dataPointer);
			//file pointer for output file
			FILE* out = fopen(argv[2], "w");
			//checks if output file is writeable
			checkwrite(out,argv[2],dataPointer);
			//write pixels into output file
			writebfile(out,argv[2],dataPointer);
			//print success message
			printf("TILED\n");
			//return success code
			exit(0);
		}
	}
