#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include "readcodes.h"

//function that checks if magic number is valid and stores into a struct
int getmno(FILE* inputFile, char*fileName,struct Fileinfo* id){
  //stores the magic number into the struct
  id->magic_number[0] = getc(inputFile);
  id->magic_number[1] = getc(inputFile);

  //create variable to store magic number
  unsigned short *magic_Number = (unsigned short *) id->magic_number;

  //condition to check magic number
  if (*magic_Number != MAGIC_NUMBER_ASCII_PGM && *magic_Number != MAGIC_NUMBER_RAW_PGM){
    //magic number is invalid
    //close the file
    fclose(inputFile);
    //print error message
    printf("ERROR: Bad Magic Number (%s)\n",fileName);
    /* and exit the program with the correct return code*/
    exit (BAD_MAGIC_NUMBER);
  }
  //successful magic number check
  //return success code
  return 0;
}
