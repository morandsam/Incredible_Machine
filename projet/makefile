CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall -g
LDLIBS = -lm

all: bac_a_sable clean

bac_a_sable: bac_a_sable.o Vecteur.o Balle.o Integrateur_E.o Integrateur_EC.o Integrateur_RK4.o Integrateur_Newmark.o ChampForces.o ObjetMobile.o Obstacles.o Brique.o Plan.o Portion_plan.o Pendule.o PenduleSpherique.o Ressort.o TextViewer.o Systeme.o constantes.o Vent.o Ventilateur.o
exerciceP9a: exerciceP9a.o Vecteur.o Balle.o Integrateur_E.o Integrateur_EC.o Integrateur_RK4.o Integrateur_Newmark.o ChampForces.o ObjetMobile.o Obstacles.o Brique.o Plan.o Portion_plan.o Pendule.o Ressort.o TextViewer.o Systeme.o constantes.o Vent.o Ventilateur.o
testChocs: testChocs.o Vecteur.o Balle.o Integrateur_E.o Integrateur_EC.o Integrateur_RK4.o Integrateur_Newmark.o ChampForces.o ObjetMobile.o Obstacles.o Brique.o Plan.o Portion_plan.o Pendule.o Ressort.o TextViewer.o Systeme.o constantes.o Vent.o Ventilateur.o
testVecteur: testVecteur.o Vecteur.o
testPendule: testPendule.o Pendule.o Vecteur.o ObjetMobile.o ChampForces.o Integrateur.o Integrateur_EC.o Integrateur_E.o Integrateur_RK4.o Integrateur_Newmark.o constantes.o Systeme.o Obstacles.o
testPenduleSpherique: testPenduleSpherique.o PenduleSpherique.o Pendule.o Vecteur.o ObjetMobile.o ChampForces.o Integrateur.o Integrateur_EC.o Integrateur_E.o Integrateur_RK4.o Integrateur_Newmark.o constantes.o Systeme.o Obstacles.o
testBalle: testBalle.o Balle.o Vecteur.o ChampForces.o ObjetMobile.o Objets.o constantes.o Systeme.o Obstacles.o
testIntegrateur1: testIntegrateur1.o Integrateur.o Balle.o Integrateur_EC.o Integrateur_E.o Integrateur_RK4.o Integrateur_Newmark.o Objets.o ObjetMobile.o Vecteur.o Pendule.o constantes.o Systeme.o Obstacles.o
testIntegrateur2: testIntegrateur2.o Integrateur.o Integrateur_E.o Integrateur_RK4.o Integrateur_Newmark.o ObjetMobile.o Vecteur.o Balle.o ChampForces.o Integrateur_EC.o Pendule.o Objets.o constantes.o Systeme.o Obstacles.o
testObstacle: testObstacle.o Obstacles.o Vecteur.o Balle.o Brique.o Plan.o Portion_plan.o ChampForces.o ObjetMobile.o Objets.o constantes.o Systeme.o 
testRessort: testRessort.o Ressort.o Vecteur.o ObjetMobile.o ChampForces.o Integrateur.o Integrateur_E.o Integrateur_EC.o Integrateur_RK4.o Integrateur_Newmark.o constantes.o Systeme.o Obstacles.o
testVentilateur: testVentilateur.o Vecteur.o Balle.o ObjetMobile.o Obstacles.o Integrateur.o Integrateur_EC.o Integrateur_E.o Integrateur_RK4.o Integrateur_Newmark.o Objets.o ChampForces.o Vent.o Brique.o TextViewer.o Systeme.o Portion_plan.o Plan.o constantes.o Pendule.o Ressort.o Ventilateur.o


bac_a_sable.o: bac_a_sable.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h \
 Dessinable.h SupportADessin.h Pendule.h constantes.h PenduleSpherique.h \
 Ressort.h Integrateur_E.h Integrateur.h Integrateur_EC.h \
 Integrateur_Newmark.h Integrateur_RK4.h ChampForces.h TextViewer.h \
 Systeme.h Obstacles.h Plan.h Portion_plan.h Brique.h Ventilateur.h \
 Vent.h
Balle.o: Balle.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h Dessinable.h \
 SupportADessin.h Systeme.h Obstacles.h Integrateur.h ChampForces.h
Brique.o: Brique.cpp Brique.h Portion_plan.h Plan.h Obstacles.h Objets.h \
 Vecteur.h Dessinable.h SupportADessin.h ObjetMobile.h Systeme.h \
 Integrateur.h Balle.h ChampForces.h
ChampForces.o: ChampForces.cpp Vecteur.h ObjetMobile.h Objets.h \
 Dessinable.h SupportADessin.h Systeme.h Obstacles.h Integrateur.h \
 Balle.h ChampForces.h
constantes.o: constantes.cpp Vecteur.h constantes.h
exerciceP9a.o: exerciceP9a.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h \
 Dessinable.h SupportADessin.h Integrateur_E.h Integrateur.h \
 Integrateur_EC.h Integrateur_Newmark.h Integrateur_RK4.h ChampForces.h \
 TextViewer.h Systeme.h Obstacles.h constantes.h
Integrateur.o: Integrateur.cpp Integrateur.h Vecteur.h ObjetMobile.h \
 Objets.h Dessinable.h SupportADessin.h Balle.h
Integrateur_E.o: Integrateur_E.cpp Integrateur.h Vecteur.h ObjetMobile.h \
 Objets.h Dessinable.h SupportADessin.h Balle.h Integrateur_E.h \
 constantes.h
Integrateur_EC.o: Integrateur_EC.cpp Integrateur.h Vecteur.h \
 ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Balle.h \
 Integrateur_EC.h constantes.h
Integrateur_Newmark.o: Integrateur_Newmark.cpp Integrateur.h Vecteur.h \
 ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Balle.h \
 Integrateur_Newmark.h constantes.h
Integrateur_RK4.o: Integrateur_RK4.cpp Integrateur.h Vecteur.h \
 ObjetMobile.h Objets.h Dessinable.h SupportADessin.h Balle.h \
 Integrateur_RK4.h constantes.h
ObjetMobile.o: ObjetMobile.cpp ObjetMobile.h Vecteur.h Objets.h \
 Dessinable.h SupportADessin.h
Objets.o: Objets.cpp Objets.h Vecteur.h Dessinable.h SupportADessin.h
Obstacles.o: Obstacles.cpp Obstacles.h Objets.h Vecteur.h Dessinable.h \
 SupportADessin.h ObjetMobile.h
Pendule.o: Pendule.cpp Pendule.h ObjetMobile.h Vecteur.h Objets.h \
 Dessinable.h SupportADessin.h constantes.h Systeme.h Obstacles.h \
 Integrateur.h Balle.h ChampForces.h
PenduleSpherique.o: PenduleSpherique.cpp PenduleSpherique.h ObjetMobile.h \
 Vecteur.h Objets.h Dessinable.h SupportADessin.h Pendule.h constantes.h
Plan.o: Plan.cpp Plan.h Obstacles.h Objets.h Vecteur.h Dessinable.h \
 SupportADessin.h ObjetMobile.h Systeme.h Integrateur.h Balle.h \
 ChampForces.h
Portion_plan.o: Portion_plan.cpp Portion_plan.h Plan.h Obstacles.h \
 Objets.h Vecteur.h Dessinable.h SupportADessin.h ObjetMobile.h Systeme.h \
 Integrateur.h Balle.h ChampForces.h
Ressort.o: Ressort.cpp Ressort.h ObjetMobile.h Vecteur.h Objets.h \
 Dessinable.h SupportADessin.h Systeme.h Obstacles.h Integrateur.h \
 Balle.h ChampForces.h
Systeme.o: Systeme.cpp Systeme.h Dessinable.h ObjetMobile.h Vecteur.h \
 Objets.h SupportADessin.h Obstacles.h Integrateur.h Balle.h \
 ChampForces.h constantes.h
testBalle.o: testBalle.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h \
 Dessinable.h SupportADessin.h ChampForces.h constantes.h
testChocs.o: testChocs.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h \
 Dessinable.h SupportADessin.h Pendule.h constantes.h Ressort.h \
 Integrateur_E.h Integrateur.h Integrateur_EC.h Integrateur_Newmark.h \
 Integrateur_RK4.h ChampForces.h TextViewer.h Systeme.h Obstacles.h \
 Plan.h
testIntegrateur1.o: testIntegrateur1.cpp Balle.h ObjetMobile.h Vecteur.h \
 Objets.h Dessinable.h SupportADessin.h Integrateur.h Integrateur_EC.h \
 Integrateur_Newmark.h Integrateur_E.h Integrateur_RK4.h
testIntegrateur2.o: testIntegrateur2.cpp Balle.h ObjetMobile.h Vecteur.h \
 Objets.h Dessinable.h SupportADessin.h Integrateur.h Integrateur_E.h \
 Integrateur_EC.h Integrateur_Newmark.h Integrateur_RK4.h ChampForces.h \
 constantes.h
testObstacle.o: testObstacle.cpp Balle.h ObjetMobile.h Vecteur.h Objets.h \
 Dessinable.h SupportADessin.h Brique.h Portion_plan.h Plan.h Obstacles.h \
 ChampForces.h constantes.h
testPendule.o: testPendule.cpp Vecteur.h Pendule.h ObjetMobile.h Objets.h \
 Dessinable.h SupportADessin.h constantes.h Integrateur.h Balle.h \
 Integrateur_EC.h Integrateur_E.h Integrateur_Newmark.h Integrateur_RK4.h \
 ChampForces.h
testPenduleSpherique.o: testPenduleSpherique.cpp Vecteur.h \
 PenduleSpherique.h ObjetMobile.h Objets.h Dessinable.h SupportADessin.h \
 Pendule.h constantes.h Integrateur.h Balle.h Integrateur_EC.h \
 Integrateur_E.h Integrateur_Newmark.h Integrateur_RK4.h ChampForces.h
testRessort.o: testRessort.cpp Vecteur.h Ressort.h ObjetMobile.h Objets.h \
 Dessinable.h SupportADessin.h Integrateur.h Balle.h Integrateur_EC.h \
 Integrateur_Newmark.h Integrateur_RK4.h ChampForces.h constantes.h
testVecteur.o: testVecteur.cpp Vecteur.h
testVentilateur.o: testVentilateur.cpp Balle.h ObjetMobile.h Vecteur.h \
 Objets.h Dessinable.h SupportADessin.h Integrateur_EC.h Integrateur.h \
 Integrateur_E.h Integrateur_Newmark.h Integrateur_RK4.h ChampForces.h \
 TextViewer.h Systeme.h Obstacles.h Ventilateur.h Vent.h Brique.h \
 Portion_plan.h Plan.h constantes.h
TextViewer.o: TextViewer.cpp TextViewer.h SupportADessin.h Systeme.h \
 Dessinable.h ObjetMobile.h Vecteur.h Objets.h Obstacles.h Integrateur.h \
 Balle.h ChampForces.h Pendule.h constantes.h Ressort.h Plan.h \
 Portion_plan.h Brique.h Ventilateur.h Vent.h
Vecteur.o: Vecteur.cpp Vecteur.h
Vent.o: Vent.cpp Vent.h ChampForces.h Vecteur.h Objets.h Dessinable.h \
 SupportADessin.h ObjetMobile.h Systeme.h Obstacles.h Integrateur.h \
 Balle.h
Ventilateur.o: Ventilateur.cpp Ventilateur.h Vent.h ChampForces.h \
 Vecteur.h Objets.h Dessinable.h SupportADessin.h Brique.h Portion_plan.h \
 Plan.h Obstacles.h ObjetMobile.h Systeme.h Integrateur.h Balle.h

clean:
ifdef OS
	@del *.o 
else
	@rm *.o 
endif

