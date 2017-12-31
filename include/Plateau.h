#ifndef PLATEAU_H
#define PLATEAU_H
#include <vector>
#include "Case.h"
#include <memory>

class Plateau
{
    public:
        Plateau();

        std::shared_ptr<Case> getCase(int i) const;
        std::vector<std::shared_ptr<Case>> getCases();
        std::vector<std::shared_ptr<Case>> getBords();

        virtual ~Plateau();

    protected:

    private:
      // std::vector<Case*> cases;
       //std::vector<Case*> bords;

       std::vector<std::shared_ptr<Case> > cases;
       std::vector<std::shared_ptr<Case> > bords;
};

#endif // PLATEAU_H
