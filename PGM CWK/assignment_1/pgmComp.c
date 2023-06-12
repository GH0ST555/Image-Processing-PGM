#include <stdio.h>
#include "readcodes.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/*************/
/* main routine                    */
/*                                 */
/* CLI parameters:                 */
/* argv[0]: executable name        */
/* argv[1]: input file name        */
/* argv[2]: input file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/*************/
int main(int argc, char **argv)
	{
		/*Two structs with file info stored to check if they are the same*/

		//to check weather the user has not entered any arguments
		if (argc == 1)
		{
			//wrong argument count
      		// If no arguments given, print error message
      		printf("Usage: %s inputImage.pgm inputImage.pgm\n", argv[0]);
      		// Return appropriate error code
     		return 0;
		}

		//to check weather the user has entered the wrong number of arguments
		if (argc !=3 && argc !=1)
		{ 	
			/* wrong arg count */
			/* print an error message        */
			printf("ERROR: Bad Argument Count");
			/* and return an error code      */
			return EXIT_WRONG_ARG_COUNT;
		}

		//define the struct for storing values of first file
		struct Fileinfo f1;
		//assign a pointer for first file 
		struct Fileinfo *dataPointer=&f1;

		//open file that is to be read
		FILE *inputFile = fopen(argv[1], "r");

		//checks if the first file is null
		checkread(inputFile,argv[1]);

		//checks if the magic number if the first file is valid (ie IF it is ASCII or Binary) and stores the magic number in the struct
		getmno(inputFile,argv[1],dataPointer);

		//checks if the commentline of the first file is valid
		chkcom(inputFile,argv[1],dataPointer);

		//checks if the dimensions and maxGray values of the first file are valid and stores them in the struct
		chkstructure(inputFile,argv[1],dataPointer);

		//add the first filename to the struct pointer
		dataPointer->filename = argv[1];

		//store the magic number in a variable
		unsigned short *magic_Number = (unsigned short *) dataPointer->magic_number;

		//conditions to check weather the magic number is ASCII
		if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){
			//the file is ASCII
			//read the File using ascii read function
			readfile(inputFile,argv[1],dataPointer);
		}
		else if (*magic_Number == MAGIC_NUMBER_RAW_PGM){
			//the file is BINARY
			//read the File using binary read function
			readbfile(inputFile,argv[1],dataPointer);
		}

		//create struct for the second file
		struct Fileinfo f2;
		//assign the pointer for the second file
		struct Fileinfo *dataPointer2=&f2;

		//creates file pointer for the second file
		FILE *inputFile2 = fopen(argv[2], "r");

		//checks if the second file is null
		checkread(inputFile2,argv[2]);

		//checks if the magic number if the second file is valid (ie IF it is ASCII or Binary) and stores the magic number in the struct
		getmno(inputFile2,argv[2],dataPointer2);

		//checks if the commentline of the second file is valid
		chkcom(inputFile2,argv[2],dataPointer2);

		//checks if the dimensions and mxGray values of the first file are valid and stores them in the struct
		chkstructure(inputFile2,argv[2],dataPointer2);

		//assign the second file to the filename pointer of the second struct
		dataPointer2->filename = argv[2];

		//assign variable to store the magic number of the second file
		unsigned short *magic_Number2 = (unsigned short *) dataPointer2->magic_number;

		//if the magic number of the second file is ASCII
		if (*magic_Number2 == MAGIC_NUMBER_ASCII_PGM){
			//the file is ASCII
			//uses the ASCII read function
			readfile(inputFile2,argv[2],dataPointer2);
		}

		//if the magic number of the second file is Binary
		else if (*magic_Number2 == MAGIC_NUMBER_RAW_PGM){
			//the file is binary
			//uses the Binary read function
			readbfile(inputFile2,argv[2],dataPointer2);
		}

		// conditions to compare the basic properties of both files to check weather they are structurally identical
		if  (dataPointer->width != dataPointer2->width || dataPointer->height != dataPointer2->height || dataPointer->maxGray != dataPointer2->maxGray){
			//conditions are not met and the files are distinct
			//print message
			printf("DIFFERENT");
			//return the code for successful comparison
			exit(0);
		}
		else{
			// the conditions are met and the files have identical structure
			//now to test if the pixel values are identical

			//create integer to count the number of identical pixels
			int pIdentical;

			//create integer to hold the product of dimensions
			long dims = dataPointer->width * dataPointer->height * sizeof(unsigned char);
			for(int k = 0; k < dataPointer -> height ; k++){
				for(int l = 0; l < dataPointer -> width ; l++){
					if (dataPointer->imageData[k][l] == dataPointer2->imageData[k][l]){
						//the pixels are identical
						//add 1 to the variable
						pIdentical++;
					}
				}
			}
			//condition to check if the number of identical pixels is equal to the product of dimensions
			if (pIdentical == dims){
				//the files are identical
				//print success message
				printf("IDENTICAL");
				//return successful file comparison code
				exit(0);
			}
			else{
				//conditions are not met and the files are distinct
				//print message
				printf("DIFFERENT");
				//return the code for successful comparison
				exit(0);
			}
		}

}
