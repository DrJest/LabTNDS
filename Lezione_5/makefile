ALL=esercizio5.1 esercizio5.2 esercizio5.3
CC=g++ -std=c++11 -c

all: clean $(ALL)

esercizio5.1: Parabola.o esercizio5.1.o
	g++ $^ -o $@
	
esercizio5.2: Bisezione.o Parabola.o Retta.o esercizio5.2.o
	g++ $^ -o $@
	
esercizio5.3: Bisezione.o Parabola.o Buca.o esercizio5.3.o
	g++ $^ -o $@
	
Parabola.o: Parabola.cxx Parabola.hpp FunzioneBase.hpp
	$(CC) $< -o $@
	
Bisezione.o: Bisezione.cxx Bisezione.hpp Solutore.hpp
	$(CC) $< -o $@
	
Retta.o: Retta.cxx Retta.hpp FunzioneBase.hpp
	$(CC) $< -o $@
	
Buca.o: Buca.cxx Buca.hpp FunzioneBase.hpp
	$(CC) $< -o $@
	
clean:
	rm -f *~ *.o $(ALL)


