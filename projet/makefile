CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall -g
LDLIBS = -lm

all: testObstacle clean

testVecteur: testVecteur.o Vecteur.o
testPendule: testPendule.o Pendule.o Vecteur.o ObjetMobile.o ChampForces.o Integrateur.o Integrateur_EC.o Balle.o Objets.o
testBalle: testBalle.o Balle.o Vecteur.o ChampForces.o ObjetMobile.o Objets.o
testIntegrateur1: testIntegrateur1.o Integrateur.o Balle.o Integrateur_EC.o Objets.o ObjetMobile.o Vecteur.o Pendule.o 
testIntegrateur2: testIntegrateur2.o Integrateur.o Integrateur_E.o ObjetMobile.o Vecteur.o Balle.o ChampForces.o Integrateur_EC.o Pendule.o Objets.o
testObstacle: testObstacle.o Obstacles.o Vecteur.o Balle.o Brique.o Plan.o Portion_plan.o ChampForces.o ObjetMobile.o Objets.o

Balle.o: Balle.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Obstacles.h ChampForces.h
Brique.o: Brique.cpp Brique.h Portion_plan.h Plan.h Obstacles.h Objets.h Vecteur.h ObjetMobile.h ChampForces.h
ChampForces.o: ChampForces.cpp Vecteur.h ObjetMobile.h Objets.h Obstacles.h ChampForces.h
Integrateur.o: Integrateur.cpp Integrateur.h Vecteur.h Pendule.h ObjetMobile.h Objets.h Obstacles.h ChampForces.h Balle.h
Integrateur_E.o: Integrateur_E.cpp Integrateur.h Vecteur.h Pendule.h ObjetMobile.h Objets.h Obstacles.h ChampForces.h Balle.h Integrateur_E.h
Integrateur_EC.o: Integrateur_EC.cpp Integrateur.h Vecteur.h Pendule.h ObjetMobile.h Objets.h Obstacles.h ChampForces.h Balle.h Integrateur_EC.h
ObjetMobile.o: ObjetMobile.cpp ObjetMobile.h Vecteur.h Objets.h Obstacles.h ChampForces.h
Objets.o: Objets.cpp Objets.h Vecteur.h ObjetMobile.h Obstacles.h ChampForces.h
Obstacles.o: Obstacles.cpp Obstacles.h Objets.h Vecteur.h ObjetMobile.h ChampForces.h
Pendule.o: Pendule.cpp Pendule.h ObjetMobile.h Vecteur.h Objets.h Obstacles.h ChampForces.h Integrateur.h Balle.h Integrateur_EC.h
Plan.o: Plan.cpp Plan.h Obstacles.h Objets.h Vecteur.h ObjetMobile.h ChampForces.h Brique.o
Portion_plan.o: Portion_plan.cpp Portion_plan.h Plan.h Obstacles.h Objets.h Vecteur.h ObjetMobile.h ChampForces.h
testBalle.o: testBalle.cpp Balle.h Objets.h ObjetMobile.h Vecteur.h Obstacles.h ChampForces.h
testIntegrateur1.o: testIntegrateur1.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Obstacles.h ChampForces.h Integrateur.h Pendule.h Integrateur_EC.h
testIntegrateur2.o: testIntegrateur2.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Obstacles.h ChampForces.h Integrateur.h Pendule.h Integrateur_E.h Integrateur_EC.h
testPendule.o: testPendule.cpp Vecteur.h Pendule.h ObjetMobile.h Objets.h Obstacles.h ChampForces.h Integrateur.h Balle.h
testObstacle.o: testObstacle.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Brique.h Portion_plan.h Plan.h Obstacles.h ChampForces.h
testVecteur.o: testVecteur.cpp Vecteur.h
Vecteur.o: Vecteur.cpp Vecteur.h


clean:
ifdef OS
	@del *.o 
else
	@rm *.o 
endif

