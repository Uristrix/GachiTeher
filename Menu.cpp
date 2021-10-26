#include "Menu.h"
Menu::Menu(float width, float height):selectedItemIndex(0)
{
    intr.setFont(font);
    name.setFont(font);
    font.loadFromFile("images/minion.otf");
    name.setString(L"Афанасьев"); name.setFillColor(Color::Cyan);
    intr.setString(L"Привет, студент. Пожалуйста, не обращай на меня \n                                    внимания,""\n         это просто Я, молодой, добрый Афанасьев");

    for(int i=0; i<MAX_NUMBER_OF_ITEMS; i++)
    {
        menu[i].setFont(font);
        menu[i].setOutlineColor(sf::Color::White);
        menu[i].setString(name_menu[i]);
        menu[i].setPosition(sf::Vector2f(width / 2 -menu[i].getGlobalBounds().width/2, 750 +(i*70)));
    }
    menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
    texture[0].loadFromFile("images/lesteh_front.png");
    texture[1].loadFromFile("images/dialog.png");
    texture[2].loadFromFile("images/Afa.png");
    texture[3].loadFromFile("images/dialog2.png");

    for(int i=0; i<MAX_NUMBER_OF_SPRITE; i++)
    {
        sprite[i].setTexture(texture[i]);
        sprite[i].setTextureRect(IntRect (0,0,1920,1080));
    }
    sprite[0].setTextureRect(IntRect (0,300,1920,1080));
    sprite[2].setTextureRect(IntRect (0,0,448,604));
}

void Menu::draw(sf::RenderWindow &window, Event event)
{
    sprite[2].setPosition(window.getSize().x / 2 - sprite[2].getGlobalBounds().width / 2, 300);
    if (!gamestart)
    {
        for (auto &i : sprite) window.draw(i);
        if (!intro)
        {
            for ( auto & i : menu) window.draw(i);

            if (event.type==sf::Event::KeyReleased && event.key.code==Keyboard::W)
            {
                if (selectedItemIndex > 0)
                {
                    menu[selectedItemIndex].setFillColor(sf::Color::White);
                    selectedItemIndex--;
                    menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
                }
                //KeyPressed = true;
            }
            if(event.type==sf::Event::KeyReleased && event.key.code==Keyboard::S)
            {
                if (selectedItemIndex+1  < MAX_NUMBER_OF_ITEMS)
                {
                    menu[selectedItemIndex].setFillColor(sf::Color::White);
                    selectedItemIndex++;
                    menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
                }
                //KeyPressed = true;
            }
            //else KeyPressed = false;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && selectedItemIndex==0) gamestart =true;
            if(Keyboard::isKeyPressed(Keyboard::Enter) && selectedItemIndex==1)
            {
                music.setVolume(50);
                music.openFromFile("music/open.wav");
                music.play();
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter) && selectedItemIndex==2) window.close();
        }
        else
        {
            name.setPosition(window.getSize().x/2 - name.getGlobalBounds().width/2, 750);
            intr.setPosition(window.getSize().x/2 - intr.getGlobalBounds().width/2, 800);
            window.draw(name); window.draw(intr);
            if (Mouse::isButtonPressed(Mouse::Left)) intro=false;
        }

    }

}
//
//void Menu::MoveUp()
//{
//    if (selectedItemIndex - 1 >= 0)
//    {
//        menu[selectedItemIndex].setFillColor(sf::Color::White);
//        selectedItemIndex--;
//        menu[selectedItemIndex].setFillColor(sf::Color::Red);
//    }
//}
//
//void Menu::MoveDown()
//{
//    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
//    {
//        menu[selectedItemIndex].setFillColor(sf::Color::White);
//        selectedItemIndex++;
//        menu[selectedItemIndex].setFillColor(sf::Color::Red);
//    }
//}

