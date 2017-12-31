#ifndef CASE_H
#define CASE_H

class Peuple;
#include <vector>
#include <memory>
#include "TypeCase.h"

class Case
{
    public:
        Case(NETypeCase::ETypeCase);
        void addVoisin(std::shared_ptr<Case> c);
        void casePrise(Peuple * p);
        Peuple * getPeuple();
        std::shared_ptr<Case> getVoisin(int i);
        int chercherVoisin(Case * c);
        std::vector<std::shared_ptr<Case>> getVoisins() const;
        void nouveauProprietaireCase(Peuple * nouveauPeuple, int nouveauNbUnites);
        int getDefense();
        NETypeCase::ETypeCase getTypeCase() const;

        virtual ~Case();

    protected:

    private:
        std::vector<std::shared_ptr<Case>> voisins;
        Peuple * peuple = 0;
        int nbUnites = 0;
        NETypeCase::ETypeCase typeCase;

};

#endif // CASE_H
