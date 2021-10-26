#include "Interface.h"
Interface::Interface(const std::string& background)
{
    background_.loadFromFile(background);
    this->background.setTexture(background_);
    font.loadFromFile("images/minion.otf");
}

void Interface::show_lvl_interface(RenderWindow &window, int num_of_move, int lvl)
{
    View view;
    Text num(std::to_string(num_of_move), font, 60);
    Text lv(std::to_string(lvl), font, 60);
    Text inf("RESTART [R or RB]", font, 40);

    background.setPosition(0,0);
    num.setPosition(180,790);
    lv.setPosition(1700,790);
    inf.setPosition(800,970);

    window.draw(num);
    window.draw(lv);
    window.draw(inf);
    window.draw(background);
}