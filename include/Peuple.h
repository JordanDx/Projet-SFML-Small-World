#ifndef PEUPLE_H
#define PEUPLE_H

#include "Races/Race.h"
#include "Pouvoirs/PouvoirSpecial.h"

class Peuple
{
    public:
        Peuple(Race race, PouvoirSpecial pouvoir);
        virtual ~Peuple();
        std::string toString() const;
        void incrementerNbPieces();
        int getNbPieces() const;
        int getNbUnites() const;

    protected:

    private:
        Race race;
        PouvoirSpecial pouvoir;
        int nbPieces = 0;
        int nbUnites;

};

#endif // PEUPLE_H
