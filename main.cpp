#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Race.h"
#include "Peuple.h"
#include "Amazone.h"
#include "Elfe.h"
#include "Humain.h"
#include "Mage.h"
#include "Nain.h"
#include "Orc.h"

#include "PouvoirSpecial.h"
#include "Alchimistes.h"
#include "Armes.h"
#include "DesForets.h"
#include "Fortunes.h"
#include "Marchands.h"
#include "Volants.h"

#include "Joueur.h"

using namespace std;
using namespace sf;

    vector<Race> races;
    vector<PouvoirSpecial> pouvoirs;
    vector<Peuple> peuples;


void iniatiliserJeu()
{

    //Remplissage de la liste des races
    races.push_back(Amazone());
    races.push_back(Elfe());
    races.push_back(Humain());
    races.push_back(Nain());
    races.push_back(Mage());
    races.push_back(Orc());

    //Remplissage de la liste des pouvoirs speciaux
    pouvoirs.push_back(Alchimistes());
    pouvoirs.push_back(Armes());
    pouvoirs.push_back(DesForets());
    pouvoirs.push_back(Fortunes());
    pouvoirs.push_back(Marchands());
    pouvoirs.push_back(Volants());


    //6 Peuples (combinaisons Race + PouvoirSpecial) choisis au hasard
    srand(time(NULL)); // initialisation de rand
    int nbRacesDisponibles = races.size();
    int nbPouvoirsDisponibles = pouvoirs.size();
    int nombreAleatoireRaces;
    int nombreAleatoirePouvoirs;

    for(int i=0; i<6; i++)
    {
        nombreAleatoireRaces = rand()%nbRacesDisponibles;
        nombreAleatoirePouvoirs = rand()%nbPouvoirsDisponibles;
        peuples.push_back(Peuple(races.at(nombreAleatoireRaces), pouvoirs.at(nombreAleatoirePouvoirs)));
        races.erase(races.begin() + nombreAleatoireRaces);
        pouvoirs.erase(pouvoirs.begin() + nombreAleatoirePouvoirs);
        nbRacesDisponibles--;
        nbPouvoirsDisponibles--;
    }

    for(unsigned int i=0; i<peuples.size(); i++)
    {
        cout << "Nom numero " << i << " : " << peuples.at(i).toString() << endl;
    }

}

int initialiserSons()
{
    //Musique du jeu
    sf::Music music;
    if (!music.openFromFile("Sons/Music.ogg"))
        return -1;
    music.setLoop(true);
    music.play();
/*
    //Son court
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Sons/sound.wav"))
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    */

    return 0;
}


int main()
{
    iniatiliserJeu();
    //initialiserSons();


    Joueur joueur1;
    //Joueur joueur2;

    int choixPeuple;
    printf("Quel peuple ?\n");
    scanf("%d", &choixPeuple);
    printf("Votre choix : %d\n", choixPeuple);

    joueur1.nouveauPeupleActif(&peuples.at(choixPeuple));
    cout << joueur1.toString() << endl;



    sf::RenderWindow window(sf::VideoMode(1600, 689), "Small World");

    //Affichage map
    Texture textureMap;
    if (!textureMap.loadFromFile("Images/Map.jpg")) //1136 x 689
    {
        return -1;
    }
    Sprite spriteMap;
    spriteMap.setTexture(textureMap);
    window.draw(spriteMap);

    Font font;
    if (!font.loadFromFile("Mermaid1001.ttf"))
    {
        return -1;
    }


    Text texte;
    texte.setFont(font);
    texte.setCharacterSize(24);
    texte.setPosition(1150, 10);

    texte.setString("Peuples disponibles :\n");
    for(unsigned int i=0; i<peuples.size(); i++)
    {
        texte.setString(texte.getString() + peuples.at(i).toString() + "\n");
        //cout << "test : " << peuples.at(i).toString() << endl;
    }
    texte.setFillColor(Color::Yellow);
    window.draw(texte);




    window.display();

    while (window.isOpen())
    {
        //Détection d'évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            /*
            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "Une touche a ete actionnee" << std::endl;
                //sound.play();
            }
            */
        }

    }

 return 0;
}




