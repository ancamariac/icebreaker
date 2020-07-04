#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>

class Projectile : public sf ::Drawable {
    float speed = 0.1f;
    float xspeed = 0.1f;
    float yspeed = 0.f;
    sf::RectangleShape shape;
public:
    bool active = true;
    Projectile();
    Projectile(float angle);
    void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    void update();
    void setPosition(sf::Vector2f pos);
};

#endif // PROJECTILE_HPP
