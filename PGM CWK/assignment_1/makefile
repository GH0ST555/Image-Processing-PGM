CC=gcc
CCFLAGS = -g -std=c99 -fmax-errors=1 -Wall -Werror
MODULES= read.o write.o writebinary.o readbinary.o getmagicno.o checkstructure.o chkcomnt.o checkRW.o reducedRead.o
MAINS = pgmEcho.o pgmComp.o pgma2b.o pgmb2a.o pgmReduce.o pgmTile.o pgmAssemble.o
TARGETS=pgmEcho pgmComp pgma2b pgmb2a pgmReduce pgmTile pgmAssemble
all: ${MODULES}  ${MANIS} ${TARGETS}

clean:
	rm ${TARGETS} ${MANIS} ${MODULES} *.o
pgmEcho:	pgmEcho.o
	${CC} ${CCFLAGS} -o pgmEcho pgmEcho.o ${MODULES}
pgmComp:   pgmComp.o
	${CC} ${CCFLAGS} -o pgmComp pgmComp.o ${MODULES}
pgma2b:   pgma2b.o
	${CC} ${CCFLAGS} -o pgma2b pgma2b.o ${MODULES}
pgmb2a:   pgmb2a.o
	${CC} ${CCFLAGS} -o pgmb2a pgmb2a.o ${MODULES}
pgmReduce:   pgmReduce.o
		${CC} ${CCFLAGS} -o pgmReduce pgmReduce.o ${MODULES}
pgmTile:   pgmTile.o
		${CC} ${CCFLAGS} -o pgmTile pgmTile.o ${MODULES}
pgmAssemble:   pgmAssemble.o
				${CC} ${CCFLAGS} -o pgmAssemble pgmAssemble.o ${MODULES}
pgmEcho.o: pgmEcho.c  readcodes.h
			gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o pgmEcho.o pgmEcho.c
pgmComp.o: pgmComp.c  readcodes.h
			gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o pgmComp.o pgmComp.c
pgma2b.o: pgma2b.c  readcodes.h
			gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o pgma2b.o pgma2b.c
pgmb2a.o: pgmb2a.c  readcodes.h
			gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o pgmb2a.o pgmb2a.c
pgmReduce.o: pgmReduce.c  readcodes.h
						gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o pgmReduce.o pgmReduce.c
pgmAssemble.o: pgmAssemble.c  readcodes.h
												gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o pgmAssemble.o pgmAssemble.c
pgmTile.o: pgmTile.c  readcodes.h
			gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o pgmTile.o pgmTile.c
read.o: read.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o read.o read.c
write.o: write.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o write.o write.c

writebinary.o: writebinary.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o writebinary.o writebinary.c
readbinary.o: readbinary.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o readbinary.o readbinary.c
getmagicno.o: getmagicno.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o getmagicno.o getmagicno.c
chkcomnt.o: chkcomnt.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o chkcomnt.o chkcomnt.c
checkRW.o: checkRW.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o checkRW.o checkRW.c
checkstructure.o: checkstructure.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o checkstructure.o checkstructure.c
reducedRead.o: reducedRead.c  readcodes.h
		gcc -c -g -std=c99 -fmax-errors=1 -Wall -Werror -o reducedRead.o reducedRead.c
