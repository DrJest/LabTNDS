ALL=esercizio7.0 esercizio7.1 esercizio7.2
CC=g++ -std=c++11 -c

all: clean $(ALL)

esercizio7.0: Integrate.o esercizio7.0.o
	g++ $^ -o $@

esercizio7.1: Integrate.o esercizio7.1.o
	g++ $^ -o $@

esercizio7.2: Integrate.o esercizio7.2.o
	g++ $^ -o $@

Integrate.o: Integrate.cxx Integrate.hpp
	$(CC) $< -o $@
	

clean:
	rm -f *~ *.o $(ALL)

