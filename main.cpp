#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include <ScoreText.hpp>
#include <PlayerObj.hpp>
#include <Projectile.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setKeyRepeatEnabled(false);

    PlayerObj player;

    std::vector<Projectile*> prvec;

    ScoreText scoreText;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            player.onEvent(event);

            if ( event.type == sf::Event::KeyPressed ){
                if ( event.key.code == sf::Keyboard::F ){
                    Projectile * newPr = new Projectile();
                    newPr->setPosition(player.getPosition());
                    prvec.push_back(newPr);
                }
            }
        }

        player.update();

        for (std::vector<Projectile*>::iterator it = prvec.begin() ; it != prvec.end(); ++it)
            (*it)->update();

        window.clear(sf::Color::White);
        window.draw(player);
        for (std::vector<Projectile*>::iterator it = prvec.begin() ; it != prvec.end(); ++it)
            window.draw(*(*it));
        window.draw(scoreText);
        window.display();
    }

    return 0;
}
