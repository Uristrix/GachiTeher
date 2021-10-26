#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Move.h"
#include "Enemy.h"
#include "Level.h"
#include "Dialogue.h"
#include "Interface.h"
#include <utility>
#include <vector>
#include <string>
#ifndef LESSTEHER_GACHITAKER_H
#define LESSTEHER_GACHITAKER_H
using namespace sf;
class Game
{
    Clock clock;
    Music music;
    Move move;
    Menu menu;
    RenderWindow window;
    Interface interface;
    Dialogue dialog;
    std::vector<int> num_move;
    int level=0;
    Hero hero;
    Character Tyan;
    std::vector<Enemy> Enemy;
    Level lvl;
public:
    explicit Game(std::vector<int>num_move);
    void start();
};
Game::Game(std::vector<int> num_move):
        window(sf::VideoMode(1920, 1080), "GachiTaker"),
        lvl("level/lvl_1.txt", "images/school3.png",num_move[level]),
        hero("images/Me.png", 100, 0, 100, 100),
        Tyan("images/Lucifer.png",100,0,100,100),
        interface("images/gachi_norm1920.png"),
        menu(1920, 1080)
{
    this->num_move=std::move(num_move);
    music.openFromFile("music/level_music.wav");
    music.setVolume(1.5);  music.play();  music.setLoop(true);
    lvl.fit(window);
    lvl.get_Enemy(Enemy);
    lvl.set_position(hero, "H");
    lvl.set_position(Tyan, "F");
    for(auto & i : Enemy){i.heroTexture.loadFromFile("images/skeleton.png"); i.hero.setTexture(i.heroTexture);}
}

void Game::start()
{
    while(window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
        double time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /=1200;

        Event event{};
        while (window.pollEvent(event)) if (event.type == Event::Closed) window.close();

        window.clear();
        menu.draw(window, event);
        if (menu.gamestart)
        {
            dialog.prolog(window, event, level, menu.gamestart);
            if(!dialog.shows)
            {
                lvl.generate_map(window);
                lvl.generate_object(window);
                hero.hero_atack(window,time);
                hero.show_animate_hero(window,time);
                Tyan.show_animate_hero(window,time);
                for(auto & i : Enemy){i.hero_atack(window, time);i.show_animate_hero(window, time); i.hero_move(); i.hero_invisiable();}
                interface.show_lvl_interface(window, lvl.num_of_move, level);
                move.moveable(hero, Enemy, lvl);
                hero.hero_move();
                lvl.check_yes();
                lvl.check_energy();

                if(lvl.num_of_move==-1)
                {
                    lvl.restart();
                    hero.restart();
                    lvl.set_position(hero, "H");
                    Enemy.clear();
                    lvl.get_Enemy(Enemy);
                    for(auto & i : Enemy) {i.heroTexture.loadFromFile("images/skeleton.png");i.hero.setTexture(i.heroTexture);}
                }
                if(lvl.yes && level < num_move.size() && hero.mv==96)
                {
                    hero.restart();
                    lvl.update("level/lvl_"+std::to_string(level+1)+".txt", num_move[level]);
                    lvl.fit(window);
                    lvl.set_position(hero, "H");
                    lvl.set_position(Tyan, "F");
                    Enemy.clear();
                    lvl.get_Enemy(Enemy);
                    for(auto & i : Enemy) {i.heroTexture.loadFromFile("images/skeleton.png");i.hero.setTexture(i.heroTexture);}
                    dialog.shows = true;
                    dialog.num=0;
                }
                if(lvl.yes && level == num_move.size() && hero.mv==96)
                {
                    lvl.update("level/lvl_1.txt", num_move[0]);
                    Enemy.clear();
                    lvl.fit(window);
                    lvl.get_Enemy(Enemy);
                    for(auto & i : Enemy) {i.heroTexture.loadFromFile("images/skeleton.png");i.hero.setTexture(i.heroTexture);}
                    dialog.shows = true;
                    dialog.num=0;
                    lvl.set_position(hero, "H");
                    lvl.set_position(Tyan, "F");
                    //menu.gamestart = false;
                }
            }
        }
        window.display();
    }
}
#endif //LESSTEHER_GACHITAKER_H
