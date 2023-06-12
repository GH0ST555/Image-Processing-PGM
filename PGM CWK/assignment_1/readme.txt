TO Remove all object files and executables: make clean
TO Create all object files and executables: make all or  make

Intstructions before running testscript.sh:
1. change permissions to read only for the following pgm files: faliedwrite.pgm , nrbinary.pgm
2. use "make all" in the directory where all the .c files are contained 
3. run testscript.sh by typing ./testscript.sh to execute a set of tests to test each program
4. run "make clean" after testing to remove all object files and executables


To run specific programs:
pgmEcho-     ./pgmEcho inputImage.pgm outputImage.pgm
pgmComp-     ./pgmComp inputImage.pgm inputImage.pgm
pgma2b-      ./pgma2b inputImage.pgm outputImage.pgm
pgmb2a-      ./pgmb2a inputImage.pgm outputImage.pgm
pgmReduce-   ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm
pgmTile-     ./pgmTile inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm
pgmAssemble- ./pgmAssemble outputImage.pgm width height (row column inputImage.pgm)+
