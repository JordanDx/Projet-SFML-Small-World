#include "../include/Partie.h"


using namespace std;
using namespace sf;

Partie::Partie()
{
    //ctor
}

Partie::~Partie()
{
    //dtor
}

void Partie::iniatiliserJeu()
{

    vector<Race> races;
    vector<PouvoirSpecial> pouvoirs;

    //Remplissage de la liste des races
    races.push_back(Amazone());
    races.push_back(Elfe());
    races.push_back(Humain());
    races.push_back(Nain());
    races.push_back(Mage());
    races.push_back(Orc());
    races.push_back(HommeRat());

    //Remplissage de la liste des pouvoirs speciaux
    pouvoirs.push_back(Alchimistes());
    pouvoirs.push_back(Armes());
    pouvoirs.push_back(DesForets());
    pouvoirs.push_back(DesMarais());
    pouvoirs.push_back(Fortunes());
    pouvoirs.push_back(Marchands());
    pouvoirs.push_back(Volants());


    srand(time(NULL)); // initialisation de rand
    int nbRacesDisponibles = races.size();
    int nbPouvoirsDisponibles = pouvoirs.size();
    int nombreAleatoireRaces;
    int nombreAleatoirePouvoirs;
    int nombrePeuplesDisponibles = 3;

    //Melange des races
    for(int i=0; i<nbRacesDisponibles; i++)
    {
        nombreAleatoireRaces = rand()%races.size();
        racesMelangees.push_back(races.at(nombreAleatoireRaces));
        races.erase(races.begin() + nombreAleatoireRaces);
    }

    //Melange des pouvoirs
     for(int i=0; i<nbPouvoirsDisponibles; i++)
    {
        nombreAleatoirePouvoirs = rand()%pouvoirs.size();
        pouvoirsMelanges.push_back(pouvoirs.at(nombreAleatoirePouvoirs));
        pouvoirs.erase(pouvoirs.begin() + nombreAleatoirePouvoirs);
    }

    //Peuples (combinaisons Race + PouvoirSpecial) choisis au hasard que peuvent prendre les joueurs
    for(int i=0; i<nombrePeuplesDisponibles; i++)
    {
        peuples.push_back(Peuple(racesMelangees.at(0), pouvoirsMelanges.at(0)));
        racesMelangees.erase(racesMelangees.begin());
        pouvoirsMelanges.erase(pouvoirsMelanges.begin());
    }


    for(unsigned int i=0; i<peuples.size(); i++)
    {
        cout << "Nom numero " << i << " : " << peuples.at(i).toString() << endl;
    }

}

int Partie::initialiserSons()
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

void Partie::miseAJourPeuples(int rang)
{
    //Supression du peuple choisi dans peuples
    peuples.erase(peuples.begin() + rang);

    //Rajout d'un peuple
    peuples.push_back(Peuple(racesMelangees.at(0), pouvoirsMelanges.at(0)));
    racesMelangees.erase(racesMelangees.begin());
    pouvoirsMelanges.erase(pouvoirsMelanges.begin());
}

vector<Peuple> Partie::getPeuples() const
{
    return peuples;
}



int Partie::lancerPartie()
{
    iniatiliserJeu();
    //initialiserSons();
    Joueur joueur1;
    Joueur joueur2;
    unsigned int numeroTour = 0;
    unsigned int nbToursTotal = 2;


    /*
    while(numeroTour < nbToursTotal)
    {
        numeroTour++;
    }
*/

    //Nb unites des peuples
    for(unsigned int i=0; i<peuples.size(); i++)
    {
        cout << "Nb unites peuple num  " << i << " : " << peuples.at(i).getNbUnites() << endl;
    }

    joueur1.choisirNouveauPeuple(this, peuples);
    cout << joueur1.toString() << endl;



    //joueur2.choisirNouveauPeuple(peuples);
    //cout << joueur2.toString() << endl;

     for(unsigned int i=0; i<peuples.size(); i++)
    {
        cout << "Nom numero " << i << " : " << peuples.at(i).toString() << endl;
    }




/*
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
/*

        }

    }
*/

 return 0;
}

