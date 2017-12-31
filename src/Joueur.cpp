#include "../include/Joueur.h"
#include <stdio.h>
#include <sstream>
#include "../include/Partie.h"



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
    printf("Vous gagnez %d pieces d'or.\n", peupleActif->getNbPieces());

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


    while(choix < 1 || choix > 3)
    {
        printf("1 - Passer en declin\n2 - Attaquer\n3 - Passer tour\n");
        scanf("%u", &choix);
    }
    switch(choix)
    {
        case 1:
            printf("Vous avez choisi de passer en declin\n");
            passerEnDeclin();
            break;
        case 2:
            unsigned int continuerAttaquer = 0;
            while(continuerAttaquer == 0)
            {
                boucleAttaquer(partie);
                printf("Attaquer de nouveau ?\n0 - Oui\nAutre - Non\n");
                scanf("%u", &continuerAttaquer);
            }
            break;

    }

    finTour();
}

void Joueur::boucleAttaquer(Partie * partie)
{
       int choixCaseAttaquee = 0;
        printf("Quelle case attaquer ?\n");
        scanf("%d", &choixCaseAttaquee);
        std::shared_ptr<Case> caseAttaquee = (partie->getPlateau()).getCase(choixCaseAttaquee);

        if(peupleActif->getNumeroTour() == 0)
        {
            peupleActif->premiereAttaque(partie->getPlateau());
        }
        attaquer(caseAttaquee);
}

void Joueur::attaquer(std::shared_ptr<Case> caseAttaquee)
{
    if(peupleActif == caseAttaquee->getPeuple())
    {
        printf("Un peuple actif ne peut pas s'attaquer lui-meme.\n");
        return;
    }

    //Nb unites a utiliser = minimum 2, +1 pour chaque soldat ennemi
    int nbUnitesUtilisees = 2;
    if (caseAttaquee->getPeuple() != 0)
    {
        nbUnitesUtilisees += caseAttaquee->getDefense();
        printf("Nombre unites a utiliser : %d\n", nbUnitesUtilisees);

    }

    //Verification si la case attaquee est voisine d'une des notres
    if(peupleActif->verificationCaseVoisine(caseAttaquee))
    {
        //Attaque reussie
        if(peupleActif->getNbUnitesUtilisables() >= nbUnitesUtilisees)
        {
            //Ennemi perd sa case et nous la gagnons + perte soldats
            peupleActif->ajouterCase(caseAttaquee);
            peupleActif->setNbUnitesUtilisables(peupleActif->getNbUnitesUtilisables()- nbUnitesUtilisees);
            caseAttaquee->nouveauProprietaireCase(peupleActif, nbUnitesUtilisees);


            //Si premiere attaque du peuple => cases attaquables deviennent uniquement voisins de la case attaquee
            if(peupleActif->getNumeroTour() == 0)
            {
                peupleActif->finPremiereAttaque(caseAttaquee);
            }
        }
        else
        {
            cout << "Pas assez d'unites." << endl;
        }
    }
    else
    {
        cout << "Cette case n'est pas voisine de votre peuple actif." << endl;
    }
}


void Joueur::finTour()
{

    printf("==================\n");
    printf("==== FIN TOUR ====\n");
    printf("==================\n");

    printf("Nombre unites peuple actif : %d\n", peupleActif->getNbUnites());
    printf("Nombre unites utilisables peuple actif : %d\n", peupleActif->getNbUnitesUtilisables());


    int orGagne = gainOr.calculerGainOr(peupleActif->getCases(), peupleActif->getRace(), peupleActif->getPouvoir());
    printf("Or gagne ce tour ci : %d\n", orGagne);

    nbPieces += orGagne;

    cout << toString() << endl;

}

