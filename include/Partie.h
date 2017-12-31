#ifndef PARTIE_H
#define PARTIE_H


#include "main.h"
#include "Plateau.h"
using namespace sf;
using namespace std;

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
        Plateau getPlateau() const;

    protected:

    private:
        std::vector<Race> racesMelangees;
        std::vector<PouvoirSpecial> pouvoirsMelanges;
        std::vector<Peuple*> peuples;
        Plateau plateau;
};

#endif // PARTIE_H
