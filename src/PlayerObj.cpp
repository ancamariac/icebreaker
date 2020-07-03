#include "PlayerObj.hpp"

PlayerObj::PlayerObj(){
    shape.setRadius(50.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(100,100);
    shape.setOrigin(50,50);
}

void PlayerObj::update(){
    shape.move(xspeed,yspeed);
}

sf::Vector2f PlayerObj::getPosition(){
    return shape.getPosition();
}

void PlayerObj::onEvent(sf::Event & event){
    if ( event.type == sf::Event::KeyPressed ){
        if ( event.key.code == sf::Keyboard::S )
            yspeed = speed;
        if ( event.key.code == sf::Keyboard::W )
            yspeed = -speed;
        if ( event.key.code == sf::Keyboard::A )
            xspeed = -speed;
        if ( event.key.code == sf::Keyboard::D )
            xspeed = speed;
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

void PlayerObj::draw(sf::RenderTarget & target, sf::RenderStates states) const{
    target.draw(shape);
}
