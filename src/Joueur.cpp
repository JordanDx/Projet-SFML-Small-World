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
    delete peupleActif;
    delete peupleDeclin;
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

void Joueur::choisirNouveauPeuple(Partie * partie)
{
    //CHOIX CONSOLE
    unsigned int taillePeuples = partie->getPeuples().size();
    unsigned int choixPeuple = taillePeuples;
    printf("Quel peuple ?\n");
    while(choixPeuple >= taillePeuples)
    {
        scanf("%d", &choixPeuple);
    }

    if(choixPeuple >= taillePeuples)
    {
        printf("Choix impossible\n");
        return;
    }
    //////////////////////////////////////////


    //On pose une pièce du joueur sur chaque peuple au-dessus de celui choisi
    for(unsigned int i=0; i<choixPeuple; i++)
    {
        //(*partie->getPeuples()).at(i).incrementerNbPieces();
        partie->getPeuples().at(i)->incrementerNbPieces();
        nbPieces--;
    }

    nouveauPeupleActif(partie->getPeuples().at(choixPeuple));
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



void Joueur::debutTour(Partie * partie)
{
    unsigned int choix = 0;

    printf("====================\n");
    printf("==== DEBUT TOUR ====\n");
    printf("====================\n");
    if(peupleActif == 0)
    {
        partie->afficherPeuples();
        choisirNouveauPeuple(partie);
    }


    while(choix != 1 && choix != 2)
    {
        printf("1 - Passer en declin\n2- Attaquer ?\n");
        scanf("%d", &choix);
    }
    switch(choix)
    {
        case 1:
            printf("Vous avez choisi de passer en declin\n");
            passerEnDeclin();
            break;
        case 2:
            printf("Vous avez choisi d'attaquer\n");
            break;

    }


    cout << toString() << endl;




}

