#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include"readcodes.h"


// function Takes file pointer , outputfileName and s struct that contains image data and using it to write into an ASCII pgm file
int writefile(FILE*outputFile,char *fileName, struct Fileinfo* dataPointer){
  //long nImageBytes = id->width * id->height * sizeof(unsigned char);
  /* write magic number, size & gray value */
  size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", dataPointer->width, dataPointer->height, dataPointer->maxGray);

  /* check that dimensions wrote correctly */
  if (nBytesWritten < 0)
  { /* dimensional write failed */
    /* free memory */
    free(dataPointer->imageData);

    /* print an error message */
    printf("Error: Output Failed (%s)\n", fileName);

    /* return an error code */
    exit(9);
  }
  //nested loop to write data into outputfile
  for(int pgmRow = 0; pgmRow < dataPointer -> height ; pgmRow++){
		for(int pgmCol = 0; pgmCol < dataPointer -> width ; pgmCol++){
      //prints pixel into outputFile
      nBytesWritten = fprintf(outputFile,"%d%c", dataPointer-> imageData[pgmRow][pgmCol], ' ');
      if (nBytesWritten < 0)
      { /* dimensional write failed */
        /* free memory */
        free(dataPointer->imageData);

        /* print an error message */
        printf("Error: Output Failed (%s)\n", fileName);

        /* return an error code */
        exit(9);
      }
    }
  }
  /* at this point, we are done and can exit with a success code */
  return EXIT_NO_ERRORS;
}
