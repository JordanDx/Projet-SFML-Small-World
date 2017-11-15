#include "../include/Races/Race.h"

using namespace std;

Race::Race(string nom, int nbUnites) : nom(nom), nbUnites(nbUnites)
{
}

Race::~Race()
{
    //dtor
}

string Race::getNom() const
{
    return nom;
}

int Race::getNbUnites() const
{
    return nbUnites;
}
