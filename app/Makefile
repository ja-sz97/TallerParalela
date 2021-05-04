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
	mkdir -p al	
	touch mejoresPromedios.csv
	touch mejoresArtisticos.csv
	touch mejoresHumanistas.csv
	touch mejoresTecnicos.csv

	cp mejoresPromedios.csv al/
	cp mejoresArtisticos.csv al/
	cp mejoresHumanistas.csv al/
	cp mejoresTecnicos.csv al/

.PHONY: dist
dist: clean main
	#mkdir -p bin
	#cp -r app bin/
	#cp estudiantes.csv bin/
	$(DEL) *.o mejoresPromedios.csv mejoresArtisticos.csv mejoresHumanistas.csv mejoresTecnicos.csv
