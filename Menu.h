
#ifndef LESSTEHER_MENU_H
#define LESSTEHER_MENU_H

#include <SFML/Audio/Music.hpp>
#include "SFML/Graphics.hpp"
using namespace sf;
#define MAX_NUMBER_OF_ITEMS 3
#define MAX_NUMBER_OF_SPRITE 4

class Menu
{
public:
    Menu(float width, float height);
    void draw(sf::RenderWindow &window, Event event);
    bool gamestart = false;
private:
    Music music;
    bool intro =true;
    int selectedItemIndex;
    Text intr, name;
    Font font;
    Text menu[MAX_NUMBER_OF_ITEMS];
    std::string name_menu[MAX_NUMBER_OF_ITEMS] ={"Play", "Options", "Exit"};
    Texture  texture[MAX_NUMBER_OF_SPRITE];
    Sprite sprite[MAX_NUMBER_OF_SPRITE];
};
#endif //LESSTEHER_MENU_H
