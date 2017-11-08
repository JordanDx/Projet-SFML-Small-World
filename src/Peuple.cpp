#include "Peuple.h"
using namespace std;

Peuple::Peuple(Race race, PouvoirSpecial pouvoir) : race(race), pouvoir(pouvoir)
{
}


Peuple::~Peuple()
{
    //dtor
}

string Peuple::toString() const
{
    return "Race : " + race.getNom() + " / " + "Pouvoir : " + pouvoir.getNom();
}

void Peuple::augmenterNbPieces()
{
    nbPieces++;
}


