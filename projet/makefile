CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall -g
LDLIBS = -lm

all: testVecteur testBalle testPendule clean

testVecteur: testVecteur.o Vecteur.o
testBalle: testBalle.o Balle.o Vecteur.o ChampForces.o ObjetMobile.o
testPendule: testPendule.o Pendule.o Vecteur.o ObjetMobile.o ChampForces.o Integrateur.o

Balle.o: Balle.cpp Balle.h ObjetMobile.h Vecteur.h
testBalle.o: testBalle.cpp Balle.h ObjetMobile.h Vecteur.h ChampForces.h
testVecteur.o: testVecteur.cpp Vecteur.h
Vecteur.o: Vecteur.cpp Vecteur.h
ObjetMobile.o: ObjetMobile.cpp ObjetMobile.h Vecteur.h
ChampForces.o: ChampForces.cpp Vecteur.h ObjetMobile.h ChampForces.h
Integrateur.o: Integrateur.cpp Integrateur.h Vecteur.h Pendule.h ObjetMobile.h
Pendule.o: Pendule.cpp Pendule.h ObjetMobile.h Vecteur.h Integrateur.h 
testPendule.o: testPendule.cpp Vecteur.h Pendule.h ObjetMobile.h Integrateur.h

clean:
ifdef OS
	@del *.o 
else
	@rm *.o 
endif

