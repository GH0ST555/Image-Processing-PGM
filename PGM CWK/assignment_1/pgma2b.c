#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
//include the header file with error codes
#include "readcodes.h"

//MAIN FUNCTION
int main(int argc, char **argv){
  // ARGUMENT CHECKS
  if (argc == 1)
  {
    // If no arguments given, print error message
    printf("Usage: %s inputImage.pgm outputImage.pgm\n", argv[0]);
    // Return appropriate error code
    return 0;
  }

  else if (argc != 3 && argc != 1)
  {
    // If number of arguments wrong, print error message
    printf("ERROR: Bad Argument Count\n");

    // Return appropriate error code
    return EXIT_WRONG_ARG_COUNT;
  }
	struct Fileinfo f1;
	struct Fileinfo *dataPointer=&f1;

  //opens the file pointer
  FILE *inputFile = fopen(argv[1], "r");
  //checks if file is readable
  checkread(inputFile,argv[1]);
  //retrieves magic number for inputFile
  getmno(inputFile,argv[1],dataPointer);
  //checks comment for inputFile
  chkcom(inputFile,argv[1],dataPointer);
  //checks file structure for inputFile
  chkstructure(inputFile,argv[1],dataPointer);

  //assign the filename into the filename pointer
  dataPointer->filename = argv[1];

  //assign variable to store the magic number
  unsigned short *magic_Number = (unsigned short *) dataPointer->magic_number;

  //checks if the magic number is the magic number of an ASCII PGM file
  if (*magic_Number == MAGIC_NUMBER_ASCII_PGM){
    //read the file in ASCII
    readfile(inputFile,argv[1],dataPointer);
    FILE* outputFile = fopen(argv[2],"w");
    checkwrite(outputFile,argv[2],dataPointer);
    //write the file in binary
   	writebfile(outputFile,argv[2],dataPointer);
    //close outputfile
    fclose(outputFile);
    //print statemnt for succesful conversion
   	printf("CONVERTED\n");
  }

  else{
    //the file was not ascii
    //print the error statement
    printf("ERROR: Bad Magic Number (%s)",argv[1]);
    //return error code
    return 3;
  }
}
