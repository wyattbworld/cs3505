#@author C Wyatt Bruchhauser
#@date September 12, 2023
#Professor: David Johnson
#Class: CS3505 - Software Practice II
#Assignment: HW3 Facades and Makefiles
#Organization: University of Utah Kalhert School of Computing

CC = g++
CFLAGS = -Wall

sinePDF : HaruPDF.cpp HaruPDF.h sinePDF.cpp
	$(CC) $(CFLAGS) -o sinePDF HaruPDF.cpp sinePDF.cpp

HaruPDF.o : HaruPDF.h HaruPDF.cpp
	$(CC) $(CFLAGS) -c HaruPDF.cpp

sinePDF.o : sinePDF.cpp
	$(CC) $(CFLAGS) -c sinePDF.cpp

clean:
	rm *.o