#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Hero.h"
#ifndef LESSTEHER_ENEMY_H
#define LESSTEHER_ENEMY_H

class Enemy : public Hero
{
public:
    bool invise = false;
    int mask = 255;
    explicit Enemy(const String &name1, int x1, int y1, int w, int h) : Hero(name1, x1, y1, w, h){}
    void hero_invisiable();
    void hero_atack(RenderWindow &window,  double time) override;
};


#endif //LESSTEHER_ENEMY_H
