#ifndef JOUEUR_H
#define JOUEUR_H

#include "Peuple.h"

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

    protected:

    private:
        int nbPieces = 5;
        Peuple * peupleActif = 0;
        Peuple * peupleDeclin = 0;
};

#endif // JOUEUR_H