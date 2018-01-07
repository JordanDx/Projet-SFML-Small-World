#include "../include/Partie.h"


using namespace std;
using namespace sf;

Partie::Partie()
{

}

Partie::~Partie()
{

    for(unsigned int i=1; i<peuples.size(); i++)
    {
      delete peuples.at(i);
    }

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
        peuples.push_back(new Peuple(racesMelangees.at(0), pouvoirsMelanges.at(0)));
        racesMelangees.erase(racesMelangees.begin());
        pouvoirsMelanges.erase(pouvoirsMelanges.begin());
    }
}

int Partie::initialiserSons()
{
    //Musique du jeu
    //sf::Music music;
    if (!music.openFromFile("./Sons/Music.ogg"))
        return -1;
    music.setLoop(true);

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
    peuples.push_back(new Peuple(racesMelangees.at(0), pouvoirsMelanges.at(0)));
    racesMelangees.erase(racesMelangees.begin());
    pouvoirsMelanges.erase(pouvoirsMelanges.begin());
}



vector<Peuple*> Partie::getPeuples()
{
    return  peuples;
}


void Partie::afficherPeuples()
{
     for(unsigned int i=0; i<peuples.size(); i++)
    {
        cout << "Nom numero " << i << " : " << peuples.at(i)->toString();
        cout << " / nbUnites : " << peuples.at(i)->getNbUnites() << endl;
    }
}

Plateau Partie::getPlateau() const
{
    return plateau;
}


int Partie::lancerPartie()
{
    RenderWindow window;
    window.create(VideoMode(1280,720), "SmallWorld");
    Texture texture_carte;
    Sprite carte;

    if(!texture_carte.loadFromFile("./Images/Map.png"))
    {
        cout << "An error occurred." << endl;
    }
    else
    {
        carte.setTexture(texture_carte);
    }


    iniatiliserJeu();
    initialiserSons();
    music.play();




    unsigned int numeroTour = 0;
    unsigned int nbToursTotal = 2;
    unsigned int nbJoueurs = 2;

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(carte);

        window.display();

        //Création des joueurs
        for(unsigned int i=0; i<nbJoueurs; i++)
        {
            joueurs.push_back(Joueur());
        }


        while(numeroTour < nbToursTotal)
        {
            for(unsigned int i=0; i<nbJoueurs; i++)
            {
                //afficherPeuples();
                joueurs.at(i).debutTour(this);

            }

            numeroTour++;
        }

    }



 return 0;
}

