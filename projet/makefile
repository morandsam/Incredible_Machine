CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall -g
LDLIBS = -lm

all: testVecteur testBalle clean

testVecteur: testVecteur.o Vecteur.o
testBalle: testBalle.o Balle.o Vecteur.o ChampForces.o

Balle.o: Balle.cpp Vecteur.h Balle.h
testBalle.o: testBalle.cpp Balle.cpp Vecteur.h Balle.h
testVecteur.o: testVecteur.cpp Vecteur.h
Vecteur.o: Vecteur.cpp Vecteur.h
ChampForces.o: ChampForces.cpp Vecteur.h Balle.h ChampForces.h


clean:
ifdef OS
	@del *.o 
else
	@rm *.o 
endif

