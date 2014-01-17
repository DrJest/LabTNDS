CC=g++
ALL=esercizio1.0 esercizio1.1 esercizio1.2 esercizio1.3 esercizio1.4

all: clean $(ALL)

esercizio1.1: esercizio1.1.cpp esercizio1.1.cxx esercizio1.1.hpp
	$(CC) esercizio1.1.cpp esercizio1.1.cxx -o esercizio1.1

esercizio1.2: esercizio1.2.cpp esercizio1.1.cxx esercizio1.1.hpp
	$(CC) esercizio1.2.cpp esercizio1.1.cxx -o esercizio1.2

esercizio1.3: esercizio1.3.cpp esercizio1.3.cxx esercizio1.3.hpp
	$(CC) esercizio1.3.cpp esercizio1.3.cxx -o esercizio1.3

esercizio1.4: esercizio1.4.cpp esercizio1.4.cxx esercizio1.4.hpp
	$(CC) esercizio1.4.cpp esercizio1.4.cxx -o esercizio1.4

clean:
	rm -f *~ *.o $(ALL)
