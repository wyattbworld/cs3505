#@author C Wyatt Bruchhauser
#@date September 12, 2023
#Professor: David Johnson
#Class: CS3505 - Software Practice II
#Assignment: HW3 Facades and Makefiles
#Organization: University of Utah Kalhert School of Computing

CC = g++
CFLAGS = -Wall
LIBHARU = ./libharu

sinePDF : HaruPDF.o sinePDF.o
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -o sinePDF HaruPDF.o sinePDF.o -L$(LIBHARU)/src/ -lhpdfs

HaruPDF.o : HaruPDF.h HaruPDF.cpp
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c HaruPDF.cpp -L$(LIBHARU)/src/ -lhpdfs

sinePDF.o : sinePDF.cpp
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c sinePDF.cpp -L$(LIBHARU)/src/ -lhpdfs

clean:
	rm sinePDF *.o

test:
	./sinePDF