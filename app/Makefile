CXX=g++
CXXFLAGS=-Wall -g3
LDFLAGS=-lm
DEL=rm -fr

main: main.cpp funciones.o personas.o
	$(CXX) $(CXXFLAGS) -o app main.cpp funciones.o personas.o $(LDFLAGS)

personas.o: personas.h personas.cpp
	$(CXX) $(CXXFLAGS) -c personas.cpp

funciones.o: funciones.h funciones.cpp
	$(CXX) $(CXXFLAGS) -c funciones.cpp


clean:
	$(DEL) *.o app

.PHONY: dist
dist: clean main
	$(DEL) *.o #app

