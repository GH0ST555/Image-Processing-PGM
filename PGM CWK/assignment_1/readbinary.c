#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include <string.h>
#include "readcodes.h"


//funtion that takes input file pointer, fileName and a Struct as parameters to  read information from a binary PGM file
int  readbfile(FILE*inputFile,char *fileName, struct Fileinfo* dataPointer)
{
	//allocate memory to store pixel data
	dataPointer->imageData = (unsigned char **) malloc(dataPointer->height * sizeof(unsigned char *));

	fgetc(inputFile);
	  // Check if malloc function worked
	  if (dataPointer->imageData == NULL)
	  {
			//malloc has failed
			//free memory
			//print error message
	    printf("ERROR: Image Malloc Failed");
			//free pointer
	    free(dataPointer->imageData);
			//close the file
	    fclose(inputFile);
			//return exit code
	    exit(7);
	  }
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
		//nested for loop to assign pixel data to 2d array
		for(int pgmRow = 0; pgmRow < dataPointer -> height ; pgmRow++){
			for(int pgmCol = 0; pgmCol < dataPointer -> width ; pgmCol++){
				//integer to store+
				int lRead = fread(&dataPointer->imageData[pgmRow][pgmCol], sizeof(const char), 1, inputFile);
				if (lRead == 0 ){
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
			}
		}

		unsigned int extv;
		//scanf to store extra pixel into variable
		int chkExtv = fscanf(inputFile,"%u", &extv);
	  //integer to check if there are any unread pixels
	 if(chkExtv >0){
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
	//exit with success code
	return EXIT_NO_ERRORS;
}
