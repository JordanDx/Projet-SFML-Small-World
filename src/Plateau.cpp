#include "Plateau.h"

#include <stdio.h>
#include "Peuple.h"

using namespace std;

Plateau::Plateau(){

  /*
    Case c;
    for (int i=0;i<30;i++){
        cases.push_back(c);
        if(i<17){
            bords.push_back(&cases[i]);
        }
        if(i==22){
            bords.push_back(&cases[i]);
        }
    }

*/


    shared_ptr<Case> case1(new Case(NETypeCase::Foret));
    shared_ptr<Case> case2(new Case(NETypeCase::Montagne));
    shared_ptr<Case> case3(new Case(NETypeCase::Marais));



    cases.push_back(case1);
    cases.push_back(case2);
    cases.push_back(case3);

    //Ajout bords
    bords.push_back(case1);
    bords.push_back(case3);



    //Ajout voisins.       (bord) 0 <=> 1 <=> 2 (bord)
    cases.at(0)->addVoisin(cases.at(1));

    cases.at(1)->addVoisin(cases.at(0));
    cases.at(1)->addVoisin(cases.at(2));

    cases.at(2)->addVoisin(cases.at(1));




    /*
    //case 1
    cases[0].addVoisin(&cases[1]);
    cases[0].addVoisin(&cases[16]);
    cases[0].addVoisin(&cases[15]);
    //case 2
    cases[1].addVoisin(&cases[0]);
    cases[1].addVoisin(&cases[2]);
    cases[1].addVoisin(&cases[16]);
    cases[1].addVoisin(&cases[17]);
    //case 3
    cases[2].addVoisin(&cases[1]);
    cases[2].addVoisin(&cases[3]);
    cases[2].addVoisin(&cases[17]);
    cases[2].addVoisin(&cases[19]);
    //case 4
    cases[3].addVoisin(&cases[2]);
    cases[3].addVoisin(&cases[4]);
    cases[3].addVoisin(&cases[18]);
    cases[3].addVoisin(&cases[19]);
    //case 5
    cases[4].addVoisin(&cases[3]);
    cases[4].addVoisin(&cases[5]);
    cases[4].addVoisin(&cases[19]);
    cases[4].addVoisin(&cases[20]);
    //case 6
    cases[5].addVoisin(&cases[4]);
    cases[5].addVoisin(&cases[6]);
    cases[5].addVoisin(&cases[20]);
    //case 7
    cases[6].addVoisin(&cases[5]);
    cases[6].addVoisin(&cases[7]);
    cases[6].addVoisin(&cases[20]);
    cases[6].addVoisin(&cases[21]);
    //case 8
    cases[7].addVoisin(&cases[6]);
    cases[7].addVoisin(&cases[8]);
    cases[7].addVoisin(&cases[21]);
    cases[7].addVoisin(&cases[22]);
    //case 9
    cases[8].addVoisin(&cases[7]);
    cases[8].addVoisin(&cases[9]);
    cases[8].addVoisin(&cases[22]);
    //case 10
    cases[9].addVoisin(&cases[8]);
    cases[9].addVoisin(&cases[10]);
    cases[9].addVoisin(&cases[21]);
    cases[9].addVoisin(&cases[23]);
    cases[9].addVoisin(&cases[24]);
    //case 10
    cases[9].addVoisin(&cases[8]);
    cases[9].addVoisin(&cases[10]);
    cases[9].addVoisin(&cases[21]);
    cases[9].addVoisin(&cases[23]);
    cases[9].addVoisin(&cases[24]);
    //case 11
    cases[10].addVoisin(&cases[9]);
    cases[10].addVoisin(&cases[11]);
    cases[10].addVoisin(&cases[24]);
    cases[10].addVoisin(&cases[25]);
    //case 12
    cases[11].addVoisin(&cases[10]);
    cases[11].addVoisin(&cases[12]);
    cases[11].addVoisin(&cases[25]);
    cases[11].addVoisin(&cases[26]);
    //case 13
    cases[12].addVoisin(&cases[11]);
    cases[12].addVoisin(&cases[14]);
    cases[12].addVoisin(&cases[15]);
    cases[12].addVoisin(&cases[26]);
    //case 14
    cases[13].addVoisin(&cases[12]);
    cases[13].addVoisin(&cases[14]);
    //case 15
    cases[14].addVoisin(&cases[12]);
    cases[14].addVoisin(&cases[13]);
    cases[14].addVoisin(&cases[15]);
    cases[14].addVoisin(&cases[26]);
    cases[14].addVoisin(&cases[27]);
    //case 16
    cases[15].addVoisin(&cases[14]);
    cases[15].addVoisin(&cases[16]);
    cases[15].addVoisin(&cases[17]);
    cases[15].addVoisin(&cases[26]);
    cases[15].addVoisin(&cases[27]);
    //case 17
    cases[16].addVoisin(&cases[0]);
    cases[16].addVoisin(&cases[1]);
    cases[16].addVoisin(&cases[15]);
    cases[16].addVoisin(&cases[17]);
    //case 18
    cases[17].addVoisin(&cases[1]);
    cases[17].addVoisin(&cases[2]);
    cases[17].addVoisin(&cases[15]);
    cases[17].addVoisin(&cases[16]);
    cases[17].addVoisin(&cases[18]);
    cases[17].addVoisin(&cases[27]);
    //case 19
    cases[18].addVoisin(&cases[2]);
    cases[18].addVoisin(&cases[3]);
    cases[18].addVoisin(&cases[19]);
    cases[18].addVoisin(&cases[17]);
    cases[18].addVoisin(&cases[27]);
    cases[18].addVoisin(&cases[28]);
    //case 20
    cases[19].addVoisin(&cases[3]);
    cases[19].addVoisin(&cases[4]);
    cases[19].addVoisin(&cases[20]);
    cases[19].addVoisin(&cases[18]);
    cases[19].addVoisin(&cases[28]);
    cases[19].addVoisin(&cases[29]);
    //case 21
    cases[20].addVoisin(&cases[4]);
    cases[20].addVoisin(&cases[5]);
    cases[20].addVoisin(&cases[6]);
    cases[20].addVoisin(&cases[19]);
    cases[20].addVoisin(&cases[21]);
    cases[20].addVoisin(&cases[29]);
    //case 22
    cases[21].addVoisin(&cases[6]);
    cases[21].addVoisin(&cases[7]);
    cases[21].addVoisin(&cases[20]);
    cases[21].addVoisin(&cases[22]);
    cases[21].addVoisin(&cases[23]);
    //case 23
    cases[22].addVoisin(&cases[7]);
    cases[22].addVoisin(&cases[8]);
    cases[22].addVoisin(&cases[9]);
    cases[22].addVoisin(&cases[21]);
    cases[22].addVoisin(&cases[23]);
    //case 24
    cases[23].addVoisin(&cases[9]);
    cases[23].addVoisin(&cases[21]);
    cases[23].addVoisin(&cases[22]);
    cases[23].addVoisin(&cases[24]);
    cases[23].addVoisin(&cases[29]);
    //case 25
    cases[24].addVoisin(&cases[9]);
    cases[24].addVoisin(&cases[10]);
    cases[24].addVoisin(&cases[23]);
    cases[24].addVoisin(&cases[25]);
    cases[24].addVoisin(&cases[28]);
    cases[24].addVoisin(&cases[29]);
    //case 26
    cases[25].addVoisin(&cases[10]);
    cases[25].addVoisin(&cases[11]);
    cases[25].addVoisin(&cases[26]);
    cases[25].addVoisin(&cases[24]);
    cases[25].addVoisin(&cases[28]);
    //case 27
    cases[26].addVoisin(&cases[11]);
    cases[26].addVoisin(&cases[12]);
    cases[26].addVoisin(&cases[14]);
    cases[26].addVoisin(&cases[25]);
    cases[26].addVoisin(&cases[27]);
    cases[26].addVoisin(&cases[28]);
    //case 28
    cases[27].addVoisin(&cases[13]);
    cases[27].addVoisin(&cases[14]);
    cases[27].addVoisin(&cases[15]);
    cases[27].addVoisin(&cases[17]);
    cases[27].addVoisin(&cases[18]);
    cases[27].addVoisin(&cases[28]);
    //case 29
    cases[28].addVoisin(&cases[17]);
    cases[28].addVoisin(&cases[18]);
    cases[28].addVoisin(&cases[23]);
    cases[28].addVoisin(&cases[24]);
    cases[28].addVoisin(&cases[25]);
    cases[28].addVoisin(&cases[27]);
    cases[28].addVoisin(&cases[29]);
    //case 30
    cases[29].addVoisin(&cases[19]);
    cases[29].addVoisin(&cases[20]);
    cases[29].addVoisin(&cases[21]);
    cases[29].addVoisin(&cases[22]);
    cases[29].addVoisin(&cases[23]);
    cases[29].addVoisin(&cases[28]);
*/

}




std::shared_ptr<Case> Plateau::getCase(int i) const{

    printf("test a\n");

    // Case * retourCase = cases.at(i);
     //retourCase->test();

     std::shared_ptr<Case> retourCase =  cases.at(i);

    return retourCase;
}


std::vector<std::shared_ptr<Case>> Plateau::getCases(){
    return cases;
}

std::vector<std::shared_ptr<Case>> Plateau::getBords(){
    return bords;
}


Plateau::~Plateau(){
    /*
   for(int i=0; i<cases.size(); i++)
   {
       delete cases[i];
   }
    for(int i=0; i<bords.size(); i++)
   {
       delete bords[i];
   }
   */
}
