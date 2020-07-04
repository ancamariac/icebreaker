#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include <ScoreText.hpp>
#include <Projectile.hpp>
#include <Ship.hpp>

#include <Globals.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    window.setKeyRepeatEnabled(false);

    Globals::init();

    Ship ship;
    ship.setPosition(50,50);

    //PlayerObj player;

    //std::vector<Projectile*> prvec;

    ScoreText scoreText;

    sf::Color clearColor(32,32,32);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            /*
            if ( event.type == sf::Event::KeyPressed){
                            if ( event.key.code == sf::Keyboard::P ){
                Projectile * newPr = new Projectile();
                //newPr->setPosition(getPosition());
                Globals::getPrvec()->push_back(newPr);
                std::cout << "Added to globals";
            }
            }*/
            //player.onEvent(event);
            ship.onEvent(event);
        }

        //player.update();
        ship.update();

        for (std::vector<Projectile*>::iterator it = Globals::getPrvec()->begin() ; it != Globals::getPrvec()->end(); ++it)
            (*it)->update();

        window.clear(clearColor);
        window.draw(ship);
        //window.draw(player);
        for (std::vector<Projectile*>::iterator it = Globals::getPrvec()->begin() ; it != Globals::getPrvec()->end(); ++it)
            window.draw(*(*it));
        window.draw(scoreText);

        window.display();
    }

    return 0;
}
