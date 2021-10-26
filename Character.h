
#ifndef LESSTEHER_CHARACTER_H
#define LESSTEHER_CHARACTER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
class Character
{
public:
    Image heroImage;
    Texture heroTexture;
    Sprite hero;
    double CurrentFrame=0.0;
    bool right= true;
    bool animate = true;
    int x, y;
    int x1, y1, w, h;
    explicit Character(const String& name, int x1, int y1, int w, int h);
    void SetPosition(int x, int y);
    void show_animate_hero(RenderWindow &window, double time);
};
#endif //LESSTEHER_CHARACTER_H
