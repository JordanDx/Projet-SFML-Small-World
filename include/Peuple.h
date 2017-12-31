#ifndef PEUPLE_H
#define PEUPLE_H

#include "Races/Race.h"
#include "Pouvoirs/PouvoirSpecial.h"
#include "Case.h"
#include "Plateau.h"
#include <vector>


class Peuple
{
    public:
        Peuple(Race race, PouvoirSpecial pouvoir);
        virtual ~Peuple();
        std::string toString() const;
        void incrementerNbPieces();
        int getNbPieces() const;
        int getNbUnites() const;
        int getNbUnitesUtilisables() const;
        void setNbUnitesUtilisables(int nouveauNb);
        int getNumeroTour() const;
        void ajouterCase(std::shared_ptr<Case> caseAjoutee);
        bool verificationCaseVoisine(std::shared_ptr<Case> caseVerifiee);
        void premiereAttaque(Plateau plateau);
        void finPremiereAttaque(std::shared_ptr<Case> premiereAttaque);
        void enleverCase(std::shared_ptr<Case> caseEnlevee);
        std::vector<std::shared_ptr<Case>> getCases();
        std::string getRace() const;
        std::string getPouvoir() const;



    protected:

    private:
        Race race;
        PouvoirSpecial pouvoir;
        int nbPieces = 0;
        int nbUnites = 0;
        int nbUnitesUtilisables = 0;
        int numeroTour = 0;
        std::vector<std::shared_ptr<Case>> cases;
        std::vector<std::shared_ptr<Case>> casesAttaquables;

};

#endif // PEUPLE_H
