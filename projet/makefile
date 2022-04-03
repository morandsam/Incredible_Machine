CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall -g
LDLIBS = -lm

all: exerciceP9a clean

exerciceP9a: exerciceP9a.o Vecteur.o Balle.o Integrateur_E.o Integrateur_EC.o ChampForces.o ObjetMobile.o Obstacles.o Brique.o Plan.o Portion_plan.o Pendule.o Ressort.o TextViewer.o Systeme.o 
testVecteur: testVecteur.o Vecteur.o
testPendule: testPendule.o Pendule.o Vecteur.o ObjetMobile.o ChampForces.o Integrateur.o Integrateur_EC.o 
testBalle: testBalle.o Balle.o Vecteur.o ChampForces.o ObjetMobile.o Objets.o
testIntegrateur1: testIntegrateur1.o Integrateur.o Balle.o Integrateur_EC.o Objets.o ObjetMobile.o Vecteur.o Pendule.o 
testIntegrateur2: testIntegrateur2.o Integrateur.o Integrateur_E.o ObjetMobile.o Vecteur.o Balle.o ChampForces.o Integrateur_EC.o Pendule.o Objets.o
testObstacle: testObstacle.o Obstacles.o Vecteur.o Balle.o Brique.o Plan.o Portion_plan.o ChampForces.o ObjetMobile.o Objets.o
testRessort: testRessort.o Ressort.o Vecteur.o ObjetMobile.o ChampForces.o Integrateur.o Integrateur_E.o Integrateur_EC.o 

Balle.o: Balle.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Systeme.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h
Brique.o: Brique.cpp Brique.h Portion_plan.h Plan.h Obstacles.h Objets.h Vecteur.h Dessinable.h SupportADessin.h Systeme.h Balle.h ObjetMobile.h Pendule.h Ressort.h
ChampForces.o: ChampForces.cpp Vecteur.h ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h ChampForces.h
Dessinable.o: Dessinable.cpp Dessinable.h SupportADessin.h Systeme.h Objets.h Vecteur.h Balle.h ObjetMobile.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h
exerciceP9a.o: exerciceP9a.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Integrateur_E.h Integrateur.h Integrateur_EC.h ChampForces.h Systeme.h Obstacles.h TextViewer.h
Integrateur.o: Integrateur.cpp Integrateur.h Vecteur.h ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h
Integrateur_E.o: Integrateur_E.cpp Integrateur.h Vecteur.h ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h Integrateur_E.h
Integrateur_EC.o: Integrateur_EC.cpp Integrateur.h Vecteur.h ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h Integrateur_EC.h
ObjetMobile.o: ObjetMobile.cpp ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h
Objets.o: Objets.cpp Objets.h Vecteur.h Dessinable.h SupportADessin.h Systeme.h Balle.h ObjetMobile.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h
Obstacles.o: Obstacles.cpp Obstacles.h Objets.h Vecteur.h Dessinable.h SupportADessin.h Systeme.h Balle.h ObjetMobile.h Pendule.h Ressort.h Plan.h Portion_plan.h Brique.h
Pendule.o: Pendule.cpp Pendule.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h
Plan.o: Plan.cpp Plan.h Obstacles.h Objets.h Vecteur.h Dessinable.h SupportADessin.h Systeme.h Balle.h ObjetMobile.h Pendule.h Ressort.h Portion_plan.h Brique.h
Portion_plan.o: Portion_plan.cpp Portion_plan.h Plan.h Obstacles.h Objets.h Vecteur.h Dessinable.h SupportADessin.h Systeme.h Balle.h ObjetMobile.h Pendule.h Ressort.h Brique.h
Ressort.o: Ressort.cpp Ressort.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Pendule.h Plan.h Obstacles.h Portion_plan.h Brique.h
SupportADessin.o: SupportADessin.cpp SupportADessin.h Systeme.h Dessinable.h Objets.h Vecteur.h Balle.h ObjetMobile.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h
Systeme.o: Systeme.cpp Systeme.h Dessinable.h SupportADessin.h Balle.h ObjetMobile.h Vecteur.h Objets.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h
testBalle.o: testBalle.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Systeme.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h ChampForces.h
testIntegrateur1.o: testIntegrateur1.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Systeme.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h Integrateur.h Integrateur_EC.h
testIntegrateur2.o: testIntegrateur2.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Systeme.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h Integrateur.h Integrateur_E.h Integrateur_EC.h ChampForces.h
testObstacle.o: testObstacle.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h SupportADessin.h Systeme.h Pendule.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h ChampForces.h
testPendule.o: testPendule.cpp Vecteur.h Pendule.h ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Ressort.h Plan.h Obstacles.h Portion_plan.h Brique.h Integrateur.h Integrateur_EC.h ChampForces.h
testRessort.o: testRessort.cpp Vecteur.h Ressort.h ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Systeme.h Balle.h Pendule.h Plan.h Obstacles.h Portion_plan.h Brique.h Integrateur.h Integrateur_EC.h ChampForces.h
testVecteur.o: testVecteur.cpp Vecteur.h
TextViewer.o: TextViewer.cpp TextViewer.h SupportADessin.h Systeme.h Dessinable.h ObjetMobile.h Vecteur.h Objets.h Obstacles.h Integrateur.h Balle.h Pendule.h Ressort.h Plan.h Portion_plan.h Brique.h
Vecteur.o: Vecteur.cpp Vecteur.h


clean:
ifdef OS
	@del *.o 
else
	@rm *.o 
endif

