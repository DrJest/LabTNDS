LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

ALL=esercizio9
CC=g++ -std=c++11 -c

all: clean $(ALL)

clean:
	rm -f *~ *.o $(ALL)

esercizio9: esercizio9.cpp
	g++ -std=c++11 ${INCS} ${LIBS} esercizio9.cpp -o esercizio9

