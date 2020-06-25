#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;

class PlayerObj : public sf::Drawable {
    float speed = 0.1f;
    float xspeed = 0;
    float yspeed = 0;
    sf::CircleShape shape;
public:

    PlayerObj() {
        shape.setRadius(50.f);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(100,100);
        shape.setOrigin(50,50);
    }
    void update(){
        shape.move(xspeed,yspeed);
    }
    sf::Vector2f getPosition(){
        return shape.getPosition();
    }

    void onEvent(sf::Event & event){
        if ( event.type == sf::Event::KeyPressed ){
            if ( event.key.code == sf::Keyboard::S )
                yspeed = speed;
            if ( event.key.code == sf::Keyboard::W )
                yspeed = -speed;
            if ( event.key.code == sf::Keyboard::A )
                xspeed = -speed;
            if ( event.key.code == sf::Keyboard::D )
                xspeed = speed;
            if ( event.key.code == sf::Keyboard::P )
                test();
        }
        if ( event.type == sf::Event::KeyReleased ){
            if ( event.key.code == sf::Keyboard::S )
                yspeed = 0;
            if ( event.key.code == sf::Keyboard::W )
                yspeed = 0;
            if ( event.key.code == sf::Keyboard::A )
                xspeed = 0;
            if ( event.key.code == sf::Keyboard::D )
                xspeed = 0;
        }
    }

    void draw(sf::RenderTarget & target, sf::RenderStates states) const{
        target.draw(shape);
    }

    void test() const{
        cout << "Pozitia curenta " << shape.getPosition().x << " " << shape.getPosition().y << endl;
    }
};

class Projectile : public sf ::Drawable {
    float speed = 0.1f;
    float xspeed = 0.1f;
    float yspeed = 0.f;
    sf::RectangleShape shape;
public:
    bool active = true;
    Projectile() {
    shape.setSize(sf::Vector2f(10,10));
    shape.setOrigin(5,5);
    shape.setFillColor(sf::Color::Cyan);
    }
 void draw(sf::RenderTarget & target, sf::RenderStates states) const{
        target.draw(shape);
    }
    void update(){
        shape.move(xspeed, yspeed);
        if ( shape.getPosition().x > 800 ){
            bool active = false;
        }
    }
    void setPosition(sf::Vector2f pos){
        shape.setPosition(pos);
    }
    /*
     void onEvent(sf::Event & event){
        if ( event.type == sf::Event::KeyPressed ){
            if ( event.key.code == sf::Keyboard::K ){
                yspeed = 0;
                xspeed = 0;
            }
        }
     }
     */
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setKeyRepeatEnabled(false);

    PlayerObj player;
    player.test();

    //Projectile * prarr[256];
    //int prindex = 0;

    std::vector<Projectile*> prvec;

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
            //pr.onEvent(event);
        }

        player.update();

        for (std::vector<Projectile*>::iterator it = prvec.begin() ; it != prvec.end(); ++it)
            (*it)->update();

        window.clear(sf::Color::White);
        window.draw(player);
        for (std::vector<Projectile*>::iterator it = prvec.begin() ; it != prvec.end(); ++it)
            window.draw(*(*it));
        window.display();
    }

    return 0;
}
