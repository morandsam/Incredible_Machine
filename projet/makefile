CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
LDLIBS = -lm

all: Vecteur clean

Vecteur: Vecteur.h Vecteur.o

Vecteur.o: Vecteur.cpp Vecteur.h

clean:
	-del *.o