#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include "readcodes.h"

//function that checks and stores dimensions and maxGray
//uses input file pointer, fileName and struct as parameters
int chkstructure(FILE* inputFile, char*fileName,struct Fileinfo* imageInfo){
  //stores the number of items scanned 
  //also scans the width , height and maxgray
  int scanCount = fscanf(inputFile, " %u %u %u", &(imageInfo->width), &(imageInfo->height), &(imageInfo->maxGray));

  /* sanity checks on size & grays         */
  /* must read exactly three values        */
  if 	(
    (scanCount != 3				)	||
    (imageInfo->width 	< MIN_IMAGE_DIMENSION	) 	||
    (imageInfo->width 	> MAX_IMAGE_DIMENSION	) 	||
    (imageInfo->height < MIN_IMAGE_DIMENSION	) 	||
    (imageInfo->height > MAX_IMAGE_DIMENSION	))
    {
      /* failed size sanity check    */
      /* free up the memory            */
      /*close file pointer   */
      fclose(inputFile);

      /* print an error message */
      printf("ERROR: Bad Dimensions (%s)\n", fileName);

      /* and exit                    */
      exit(5);
    }
    else if(imageInfo->maxGray	!= 255		){
      // maxgray is invalid

      /* close file pointer   */
      fclose(inputFile);

      /* print an error message */
      printf("ERROR: Bad Max Gray Value (%s)\n", fileName);

      /* and exit with appropriate error code*/
      exit(6);
    }
    //the dimesions of the  file are valid
    //dimensions and maxgray are stored into the struct
    //return success code
    return 0;
}
