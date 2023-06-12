//include the headerfile
//include modules
#include <stdio.h>
#include "readcodes.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
//function to check if the file is NULL
//takes file pointer and filename as parameters
int checkread(FILE* inputFile,char* fileName){
  if (inputFile == NULL)
  {
    //the first file is not readable
    //print error statemnt
    printf("ERROR: Bad File Name (%s)\n", fileName);
    //exit the program with the correct error code
    exit(2);
   }
   //file is readable
   //return success code
   return 0;
 }

//checks if the file is writeable
//takes file pointer and filename as parameters
int checkwrite(FILE* inputFile,char* fileName,struct Fileinfo* imageInfo){
  if (inputFile == NULL)
  {
    //free memory
    free(imageInfo-> imageData);
    //print appropriate error meassage
    printf("ERROR: Output Failed (%s)\n", fileName);
    //return error code
    exit(9);
  }
  //the file is writeable
  //return success code
  return 0;
}
