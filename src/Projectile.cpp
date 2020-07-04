#include "Projectile.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

Projectile::Projectile() {
    shape.setSize(sf::Vector2f(10,10));
    shape.setOrigin(5,5);
    shape.setFillColor(sf::Color::Cyan);
}

Projectile::Projectile(float angle) {
    shape.setSize(sf::Vector2f(10,10));
    shape.setOrigin(5,5);
    shape.setFillColor(sf::Color::Cyan);
    angle = angle * M_PI / 180.f;
    xspeed = cos(angle) / 5.f;
    yspeed = sin(angle) / 5.f;
}

void Projectile::draw(sf::RenderTarget & target, sf::RenderStates states) const{
    target.draw(shape);
}

void Projectile::update(){
    shape.move(xspeed, yspeed);
    if ( shape.getPosition().x > 800 ){
        bool active = false;
    }
}

void Projectile::setPosition(sf::Vector2f pos){
    shape.setPosition(pos);
}

