CC=g++
ALL=esercizio2.0 esercizio2.1 esercizio2.2

all: clean $(ALL)

esercizio2.2: esercizio2.2.o Vettore.o
	$(CC) $^ -o $@
	
Vettore.o: Vettore.cxx Vettore.hpp
	$(CC) -c $< -o $@

clean:
	rm -f *~ *.o $(ALL)

