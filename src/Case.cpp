#include "Case.h"
#include "Peuple.h"
#include <stdio.h>

using namespace std;

Case::Case(NETypeCase::ETypeCase typeCase) : typeCase(typeCase)
{


}

Case::~Case(){
    /*
    delete peuple;
    for(vector<Case *>::iterator i = voisins.begin(); i!=voisins.end(); ++i){
        delete *i;
    }
    */

}

void Case::addVoisin(std::shared_ptr<Case> c){
    voisins.push_back(c);
}

void Case::casePrise(Peuple * p){
    peuple = p;
}

Peuple * Case::getPeuple(){
    return peuple;
}


std::shared_ptr<Case> Case::getVoisin(int i){
    vector<std::shared_ptr<Case>>::iterator it = voisins.begin();
    advance(it,i);
    return *it;
}

int Case::getDefense()
{
    int defense = nbUnites;
    return defense;
}

void Case::nouveauProprietaireCase(Peuple * nouveauPeuple, int nouveauNbUnites)
{
    if(peuple != 0)
    {
        peuple->setNbUnitesUtilisables(peuple->getNbUnitesUtilisables() + nbUnites - 1);

    }
    peuple = nouveauPeuple;
    nbUnites = nouveauNbUnites;
}

std::vector<std::shared_ptr<Case>> Case::getVoisins() const
{
    return voisins;
}

NETypeCase::ETypeCase Case::getTypeCase() const
{
    return typeCase;
}
