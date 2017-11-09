#ifndef RACE_H
#define RACE_H

#include <string>

class Race
{
    public:
        Race(std::string nom, int nbUnites);
        virtual ~Race();
        std::string getNom() const;

    protected:

    private:
        std::string nom;
        int nbUnites;
};

#endif // RACE_H
