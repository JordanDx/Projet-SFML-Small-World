#include "../include/Peuple.h"

using namespace std;

Peuple::Peuple(Race race, PouvoirSpecial pouvoir) : race(race), pouvoir(pouvoir)
{
    nbUnites = race.getNbUnites() + pouvoir.getNbUnites();
   // nbUnites = race.getNbUnites();
}


Peuple::~Peuple()
{
    //dtor
}

string Peuple::toString() const
{
    return "Race : " + race.getNom() + " / Pouvoir : " + pouvoir.getNom();
}

void Peuple::incrementerNbPieces()
{
    nbPieces++;
}

int Peuple::getNbPieces() const
{
    return nbPieces;
}

int Peuple::getNbUnites() const
{
    return nbUnites;
}

