#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Character.h"
#ifndef LESSTEHER_HERO_H
#define LESSTEHER_HERO_H
using namespace sf;
class Hero : public Character
{

    const int T=96;
    std::string how="";
public:
    int mv = 96;
    double atack = 13;
    explicit Hero(const String &name1, int x1, int y1, int w, int h) : Character(name1, x1, y1, w, h) { }
    void hero_move();
    void do_atack();
    virtual void hero_atack(RenderWindow &window,  double time);
    void restart();
    void do_move(std::string how);
};

#endif //LESSTEHER_HERO_H
