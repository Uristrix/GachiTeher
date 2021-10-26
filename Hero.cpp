#include "Hero.h"

void Hero::hero_move()
{
    if(mv<96)
    {
        if(how=="left"){hero.move(-1, 0);mv++;}
        if(how=="right"){hero.move(1, 0);mv++;}
        if(how=="up"){hero.move(0, -1);mv++;}
        if(how=="down"){hero.move(0, 1);mv++;}

        if(how=="left2"){hero.move(-2, 0);mv++;}
        if(how=="right2"){hero.move(2, 0);mv++;}
        if(how=="up2"){hero.move(0, -2);mv++;}
        if(how=="down2"){hero.move(0, 2); mv++;}
    }
}
void Hero::do_move(std::string how)
{
    mv=0; this->how=how;
    if(this->how=="left") x-=T;
    if(this->how=="right") x+=T;
    if(this->how=="up") y-=T;
    if(this->how=="down") y+=T;

    if(this->how=="left2") x-=(2*T);
    if(this->how=="right2") x+=(2*T);
    if(this->how=="up2") y-=(2*T);
    if(this->how=="down2") y+=(2*T);

}
void Hero::hero_atack(RenderWindow &window,  double time)
{
    if(atack<13)
    {
        atack+=0.018*time;
        if(right) hero.setTextureRect(IntRect(x1 * int(atack), y1+220 ,w , h));
        else hero.setTextureRect(IntRect(x1 * int(atack)+w, y1+220, -w, h));
        window.draw(hero);
    }
    else animate= true;
}
void Hero::do_atack()
{
    animate = false;
    atack = 0;
}
void Hero::restart()
{
    atack = 13;
    mv = 96;
    how="";
    CurrentFrame=0.0;
    right= true;
    animate = true;
}