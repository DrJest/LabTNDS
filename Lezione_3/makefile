ALL=esercizio3.0 esercizio3.1 esercizio3.2 esercizio3.3
CC=g++ -std=c++11 -c

all: clean $(ALL)

esercizio3.0: Posizione.o esercizio3.0.o
	g++ $^ -o $@
	
esercizio3.1: PosizioneR.o esercizio3.0.o
	g++ $^ -o $@
	
esercizio3.2: Particella.o Elettrone.o CorpoCeleste.o esercizio3.2.o
	g++ $^ -o $@
	
esercizio3.3: Particella.o Posizione.o Elettrone.o CorpoCeleste.o esercizio3.3.o
	g++ $^ -o $@

Posizione.o: Posizione.cxx Posizione.hpp
	$(CC) $< -o $@

PosizioneR.o: PosizioneR.cxx Posizione.hpp
	$(CC) $< -o $@
	
Particella.o: Particella.cxx Particella.hpp
	$(CC) $< -o $@
		
Elettrone.o: Elettrone.cxx Elettrone.hpp
	$(CC) $< -o $@
		
CorpoCeleste.o: CorpoCeleste.cxx CorpoCeleste.hpp
	$(CC) $< -o $@
	
clean:
	rm -f *~ *.o $(ALL)
