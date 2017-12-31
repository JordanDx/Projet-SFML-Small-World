#ifndef JOUEUR_H
#define JOUEUR_H

#include "Peuple.h"
#include <vector>
#include "GainOr.h"

class Partie;


class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();
        void nouveauPeupleActif(Peuple * nouveauPeuple);
        void ajouterPieces(int nbPiecesAjoutees);
        int getNbPieces() const;
        std::string toString();
        void passerEnDeclin();
        void choisirNouveauPeuple(Partie * partie);
        void debutTour(Partie * partie);
        void attaquer(std::shared_ptr<Case> caseAttaquee);
        void finTour();


    protected:

    private:
        int nbPieces = 5;
        Peuple * peupleActif = 0;
        Peuple * peupleDeclin = 0;
        void boucleAttaquer(Partie * partie);
        GainOr gainOr;

};

#endif // JOUEUR_H
