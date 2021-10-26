#include "Enemy.h"
#include "Level.h"
#ifndef LESSTEHER_BOX_H
#define LESSTEHER_BOX_H
class Move
{
    private:
        const int T = 96;
        bool KeyPressed = false;
        Music sound;
    public:
        Move();
        void moveable(Hero &hero, std::vector<Enemy> &Enemy, Level &level);
};
Move::Move()
{
    sound.setVolume(5);
}
void Move::moveable(Hero &hero, std::vector<Enemy> &Enemy,  Level &level)
{
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        if(!KeyPressed)
        {
            if(level.obj[hero.y/T][hero.x/T-1] == '.' || level.obj[hero.y/T][hero.x/T-1] == 'K' )
            {
                if(level.obj[hero.y/T][hero.x/T-1] == 'K')
                {level.obj[hero.y/T][hero.x/T-1] = '.'; sound.openFromFile("music/drink.wav"); sound.play();}
                std::swap(level.obj[hero.y / T][hero.x / T], level.obj[hero.y / T][hero.x / T - 1]);
                hero.right = false;
                hero.do_move("left");
                level.num_of_move--;
                level.spikes();
            }
            else if(level.obj[hero.y/T][hero.x/T-1]=='D' && level.obj[hero.y/T][hero.x/T-2]=='.')
            {
                if(level.energy)
                {
                    std::swap(level.obj[hero.y/T][hero.x/T], level.obj[hero.y/T][hero.x/T-2]);
                    hero.right = false;
                    hero.do_move("left2");
                    level.num_of_move-=2;
                }
            }
            else if(level.obj[hero.y/T][hero.x/T-1] == 'B')
            {
                if(level.obj[hero.y/T][hero.x/T-2] == '.')
                    std::swap(level.obj[hero.y/T][hero.x/T-1], level.obj[hero.y/T][hero.x/T-2]);
                hero.right = false;
                hero.do_atack();
                level.num_of_move--;
                sound.openFromFile("music/chair.wav");
                sound.play();
                level.spikes();
            }
            else if(level.obj[hero.y/T][hero.x/T-1] == 'E')
            {
                for (auto & i : Enemy)
                {
                    if(i.y/T==hero.y/T && i.x/T==hero.x/T-1)
                    {
                        if (level.obj[hero.y/T][hero.x/T-2] == '.')
                        {
                            std::swap(level.obj[hero.y/T][hero.x/T-1], level.obj[hero.y/T][hero.x/T-2]);
                            i.do_move("left");
                            sound.openFromFile("music/kick.wav");
                        }
                        else
                        {
                            level.obj[hero.y/T][hero.x/T-1] = '.';
                            i.invise= true;
                            sound.openFromFile("music/death.wav");
                        }
                        i.do_atack();
                        hero.do_atack();
                        i.right = true;
                        hero.right= false;
                        level.num_of_move--;
                        level.spikes();
                        sound.play();
                    }
                }
            }
            if(level.map[hero.y/T][hero.x/T]=='0' || level.map[hero.y/T][hero.x/T]=='2')
            {
                sound.openFromFile("music/spikes.wav");
                sound.play();
                level.num_of_move--;
            }
            for(auto &i:Enemy)
                if(level.map[i.y/T][i.x/T]=='0' || level.map[i.y/T][i.x/T]=='2')
                {
                    level.obj[i.y/T][i.x/T]='.';
                    i.x=0; i.do_atack(); i.invise= true;
                    sound.openFromFile("music/death.wav"); sound.play();
                }
        }
        KeyPressed = true;
    }

    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        if(!KeyPressed)
        {
            if(level.obj[hero.y/T][hero.x/T+1] == '.' || level.obj[hero.y/T][hero.x/T+1]=='K')
            {
                if(level.obj[hero.y/T][hero.x/T+1] == 'K')
                {level.obj[hero.y/T][hero.x/T+1] = '.'; sound.openFromFile("music/drink.wav"); sound.play();}
                std::swap(level.obj[hero.y/T][hero.x/T], level.obj[hero.y/T][hero.x/T+1]);
                hero.do_move("right");
                hero.right = true;
                level.num_of_move--;
                level.spikes();
            }
            else if(level.obj[hero.y/T][hero.x/T+1]=='D' && level.obj[hero.y/T][hero.x/T+2]=='.')
            {
                if(level.energy)
                {
                    std::swap(level.obj[hero.y/T][hero.x/T], level.obj[hero.y/T][hero.x/T+2]);
                    hero.right = true;
                    hero.do_move("right2");
                    level.num_of_move-=2;
                }
            }
            else if(level.obj[hero.y/T][hero.x/T+1] == 'B')
            {
                if( level.obj[hero.y/T][hero.x/T+2] == '.')
                    std::swap(level.obj[hero.y/T][hero.x/T+1],level.obj[hero.y/T][hero.x/T+2]);
                hero.right = true;
                hero.do_atack();
                level.num_of_move--;
                sound.openFromFile("music/chair.wav");
                sound.play();
                level.spikes();
            }
            else if(level.obj[hero.y/T][hero.x/T+1] == 'E')
            {
                for (auto & i : Enemy)
                {
                    if (i.y / T == hero.y / T && i.x / T == hero.x / T + 1)
                    {
                        if (level.obj[hero.y / T][hero.x / T + 2] == '.')
                        {
                            std::swap(level.obj[hero.y / T][hero.x / T + 1], level.obj[hero.y / T][hero.x / T + 2]);
                            i.do_move("right");
                            sound.openFromFile("music/kick.wav");
                        }
                        else
                        {
                            level.obj[hero.y / T][hero.x / T + 1] = '.';
                            i.invise= true;
                            sound.openFromFile("music/death.wav");
                        }
                        i.do_atack();
                        hero.do_atack();
                        i.right = false;
                        hero.right = true;
                        sound.play();
                        level.num_of_move--;
                        level.spikes();
                    }
                }
            }
            if(level.map[hero.y/T][hero.x/T]=='0' || level.map[hero.y/T][hero.x/T]=='2')
            {
                sound.openFromFile("music/spikes.wav");
                sound.play();
                level.num_of_move--;
            }
            for(auto &i:Enemy)
                if(level.map[i.y/T][i.x/T]=='0' || level.map[i.y/T][i.x/T]=='2')
                {
                    level.obj[i.y/T][i.x/T]='.';
                    i.x=0; i.do_atack(); i.invise= true;
                    sound.openFromFile("music/death.wav"); sound.play();
                }
        }
        KeyPressed = true;
    }

    else if (Keyboard::isKeyPressed(Keyboard::W))
    {
        if(!KeyPressed)
        {
            if(level.obj[hero.y/T-1][hero.x/T] == '.' || level.obj[hero.y/T-1][hero.x/T]=='K')
            {
                if(level.obj[hero.y/T-1][hero.x/T] == 'K')
                {level.obj[hero.y/T-1][hero.x/T] = '.'; sound.openFromFile("music/drink.wav"); sound.play();}
                std::swap(level.obj[hero.y/T][hero.x/T], level.obj[hero.y/T-1][hero.x/T]);
                hero.do_move("up");
                level.num_of_move--;
                level.spikes();
            }
            else if(level.obj[hero.y/T-1][hero.x/T]=='D' && level.obj[hero.y/T-2][hero.x/T]=='.')
            {
                if(level.energy)
                {
                    std::swap(level.obj[hero.y/T][hero.x/T], level.obj[hero.y/T-2][hero.x/T]);
                    hero.do_move("up2");
                    level.num_of_move-=2;
                }
            }
            else if(level.obj[hero.y/T-1][hero.x/T] == 'B')
            {
                if(level.obj[hero.y/T-2][hero.x/T] == '.')
                    std::swap(level.obj[hero.y/T-1][hero.x/T],level.obj[hero.y/T-2][hero.x/T]);
                hero.do_atack();
                level.num_of_move--;
                sound.openFromFile("music/chair.wav");
                sound.play();
                level.spikes();

            }
            else if(level.obj[hero.y/T-1][hero.x/T] == 'E')
            {
                for (auto & i : Enemy)
                {
                    if (i.y / T == hero.y / T - 1 && i.x / T == hero.x / T)
                    {
                        if (level.obj[hero.y / T - 2][hero.x / T] == '.')
                        {
                            std::swap(level.obj[hero.y / T - 1][hero.x / T], level.obj[hero.y / T - 2][hero.x / T]);
                            i.do_move("up");
                            sound.openFromFile("music/kick.wav");
                        }
                        else
                        {
                            level.obj[hero.y / T - 1][hero.x / T] = '.';
                            i.invise= true;
                            sound.openFromFile("music/death.wav");
                        }

                        level.num_of_move--;
                        level.spikes();
                        sound.play();
                        i.do_atack();
                        hero.do_atack();
                    }
                }
            }
            if(level.map[hero.y/T][hero.x/T]=='0' || level.map[hero.y/T][hero.x/T]=='2')
            {
                sound.openFromFile("music/spikes.wav");
                sound.play();
                level.num_of_move--;
            }
            for(auto &i:Enemy)
                if(level.map[i.y/T][i.x/T]=='0' || level.map[i.y/T][i.x/T]=='2')
                {
                    level.obj[i.y/T][i.x/T]='.';
                    i.x=0; i.do_atack(); i.invise= true;
                    sound.openFromFile("music/death.wav"); sound.play();
                }
        }
        KeyPressed = true;
    }
    else if (Keyboard::isKeyPressed(Keyboard::S))
    {
        if(!KeyPressed)
        {
            if(level.obj[hero.y/T+1][hero.x/T] == '.' || level.obj[hero.y/T+1][hero.x/T]=='K')
            {
                if(level.obj[hero.y/T+1][hero.x/T] == 'K')
                {level.obj[hero.y/T+1][hero.x/T] = '.'; sound.openFromFile("music/drink.wav"); sound.play();}
                std::swap(level.obj[hero.y / T][hero.x / T], level.obj[hero.y / T + 1][hero.x / T]);
                hero.do_move("down");
                level.num_of_move--;
                level.spikes();

            }
            else if(level.obj[hero.y/T+1][hero.x/T]=='D' && level.obj[hero.y/T+2][hero.x/T]=='.')
            {
                if(level.energy)
                {
                    std::swap(level.obj[hero.y/T][hero.x/T], level.obj[hero.y/T+2][hero.x/T]);
                    hero.do_move("down2");
                    level.num_of_move-=2;
                }
            }
            else if(level.obj[hero.y/T+1][hero.x/T] == 'B')
            {
                if(level.obj[hero.y/T+2][hero.x/T] == '.')
                    std::swap(level.obj[hero.y/T+1][hero.x/T],level.obj[hero.y/T+2][hero.x/T]);
                hero.do_atack();
                level.num_of_move--;
                sound.openFromFile("music/chair.wav");
                sound.play();
                level.spikes();
            }
            else if(level.obj[hero.y/T+1][hero.x/T] == 'E')
            {
                for (auto & i : Enemy)
                {
                    if (i.y / T == hero.y / T + 1 && i.x / T == hero.x / T)
                    {
                        if (level.obj[hero.y / T + 2][hero.x / T] == '.')
                        {
                            std::swap(level.obj[hero.y / T + 1][hero.x / T], level.obj[hero.y / T + 2][hero.x / T]);
                            i.do_move("down");
                            sound.openFromFile("music/kick.wav");
                        }
                        else
                        {
                            level.obj[hero.y / T + 1][hero.x / T] = '.';
                            i.invise= true;
                            sound.openFromFile("music/death.wav");
                        }
                        level.num_of_move--;
                        level.spikes();
                        sound.play();
                        i.do_atack();
                        hero.do_atack();
                    }
                }
            }
            if(level.map[hero.y/T][hero.x/T]=='0' || level.map[hero.y/T][hero.x/T]=='2')
            {
                sound.openFromFile("music/spikes.wav");
                sound.play();
                level.num_of_move--;
            }
            for(auto &i:Enemy)
                if(level.map[i.y/T][i.x/T]=='0' || level.map[i.y/T][i.x/T]=='2')
                {
                    level.obj[i.y/T][i.x/T]='.';
                    i.x=0; i.do_atack(); i.invise= true;
                    sound.openFromFile("music/death.wav"); sound.play();
                }
        }
        KeyPressed = true;
    }
    else KeyPressed = false;

    if (Keyboard::isKeyPressed(Keyboard::R))
    {
        level.restart(); hero.restart();
        level.set_position(hero, "H");
        Enemy.clear();
        level.get_Enemy(Enemy);
        for(auto & i : Enemy) {i.heroTexture.loadFromFile("images/skeleton.png");i.hero.setTexture(i.heroTexture);}
    }
}
#endif //LESSTEHER_BOX_H
