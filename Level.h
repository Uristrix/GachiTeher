#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "Enemy.h"

#ifndef LESSTEHER_LEVEL_H
#define LESSTEHER_LEVEL_H
using namespace sf;
class Level
{
    const int T = 48;
    Image lvlImage;
    Texture lvlTexture;
    Sprite lvl;
public:
    std::vector<std::string> map;
    std::vector<std::string> obj;
    std::vector<std::string> source;
    bool yes=false, energy= true;
    int num_of_move, copy_num;

    Level(const std::string& map, const String& name, int num_of_move);
    void generate_map(RenderWindow &window);
    void generate_object(RenderWindow &window);
    void read_map(const std::string&);

    template<typename Type>
    void set_position(Type &hero, const std::string& str);

    void restart();
    void update(std::string map, int num_of_move);
    void check_yes();
    void fit(RenderWindow &window);
    void get_Enemy(std::vector<Enemy> &Enemy);

    void create_maps();

    void spikes();

    void check_energy();
};
Level::Level(const std::string& map, const String& name, int num_of_move)
{
    lvlImage.loadFromFile(name);
    lvlTexture.loadFromImage(lvlImage);
    lvl.setTexture(lvlTexture);
    read_map(map);
    this->num_of_move=copy_num=num_of_move;
}
void Level::generate_map(RenderWindow &window)
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] == ' ') continue;
            if (map[i][j] == '.' || map[i][j] == 'H'|| map[i][j] == 'K' ||map[i][j] == 'B'||map[i][j] == 'T'
                ||map[i][j] == 'E' ||map[i][j] == 'D' || map[i][j] == 'F' || map[i][j] == 'S'|| map[i][j] == '|'
                ||map[i][j] == '0' ||map[i][j] == '1' || map[i][j] == '2' )
            {
                lvl.setTextureRect(IntRect(26*T, 4*T, T, T));
                lvl.setPosition(2*j * T, 2*i * T);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (map[i][j] == 'T')
            {
                lvl.setTextureRect(IntRect(26*T, 4*T, T, T));
                lvl.setPosition(2*j * T, 2*(i-1) * T);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (map[i][j] == '+' || map[i][j] == 'W')
            {
                lvl.setTextureRect(IntRect(T*42, T*14, T, T));
                lvl.setPosition(2*j * T, 2*i * T);
                lvl.setScale(2, 2);
                window.draw(lvl);
                lvl.setTextureRect(IntRect(T*42, T*13, T, T));
                lvl.setPosition(2*j * T, 2*(i-1) * T);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if(map[i][j] == '0' || map[i][j] == '2')
            {
                lvl.setTextureRect(IntRect(T*24,T*12,100,100));
                lvl.setPosition(2*j * T+9, 2*i * T+10);
                lvl.setScale(0.96, 0.96);
                window.draw(lvl);
            }
            if(map[i][j]=='1')
            {
                lvl.setTextureRect(IntRect(T*24+100,T*12,100,100));
                lvl.setPosition(2*j * T-3, 2*i * T+8);
                lvl.setScale(0.96, 0.96);
                window.draw(lvl);
            }
        }
    }
}
void Level::generate_object(RenderWindow &window)
{
    int shift=0;
    for (int i = 0; i < obj.size(); i++)
    {
        for (int j = 0; j < obj[i].size(); j++)
        {
            if (obj[i][j] == 'B')
            {
                lvl.setTextureRect(IntRect(T*18, T*14, T, T));
                lvl.setPosition(2*j * T, 2*i * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (obj[i][j] == 'K')
            {
                lvl.setTextureRect(IntRect(T*24+200, T*12, 100, 100));
                lvl.setPosition(2*j * T+55, 2*i * T);
                lvl.setScale(0.7, 0.7);
                lvl.setRotation(45);
                window.draw(lvl);
                lvl.setRotation(0);
            }
            if (obj[i][j] == 'D')
            {
                lvl.setTextureRect(IntRect(T*32, T*6, T, T));
                lvl.setPosition(2*j * T, 2*i * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (map[i][j] == '_')
            {
                lvl.setTextureRect(IntRect(T*7, T*6, T, T));
                lvl.setPosition(2*j * T, 2*i * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (map[i][j] == '|')
            {
                lvl.setTextureRect(IntRect(T*14, T*8, T, T));
                lvl.setPosition(2*j * T, 2*i * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
                lvl.setTextureRect(IntRect(T*14, T*7, T, T));
                lvl.setPosition(2*j * T, 2*(i-1) * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (map[i][j] == 'S')
            {
                lvl.setTextureRect(IntRect(T*20, T*14, T, T));
                lvl.setPosition(2*j * T, 2*i * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
                lvl.setTextureRect(IntRect(T*20, T*15, T, T));
                lvl.setPosition(2*j * T, 2*(i+1) * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (map[i][j] == 'W')
            {
                lvl.setTextureRect(IntRect(T*14, T*15, T, T));
                lvl.setPosition(2*j * T, 2*i * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
                lvl.setTextureRect(IntRect(T*14, T*14, T, T));
                lvl.setPosition(2*j * T, 2*(i-1) * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (map[i][j] == 'T')
            {
                lvl.setTextureRect(IntRect(T*11, T*3, T, T));
                lvl.setPosition(2*j * T, 2*i * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
                lvl.setTextureRect(IntRect(T*11, T*2, T, T));
                lvl.setPosition(2*j * T, 2*(i-1) * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
                lvl.setTextureRect(IntRect(T*11, T*4, T, T));
                lvl.setPosition(2*j * T, 2*(i+1) * T-shift);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
            if (map[i][j] == '-')
            {
                lvl.setTextureRect(IntRect(T*42, T*12, T, T));
                lvl.setPosition(2*j * T, 2*i * T);
                lvl.setScale(2, 2);
                window.draw(lvl);
            }
        }
    }
}

template<typename Type>
void Level::set_position(Type & hero, const std::string& str)
{
    for(int i=0; i<obj.size(); i++)
        if(obj[i].find(str)!=-1)
        {
            hero.SetPosition(obj[i].find(str) * T*2, i * T*2);
            //std::cout<<i<<map[i].find(str);
        }
}

void Level::read_map(const std::string& maps)
{
    if(!source.empty()) source.clear();
    std::ifstream in(maps);
    std::string temp;
    while (getline(in,temp))
        source.push_back(temp);
    in.close();
}
void Level::create_maps()
{
    map = obj = source;
    for (int i = 0; i < source.size(); i++)
    {
        for (int j = 0; j < source[i].size(); j++)
        {
            if(source[i][j]=='0' || source[i][j]=='1' || source[i][j]=='2'){obj[i][j]='.';}
            else if(source[i][j]=='K' || source[i][j]=='D'){map[i][j]='.';}
            else if(source[i][j]=='3'){map[i][j]='0';obj[i][j]='B';}
            else if(source[i][j]=='4'){map[i][j]='1';obj[i][j]='B';}
            else if(source[i][j]=='5'){map[i][j]='2';obj[i][j]='B';}
            else if(source[i][j]=='B'){map[i][j]='.';obj[i][j]='B';}
            else if(source[i][j]=='E'){map[i][j]='.';obj[i][j]='E';}
            else if(source[i][j]=='H'){map[i][j]='.';obj[i][j]='H';}
            else if(source[i][j]=='F'){map[i][j]='.';obj[i][j]='F';}
        }
    }
    //for(auto &i:obj) std::cout<<i<<"\n";
    //for(auto &i:map) std::cout<<i<<"\n";
}
void Level::restart()
{
    create_maps();
    num_of_move=copy_num;
    yes= false;
}
void Level::check_yes()
{
    for(int i=0; i<obj.size(); i++)
        if(obj[i].find('F')!=-1 &&
           (obj[i-1][obj[i].find('F')] == 'H' || obj[i+1][obj[i].find('F')] == 'H'||
            obj[i][obj[i].find('F')-1] == 'H' || obj[i][obj[i].find('F')+1] == 'H'))
            yes=true;
}

void Level::fit(RenderWindow &window)
{
    Vector2<unsigned int> vec= window.getSize();
    int x = (int(vec.x) - 2*T*source[0].size())/T/4;
    int y = (int(vec.y) - 2*T*source.size())/T/4;

    source.insert(source.begin(),y, std:: string (source[0].size(), ' '));
    for (auto & i : source)
        i = std:: string (x, ' ') + i;
    create_maps();
}

void Level::update(std::string map, int num_of_move)
{
    read_map(map);
    this->num_of_move=copy_num=num_of_move;
    yes= false; energy = true;
}

void Level::get_Enemy(std::vector<Enemy> &En)
{
    for(int i=0; i<source.size(); i++)
        for(int j=0; j<source[i].size(); j++)
            if(source[i][j]=='E')
            {
                Enemy temp("images/skeleton.png", 100,40,100,100);
                temp.SetPosition(j * T*2, i * T*2);
                En.push_back(temp);
            }
    //for(auto & i : en) Enemy.push_back(i);
}
void Level::spikes()
{
    for (auto & i : map)for (char & j : i){if (j == '1')j = '2'; else if (j == '2')j = '1';}
}

void Level::check_energy()
{
    for(auto & i : obj)
        for (char & j : i)
            if(j=='K') {energy = false; return;}
    energy = true;
}

#endif //LESSTEHER_LEVEL_H