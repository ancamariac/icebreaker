#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
    private:
        float speed = 0.1f;
        float xspeed = 0;
        float yspeed = 0;
        sf::Texture shipTex;

        sf::Vector2f velocity;
        const float friction = 0.999f;

        float turningSpeed = 0;
        const float turnFriction = 0.999f;

        bool W,A,S,D;
    public:
        void update();
        void onEvent(sf::Event & event);
        Ship();
};

#endif // SHIP_HPP
