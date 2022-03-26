CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall -g
LDLIBS = -lm

all: testVecteur testBalle testPendule testIntegrateur1 testIntegrateur2 clean

testVecteur: testVecteur.o Vecteur.o
testBalle: testBalle.o Balle.o Vecteur.o ChampForces.o ObjetMobile.o
testPendule: testPendule.o Pendule.o Vecteur.o ObjetMobile.o ChampForces.o Integrateur.o Integrateur_EC.o
testIntegrateur1: testIntegrateur1.o Integrateur.o Integrateur_EC.o ObjetMobile.o Vecteur.o Balle.o
testIntegrateur2: testIntegrateur2.o Integrateur.o Integrateur_E.o ObjetMobile.o Vecteur.o Balle.o ChampForces.o Integrateur_EC.o

Balle.o: Balle.cpp Balle.h ObjetMobile.h Vecteur.h
testBalle.o: testBalle.cpp Balle.h ObjetMobile.h Vecteur.h ChampForces.h
testVecteur.o: testVecteur.cpp Vecteur.h
Vecteur.o: Vecteur.cpp Vecteur.h
ObjetMobile.o: ObjetMobile.cpp ObjetMobile.h Vecteur.h
ChampForces.o: ChampForces.cpp Vecteur.h ObjetMobile.h ChampForces.h
Integrateur.o: Integrateur.cpp Integrateur.h Vecteur.h Pendule.h ObjetMobile.h Balle.h
Integrateur_EC.o: Integrateur_EC.cpp Integrateur.h Vecteur.h Pendule.h ObjetMobile.h Integrateur_EC.h
Integrateur_E.o: Integrateur_E.cpp Integrateur.h Vecteur.h Pendule.h ObjetMobile.h Integrateur_E.h
Pendule.o: Pendule.cpp Pendule.h ObjetMobile.h Vecteur.h Integrateur.h Integrateur_EC.h
testPendule.o: testPendule.cpp Vecteur.h Pendule.h ObjetMobile.h Integrateur.h
testIntegrateur1.o: testIntegrateur1.cpp Balle.h ObjetMobile.h Vecteur.h Integrateur.h Pendule.h Integrateur_EC.h
testIntegrateur2.o: testIntegrateur2.cpp Balle.h ObjetMobile.h Vecteur.h Integrateur.h Pendule.h Integrateur_E.h ChampForces.h Integrateur_EC.h

clean:
ifdef OS
	@del *.o 
else
	@rm *.o 
endif

