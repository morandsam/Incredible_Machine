CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall -g
LDLIBS = -lm

all: testVecteur clean

testVecteur: testVecteur.o Vecteur.o

testVecteur.o: testVecteur.cpp
Vecteur.o: Vecteur.cpp Vecteur.h


clean:
	@-rm *.o

