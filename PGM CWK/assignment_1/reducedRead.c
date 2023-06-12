#include <stdio.h>
#include "readcodes.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int reducedRead(struct Fileinfo* dataPointer,struct Fileinfo* dataPointer2,int reductionFac){
  //calculates and stores height of reduced file
  dataPointer2->height = (dataPointer->height/reductionFac);
  //calculates and stores width of reduced file
  dataPointer2->width = (dataPointer->width/reductionFac);
  //stores maxgray of reduced fille
  dataPointer2->maxGray = dataPointer->maxGray;
  //memory allocation to store pixel data of reduced file
  dataPointer2->imageData = (unsigned char**) malloc (dataPointer2->height * dataPointer2 ->width * sizeof(unsigned char*));
  //condition to check if the memory allocation failed
  if(dataPointer2->imageData == NULL){
    //memory allocation failed
    //free memory
    free(dataPointer->imageData);
    /* close file pointer*/
    //print error message
    printf("ERROR: Image Malloc Failed");
    /* return error code */
    exit(IMAGE_MALLOC_FAILED);
  }
  for (int pgmRow = 0; pgmRow < dataPointer -> height ; pgmRow++){
    dataPointer2->imageData[pgmRow] = (unsigned char *) malloc(dataPointer2->width * sizeof(unsigned char));
    if (dataPointer2->imageData[pgmRow] == NULL)
    {
      /* malloc failed */
      /* free up memory of both input and output file*/
      free(dataPointer->imageData);
      free(dataPointer2->imageData);

      /* print an error message */
      printf("ERROR: Image Malloc Failed");
      /* return error code */
      exit(IMAGE_MALLOC_FAILED);
    }
  }
  //integers to store the row and column number for the reduced file
  int reducedRow = 0;
  int reducedCol = 0;
  //nested loop to assign pixel data of reduced file
  for(int pgmRow = 0; pgmRow < dataPointer-> height ; pgmRow++)
  {
    if ((pgmRow%reductionFac )== 0)
    {
      for(int pgmCol = 0; pgmCol < dataPointer -> width ; pgmCol++)
      {
        if ((pgmCol%reductionFac )== 0)
        {
          //desirable pixel identfied
          //store pixel into reduced file
          dataPointer2->imageData[reducedRow][reducedCol] = dataPointer->imageData[pgmRow][pgmCol];
          reducedCol++;
        }
      }
      reducedRow++;
      reducedCol = 0;
    }
  }
//pixel data has been sucessfully assigned
//free memory
free(dataPointer->imageData);
//return success code
return EXIT_NO_ERRORS;
}
