#include "../include/Peuple.h"

using namespace std;
#include <algorithm>
#include <stdio.h>

Peuple::Peuple(Race race, PouvoirSpecial pouvoir) : race(race), pouvoir(pouvoir)
{
    nbUnites = race.getNbUnites() + pouvoir.getNbUnites();
    nbUnitesUtilisables = nbUnites;
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

int Peuple::getNbUnitesUtilisables() const
{
    return nbUnitesUtilisables;
}

void Peuple::setNbUnitesUtilisables(int nouveauNb)
{
    nbUnitesUtilisables = nouveauNb;
}

int Peuple::getNumeroTour() const
{
    return numeroTour;
}

void Peuple::ajouterCase(std::shared_ptr<Case> caseAjoutee)
{
    cases.push_back(caseAjoutee);
}

bool Peuple::verificationCaseVoisine(std::shared_ptr<Case> caseVerifiee)
{
    if(std::find(casesAttaquables.begin(), casesAttaquables.end(), caseVerifiee) != casesAttaquables.end())

    {
        return true;
    }
    return false;
}

//Premier tour : cases attaquables = bords du plateau
void Peuple::premiereAttaque(Plateau plateau)
{
    numeroTour++;
    for(unsigned int i=0; i<plateau.getBords().size(); i++)
    {
        casesAttaquables.push_back(plateau.getBords().at(i));
    }
}

//Apres premiere attaque, cases attaquables deviennent les voisins de la premiere case attaquee
void Peuple::finPremiereAttaque(std::shared_ptr<Case> premiereCaseAttaquee)
{
    casesAttaquables.clear();
    for(unsigned int i=0; i<premiereCaseAttaquee->getVoisins().size(); i++)
    {
        casesAttaquables.push_back(premiereCaseAttaquee->getVoisin(i));
    }
}

void Peuple::enleverCase(std::shared_ptr<Case>caseEnlevee)
{
    for(unsigned int i=0; i<cases.size(); i++)
    {
        if(cases.at(i) == caseEnlevee)
        {
            cases.erase(cases.begin() + i);
            return;
        }
    }

}

vector<shared_ptr<Case>> Peuple::getCases()
{

    return cases;
}

string Peuple::getRace() const
{
    return race.getNom();
}

string Peuple::getPouvoir() const
{
    return pouvoir.getNom();
}


