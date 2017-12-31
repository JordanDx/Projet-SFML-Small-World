#ifndef GAINOR_H
#define GAINOR_H

#include <memory>
#include "Case.h"
#include <vector>
#include "Pouvoirs/PouvoirSpecial.h"

class GainOr
{
    public:
        GainOr();
        virtual ~GainOr();
        int calculerGainOr(std::vector<std::shared_ptr<Case>> cases, std::string race, std::string pouvoir);
        int specificationTalent(Case c, std::string pouvoir);

    protected:

    private:
};

#endif // GAINOR_H
