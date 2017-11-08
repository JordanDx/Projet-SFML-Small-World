#ifndef POUVOIRSPECIAL_H
#define POUVOIRSPECIAL_H

#include <string>

class PouvoirSpecial
{
    public:
        PouvoirSpecial(std::string nom, int nbUnites);
        virtual ~PouvoirSpecial();
        std::string getNom() const;

    protected:

    private:
        std::string nom;
        int nbUnites;
};

#endif // POUVOIRSPECIAL_H
