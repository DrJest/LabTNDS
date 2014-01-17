ALL=esercizio10.0
CC=g++ -std=c++11 -c

all: clean $(ALL)

esercizio10.0: CampoVettoriale.o Posizione.o Particella.o PuntoMateriale.o esercizio4.0.o
	g++ $^ -o $@
	

CampoVettoriale.o: CampoVettoriale.cxx CampoVettoriale.hpp
	$(CC) $< -o $@

Posizione.o: Posizione.cxx Posizione.hpp
	$(CC) $< -o $@

Particella.o: Particella.cxx Particella.hpp
	$(CC) $< -o $@
	
PuntoMateriale.o: PuntoMateriale.cxx Particella.hpp
	$(CC) $< -o $@
	
clean:
	rm -f *~ *.o $(ALL)

