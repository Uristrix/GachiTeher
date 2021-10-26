#include <SFML/Graphics.hpp>
#include <string>
#ifndef LESSTEHER_DIALOGUE_H
#define LESSTEHER_DIALOGUE_H
using namespace sf;
class Dialogue
{
    Texture  dialog[4];
    Sprite dialog_[4];
    Text text, name;
    Font font;
    String dialogs[15];
public:
    bool shows = true;
    int num = 0;
    Dialogue();
    void prolog (RenderWindow &window, Event event, int &lvl, bool &gamestart);
};

#endif //LESSTEHER_DIALOGUE_H
