CC=gcc
CFLAGS=-I.

shaemake: shaegine.o
	$(CC) -o shaegine shaegine.o
