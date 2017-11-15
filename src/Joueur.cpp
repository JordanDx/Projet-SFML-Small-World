#include "../include/Joueur.h"
#include <stdio.h>
#include <sstream>
#include "Partie.h"



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
    peupleActif = 0;
}


 void Joueur::choisirNouveauPeuple(Partie * partie, vector<Peuple> & peuples)
{
    //CHOIX CONSOLE
    int choixPeuple = peuples.size();
    printf("Quel peuple ?\n");
    while(choixPeuple >= peuples.size())
    {
        scanf("%d", &choixPeuple);
        printf("Votre choix : %d\n", choixPeuple);
    }
    //////////////////////////////////////////


    if(choixPeuple >= peuples.size())
    {
        printf("Choix impossible\n");
        return;
    }


    //On pose une pièce du joueur sur chaque peuple au-dessus de celui choisi
    for(int i=0; i<choixPeuple; i++)
    {
        peuples.at(i).incrementerNbPieces();
        nbPieces--;
    }

    nouveauPeupleActif(&peuples.at(choixPeuple));
    nbPieces += peupleActif->getNbPieces(); //Gagne les pièces qui sont potentiellement sur le peuple choisi

    //Mise à jour de la liste des peuples.
    partie->miseAJourPeuples(choixPeuple);
}




string Joueur::toString()
{
    string texte;
    string nbPiecesStr;
    stringstream ssPieces;
    ssPieces << nbPieces;


    texte.append("Nombre pieces : ");
    texte.append(ssPieces.str() + "\n");
    texte.append("Peuple actif : ");
    if(peupleActif != 0)
    {
        texte.append(peupleActif->toString() + ".\n");
    }
    else
        texte.append("aucun.\n");
    texte.append("Peuple en declin : ");
    if(peupleDeclin != 0)
    {
        texte.append(peupleDeclin->toString() + ".\n");
    }
    else
        texte.append("aucun.\n");

    return texte;
}


