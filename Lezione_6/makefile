ALL=esercizio6.0 esercizio6.1 esercizio6.2 esercizio6.3
CC=g++ -std=c++11 -c

all: clean $(ALL)

esercizio6.0: Vettore.o esercizio6.0.o
	g++ $^ -o $@

esercizio6.1: Vettore.o VettoreDati.o esercizio6.1.o
	g++ $^ -o $@
	
esercizio6.2: Vettore.o VettoreDati.o esercizio6.2.o
	g++ $^ -o $@

esercizio6.3: Vettore.o VettoreDati.o esercizio6.3.o
	g++ $^ -o $@
	
Vettore.o: Vettore.cxx Vettore.hpp
	$(CC) $< -o $@
	
VettoreDati.o: VettoreDati.cxx VettoreDati.hpp Vettore.hpp
	$(CC) $< -o $@
	
esercizio6.1.o: esercizio6.1.cpp 
	$(CC) $< -o $@

esercizio6.2.o: esercizio6.2.cpp 
	$(CC) $< -o $@
clean:
	rm -f *~ *.o $(ALL)
