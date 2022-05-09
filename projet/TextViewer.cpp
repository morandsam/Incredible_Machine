#include<iostream>
#include "TextViewer.h"
#include "Systeme.h"
#include "Balle.h"
#include "Pendule.h"
#include "Ressort.h"
#include "Plan.h"
#include "Portion_plan.h"
#include "Brique.h"
#include "ChampForces.h"
#include "Ventilateur.h"
#include "Vent.h"

using namespace std;

void TextViewer::dessine(Systeme const& systeme)
{
    systeme.affiche(cout,false);
}

void TextViewer::dessine(Balle const& balle)
{
    cout<<balle;
}
void TextViewer::dessine(Pendule const& pendule)
{
    cout<<pendule;
}
void TextViewer::dessine(Ressort const& ressort)
{
    cout<<ressort;
}
void TextViewer::dessine(Plan const& plan)
{
    cout<<plan;
}
void TextViewer::dessine(Portion_plan const& portion_plan)
{
    cout<<portion_plan;
}
void TextViewer::dessine(Brique const& brique)
{
    cout<<brique;
}
void TextViewer::dessine(ChampForces const& champforces)
{
    cout<<champforces;
}
void TextViewer::dessine(Ventilateur const& ventilateur)
{
    cout<<ventilateur;
}

void TextViewer::dessine(Vent const& vent)
{
    cout<<vent;
}