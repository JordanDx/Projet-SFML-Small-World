#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
}

Joueur::~Joueur()
{
}


void Joueur::nouveauPeupleActif(Peuple * nouveauPeuple)
{
    peupleActif = nouveauPeuple;
}


void Joueur::ajouterPieces(int nbPiecesAjoutees)
{
    nbPieces += nbPiecesAjoutees;
}

int Joueur::getNbPieces() const
{
    return nbPieces;
}

void Joueur::passerEnDeclin()
{
    peupleDeclin = peupleActif;
}


string Joueur::toString()
{
    string texte;
    texte.append("Nombre pieces : " + nbPieces);
    texte.append("Peuple actif : " + peupleActif->toString());

    if(peupleDeclin != 0)
        texte.append("Peuple en declin : " + peupleDeclin->toString());
    else
        texte.append("Peuple en declin : aucun");

    return texte;
}

