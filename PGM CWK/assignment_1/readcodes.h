#ifndef read_c
#define readcodes_h
#define ECHOED 0
#define  FILES_DIFFERENT  0
#define FILES_IDENTICAL  0
#define EXIT_NO_ERRORS 0
#define BAD_MAGIC_NUMBER 3
#define BAD_COMMENT_LINE 4
#define BAD_DIMENSIONS 5
#define BAD_MAX_GREY_VALUE 6
#define IMAGE_MALLOC_FAILED 7
#define BAD_DATA 8
#define BAD_FILE_NAME 2
#define MAGIC_NUMBER_RAW_PGM 0x3550
#define MAGIC_NUMBER_ASCII_PGM 0x3250
#define MIN_IMAGE_DIMENSION 1
#define MAX_IMAGE_DIMENSION 65535
#define MAX_COMMENT_LINE_LENGTH 128
#define EXIT_WRONG_ARG_COUNT 1
#define EXIT_BAD_INPUT_FILE 2
#define EXIT_BAD_OUTPUT_FILE 3
//struct which is uses pointers to store image data
struct Fileinfo{
  char *filename;
/* the magic number		         */
/* stored as two bytes to avoid	         */
    /* problems with endianness	         */
    /* Raw:    0x5035 or P5		         */
    /* ASCII:  0x5032 or P2		         */
  unsigned char magic_number[2];
  /* we will store ONE comment	         */
  char *commentLine;

  /* the logical width & height	         */
  /* note: cannot be negative	         */
  unsigned int width;
  unsigned int height;

  /* maximum gray value (assumed)	         */
  /* make it an integer for ease	         */
  unsigned int maxGray;

  /* pointer to raw image data	         */
  unsigned char **imageData;

};
//defining the read and write functions in the header files so that they can be called in the main program
int  readfile(FILE*inputFile,char *fileName,struct Fileinfo* id);
int writefile(FILE*outputFile,char *fileName, struct Fileinfo* id);
int writebfile(FILE*outputFile,char *fileName, struct Fileinfo* id);
int  readbfile(FILE*inputFile,char *fileName, struct Fileinfo* id);
int getmno(FILE* inputFile, char*fileName,struct Fileinfo* id);
int chkcom(FILE* inputFile, char*fileName,struct Fileinfo* id);
int chkstructure(FILE* inputFile, char*fileName,struct Fileinfo* id);
int checkread(FILE* inputFile,char* fileName);
int reducedRead(struct Fileinfo* id,struct Fileinfo* ri,int reductionFac);
int checkwrite(FILE* inputFile,char* fileName,struct Fileinfo* id);

#endif
