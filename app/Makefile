CXX=g++
CXXFLAGS=-Wall -g3
LDFLAGS=-lm
DEL=rm -fr

main: main.cpp funciones.o persona.o
	$(CXX) $(CXXFLAGS) -o app main.cpp funciones.o persona.o $(LDFLAGS)

personas.o: personas.h persona.cpp
	$(CXX) $(CXXFLAGS) -c persona.cpp

funciones.o: funciones.h funciones.cpp
	$(CXX) $(CXXFLAGS) -c funciones.cpp

clean:
	$(DEL) *.o app al

crear:
	mkdir -p al	
	touch al/mejoresPromedios.csv
	touch al/mejoresArtisticos.csv
	touch al/mejoresHumanistas.csv
	touch al/mejoresTecnicos.csv

.PHONY: dist
dist: crear main
	#mkdir -p bin
	#cp -r app bin/
	#cp estudiantes.csv bin/
	$(DEL) *.o
.PHONY: limpiar
limpiar: clean


