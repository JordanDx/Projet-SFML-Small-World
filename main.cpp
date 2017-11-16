#include "include/main.h"

using namespace sf;
using namespace std;

int main()
{
    // Create the main window
    RenderWindow window;
    window.create(VideoMode(1280,720), "SmallWorld");

    // Texture ans Sprites for the main menu

    Texture texture_fond, texture_play, texture_exit;
    Sprite fond,exit,play;
    // Checking for loading errors

    if(!texture_fond.loadFromFile("./Images/background.png"))
    {
        cout << "An error occurred." << endl;
    }
    else
    {
       fond.setTexture(texture_fond);
    }

    if(!texture_exit.loadFromFile("./Images/exit.png"))
    {
        cout << "An error occurred." << endl;
    }
    else
    {
        exit.setTexture(texture_exit);
        exit.setPosition(390,370);

    }

    if(!texture_play.loadFromFile("./Images/play.png"))
    {
        cout << "An error occurred." << endl;
    }
    else
    {
        play.setTexture(texture_play);
        play.setPosition(390,100);
    }



    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(fond);
        window.draw(play);
        window.draw(exit);

        window.display();

        if(Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2<int> T=Mouse::getPosition();
            if(T.x>=390 && T.x<=890)
            {
                if(T.y>=100 && T.y<=350)
                {
                    window.close();
                    Partie partie;
                    partie.lancerPartie();
                }
                else if (T.y>370 && T.y<=620)
                {
                    window.close();
                }
            }
        }
    }


    return EXIT_SUCCESS;
}
