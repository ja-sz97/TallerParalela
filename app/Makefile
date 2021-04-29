CXX=g++
CXXFLAGS=-Wall -g3
LDFLAGS=-lm
DEL=rm -fr

main: main.cpp funciones.o
	$(CXX) $(CXXFLAGS) -o app main.cpp funciones.o $(LDFLAGS)

funciones.o: funciones.h funciones.cpp
	$(CXX) $(CXXFLAGS) -c funciones.cpp

clean:
	$(DEL) *.o app

.PHONY: dist
dist: clean main
	$(DEL) *.o app

