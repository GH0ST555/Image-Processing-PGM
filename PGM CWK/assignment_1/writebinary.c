
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include"readcodes.h"

// function Takes outputFile , outputfileName and s struct that contains image data and using it to write into a BINARY pgm file
int writebfile(FILE*outputFile,char *fileName, struct Fileinfo* dataPointer){

/* write magic number, size & gray value */
size_t nBytesWritten = fprintf(outputFile, "P5\n%d %d\n%d\n", dataPointer->width, dataPointer->height, dataPointer->maxGray);

/* check that dimensions wrote correctly */
if (nBytesWritten < 0)
  {
     /* dimensional write failed    */
     /* free memory                   */
     free(dataPointer->imageData);

     /* print an error message        */
     printf("Error: Output Failed (%s)", fileName);

     /* return an error code          */
     return EXIT_BAD_OUTPUT_FILE;
  }
//loop to write the pixel data into output file
for(int pgmRow = 0; pgmRow < dataPointer -> height ; pgmRow++){
	for(int pgmCol = 0; pgmCol < dataPointer -> width ; pgmCol++){
    //writes pixel data into output file
    nBytesWritten = fwrite(&dataPointer->imageData[pgmRow][pgmCol],sizeof(unsigned char),1,outputFile);
  }
}

  /* at this point, we are done and can exit with a success code */
  return EXIT_NO_ERRORS;
}
