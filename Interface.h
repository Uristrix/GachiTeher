
#ifndef LESSTEHER_INTERFACE_H
#define LESSTEHER_INTERFACE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
using namespace sf;
class Interface
{
    Texture background_;
    Sprite background;
    Font font;
public:
    explicit Interface(const std::string& background);
    void show_lvl_interface(RenderWindow &window, int num, int lvl);
};
#endif //LESSTEHER_INTERFACE_H
