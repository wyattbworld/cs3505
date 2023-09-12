CARDIR = ./Carlib

car2: main.cpp $(CARDIR)/include/Car.h
	g++ -o car2 main.cpp -I$(CARDIR)/include -L$(CARDIR)/lib -lCar

car3: main.o $(CARDIR)/include/Car.h
	g++ -o car3 main.o -L$(CARDIR)/lib -lCar

Car: Car.cpp Car.h main.cpp
	g++ -o Car Car.cpp main.cpp

main.o: main.cpp $(CARDIR)/include/Car.h
	g++ -I$(CARDIR)/include -c main.cpp