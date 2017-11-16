#ifndef PARTIE_H
#define PARTIE_H


#include "main.h"


class Partie
{
    public:
        Partie();
        virtual ~Partie();
        void iniatiliserJeu();
        int initialiserSons();
        void miseAJourPeuples(int rang);
        int lancerPartie();
        std::vector<Peuple*> getPeuples();
        void afficherPeuples();

    protected:

    private:
        std::vector<Race> racesMelangees;
        std::vector<PouvoirSpecial> pouvoirsMelanges;
        std::vector<Peuple*> peuples;
};

#endif // PARTIE_H
