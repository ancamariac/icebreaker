#include "Globals.hpp"

std::vector<Projectile*> * prvec;

void Globals::init(){
    prvec = new std::vector<Projectile*>();
}

std::vector<Projectile*> *  Globals::getPrvec(){
    return prvec;
}
