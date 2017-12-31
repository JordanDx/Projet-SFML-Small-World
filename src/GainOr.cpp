#include "GainOr.h"
#include <stdio.h>



using namespace std;

GainOr::GainOr()
{
    //ctor
}

GainOr::~GainOr()
{
    //dtor
}

int GainOr::calculerGainOr(vector<shared_ptr<Case>> cases, string race, string pouvoir)
{
    int gainOr = 0;
    for (unsigned int i=0; i<cases.size(); i++)
    {
        gainOr++;
        gainOr += specificationTalent((*cases.at(i)),pouvoir);

    }

    return gainOr;
}

int GainOr::specificationTalent(Case c, string pouvoir)
{
    int gainOr = 0;

    if(pouvoir == "Marchands")
    {
        gainOr++;
    }
    else if (pouvoir == "Alchimistes")
    {
        gainOr += 2;
    }
    else if (pouvoir == "DesMarais" && c.getTypeCase() == NETypeCase::Marais)
    {
        printf("DesMarais utilise\n");
    }
     else if (pouvoir == "DesForets" && c.getTypeCase() == NETypeCase::Foret)
    {
        printf("DesForets utilise\n");
    }




    return gainOr;
}
