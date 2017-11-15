#include "../include/Joueur.h"
#include <stdio.h>
#include <sstream>



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

 void Joueur::choisirNouveauPeuple(vector<Peuple> & peuples)
{
    //CHOIX CONSOLE
    int choixPeuple;
    printf("Quel peuple ?\n");
    scanf("%d", &choixPeuple);
    printf("Votre choix : %d\n", choixPeuple);
    //////////////////////////////////////////


    //On pose une pièce du joueur sur chaque peuple au-dessus de celui choisi
    for(int i=0; i<choixPeuple; i++)
    {
        peuples.at(i).incrementerNbPieces();
        nbPieces--;
    }

    nouveauPeupleActif(&peuples.at(choixPeuple));
    nbPieces += peupleActif->getNbPieces(); //Gagne les pièces qui sont potentiellement sur le peuple choisi





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


