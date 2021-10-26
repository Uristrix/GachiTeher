#include "Enemy.h"
void Enemy::hero_invisiable()
{
    if(invise)
    {
        if(mask!=0)
        {
            hero.setColor(Color(255,255,255,mask));
            mask--;
        }
    }
}
void Enemy::hero_atack(RenderWindow &window,  double time)
{
    if(atack<6)
    {
        atack+=0.015*time;
        if(right) hero.setTextureRect(IntRect(x1 * int(atack), y1+220 ,w , h));
        else hero.setTextureRect(IntRect(x1 * int(atack)+w, y1+220, -w, h));
        window.draw(hero);
    }
    else animate= true;
}