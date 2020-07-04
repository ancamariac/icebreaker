#include "Ship.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include <Projectile.hpp>

#include <Globals.hpp>
#include <iostream>

Ship::Ship()
{
    W = A = S = D = false;
    shipTex.loadFromFile("assets/ship.png");
    setTexture(shipTex);
    setScale(4,4);

    sf::FloatRect bounds = getLocalBounds();
    setOrigin(bounds.width/2.f, bounds.height/2.f);
}

const float turnSpeed = 0.0001f;

void Ship::update(){
    //move(xspeed,yspeed);

    if ( D ) {
        turningSpeed += turnSpeed;
    }
    if ( A ) {
        turningSpeed -= turnSpeed;
    }

    if ( W ) {
        float angle = getRotation() * M_PI / 180.f;

        sf::Vector2f force(cos(angle), sin(angle));
        velocity += force * 0.0001f;
    }

    move(velocity);
    velocity *= friction;

    setRotation(getRotation()+turningSpeed);
    turningSpeed *= turnFriction;
}

void Ship::onEvent(sf::Event & event){
    if ( event.type == sf::Event::KeyPressed ){
        if ( event.key.code == sf::Keyboard::S )
            S = true;
        if ( event.key.code == sf::Keyboard::W )
            W = true;
        if ( event.key.code == sf::Keyboard::A )
            A = true;
        if ( event.key.code == sf::Keyboard::D )
            D = true;
        if ( event.key.code == sf::Keyboard::F ){
            Projectile * newPr = new Projectile(getRotation());
            sf::Vector2f muzzlePosition = getPosition();
            muzzlePosition.x += cos(getRotation()* M_PI / 180.f)*50;
            muzzlePosition.y += sin(getRotation()* M_PI / 180.f)*50;
            newPr->setPosition(muzzlePosition);
            Globals::getPrvec()->push_back(newPr);
            //std::cout << "Added to globals";
        }
    }
    if ( event.type == sf::Event::KeyReleased ){
        if ( event.key.code == sf::Keyboard::S )
            S = false;
        if ( event.key.code == sf::Keyboard::W )
            W = false;
        if ( event.key.code == sf::Keyboard::A )
            A = false;
        if ( event.key.code == sf::Keyboard::D )
            D = false;
    }
}
