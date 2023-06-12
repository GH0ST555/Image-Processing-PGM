#include <stdio.h>
#include "readcodes.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

//function to check the commentline of the file
//uses input file pointer, fileName and struct as parameters
int chkcom(FILE* inputFile, char*fileName,struct Fileinfo* imageInfo){

  //scans for empty space
  fscanf(inputFile, " ");

  /*check for a comment line*/
  char nextChar = fgetc(inputFile);
  if (nextChar == '#')
  {
    /*comment line*/
    //reads any comment (even those > 128)
    //assign array to store comment
    imageInfo-> commentLine = (char*)malloc(MAX_COMMENT_LINE_LENGTH);

    char *commentString = fgets(imageInfo->commentLine, MAX_COMMENT_LINE_LENGTH+2, inputFile);
    int length=0;
    length = (int)strlen(commentString);
    if(commentString == NULL){
      //invalid commentline
      //free memory
      free(imageInfo->commentLine);
      //close file pointer      
      fclose(inputFile);

      //print an error message 
      printf("Error: Bad Comment Line(%s)\n",fileName);

      //and exit with appropriate code
      exit(4);
    }

    if (length > 128){
      //the commentline is too large
      //free memory
      free(imageInfo->commentLine);
      //close file pointer
      fclose(inputFile);

      /*print an error message */
      printf("Error: Bad Comment Line(%s)\n",fileName);

      //return exit code
      exit(0);
    }
    //the commentline is not needed anymore
    //free memory 
    free(imageInfo->commentLine);
  }

  else{
    /*not a comment line*/
    /*put character back*/
    ungetc(nextChar, inputFile);
  }
  //succesfully read comment
  //return success code
  return EXIT_NO_ERRORS;
}
