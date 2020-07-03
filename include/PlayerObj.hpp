#ifndef PLAYEROBJ_HPP
#define PLAYEROBJ_HPP

#include <SFML/Graphics.hpp>

class PlayerObj : public sf::Drawable {
    float speed = 0.1f;
    float xspeed = 0;
    float yspeed = 0;
    sf::CircleShape shape;
public:
    PlayerObj();
    void update();
    sf::Vector2f getPosition();
    void onEvent(sf::Event & event);
    void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

#endif // PLAYEROBJ_HPP
