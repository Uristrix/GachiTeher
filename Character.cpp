#include "Character.h"
Character::Character(const String& name, int x1, int y1, int w, int h)
{
    std::cout<<animate;
    this->x1=x1; this->y1=y1; this->w=w; this->h=h;
    heroImage.loadFromFile(name);
    heroTexture.loadFromImage(heroImage);
    hero.setTexture(heroTexture);
    hero.setTextureRect(IntRect(x1,y1,w,h));
    //hero.setScale(2,2);
    //hero.setPosition(0,-10);
    x=y=0;
}
void Character::SetPosition(int x, int y)
{
    this-> x = x;
    this-> y = y;
    //std::cout<<x<<" "<<y<<"\n";
    hero.setPosition(x, y-10);
}

void Character::show_animate_hero(RenderWindow &window,  double time)
{
    if(animate)
    {
        CurrentFrame += 0.018*time;
        if(CurrentFrame > 12) CurrentFrame -= 12;
        if(right)
            hero.setTextureRect(IntRect(x1 * int(CurrentFrame), y1, w, h));
        else
            hero.setTextureRect(IntRect(x1 * int(CurrentFrame)+w, y1, -w, h));
        //if(!right) hero.setScale(-1,-1);
        window.draw(hero);
    }

}
