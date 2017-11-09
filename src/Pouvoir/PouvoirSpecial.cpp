#include "../include/Pouvoir/PouvoirSpecial.h"
using namespace std;

PouvoirSpecial::PouvoirSpecial(string nom, int nbUnites) : nom(nom), nbUnites(nbUnites)
{
}

PouvoirSpecial::~PouvoirSpecial()
{
    //dtor
}

string PouvoirSpecial::getNom() const
{
    return nom;
}
