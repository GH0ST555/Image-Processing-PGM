#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "readcodes.h"


//function that reads pixel values and stores them in the struct
//uses input file pointer, fileName and struct as parameters
int  readfile(FILE*inputFile,char *fileName,struct Fileinfo* dataPointer)
{
	/* allocate the data pointer*/
	long nImageBytes = dataPointer->width * dataPointer->height * sizeof(unsigned char);
	dataPointer->imageData = (unsigned char **) malloc(dataPointer->height * sizeof(unsigned char *));
	//vaiable to store number of pixels read
	int numberLinesRead = 0;

	/* sanity check for memory allocation    */
	if (dataPointer->imageData == NULL)
	{
		/* malloc failed */
		/* free up memory*/
		free(dataPointer->imageData);
		/* close file pointer*/
		fclose(inputFile);
		/* print an error message */
		printf("ERROR: Image Malloc Failed");
		/* return error code */
		exit(IMAGE_MALLOC_FAILED);
	}
	//loop to read each pixel value
	for (int pgmRow = 0; pgmRow < dataPointer -> height ; pgmRow++){
		dataPointer->imageData[pgmRow] = (unsigned char *) malloc(dataPointer->width * sizeof(unsigned char));
		if (dataPointer->imageData[pgmRow] == NULL)
		{
			/* malloc failed */
			/* free up memory*/
			free(dataPointer->imageData);
			/* close file pointer*/
			fclose(inputFile);
			/* print an error message */
			printf("ERROR: Image Malloc Failed");
			/* return error code */
			exit(IMAGE_MALLOC_FAILED);
		}
	}
	for(int pgmRow = 0; pgmRow < dataPointer -> height ; pgmRow++){
		for(int pgmCol = 0; pgmCol < dataPointer -> width ; pgmCol++){
			/* per gray value */
			/* read next value               */
			int grayValue = -1;
			int scanCount = fscanf(inputFile, " %u", &grayValue);

			/*sanity check*/
			if ((scanCount != 1) || (grayValue < 0) || (grayValue > 255))
			{
				/* fscanf failed */
				/* free memory */
				free(dataPointer->imageData);

				/* close file */
				fclose(inputFile);

				/* print error message */
				printf("ERROR: Bad Data (%s)\n", fileName);

				/* and return */
				exit(8);
			}

			/* set the pixel value           */
			dataPointer->imageData[pgmRow][pgmCol] = (unsigned short) grayValue;
			//increase the value by 1
			numberLinesRead++;
		}
	}

	//create int to store extra values
	unsigned int extv;
	//scanf to store extra pixel into variable
	int chkExtv = fscanf(inputFile,"%u", &extv);
	if (numberLinesRead<nImageBytes){
		//too little data
		//free memory
		free(dataPointer->imageData);
		//close file pointer
		fclose(inputFile);
		//print error message
		printf("ERROR: Bad Data (%s)\n",fileName);
		//return exit code
		exit(8);
	}
	else if(chkExtv >0){
		//too much data
		//free memory
		free(dataPointer->imageData);
		//close file pointer
		fclose(inputFile);
		//print error message
		printf("ERROR: Bad Data (%s)\n",fileName);
		//return exit code
		exit(8);
	}

	/* we're done with the file, so close it */
	fclose(inputFile);
	//return success code
	return EXIT_NO_ERRORS;
}
