#include "Dialogue.h"
Dialogue::Dialogue()
{
    font.loadFromFile("images/minion.otf");
    text.setFont(font); text.setString(dialogs[num]);
    name.setFont(font);name.setPosition(960, 750);

    name.setFillColor(Color::Cyan);
    dialog[2].loadFromFile("images/Afa.png");
    dialog[1].loadFromFile("images/dialog.png");
    dialog[3].loadFromFile("images/dialog2.png");
    dialog[0].loadFromFile("images/lesteh_front.png");
    for(int i=0; i<4; i++)
    {
        dialog_[i].setTexture(dialog[i]);
        dialog_[i].setTextureRect(IntRect (0,0,1920,1080));
    }
    //dialog_[2].setTextureRect(IntRect (0,0,2000,748));
    dialog_[0].setTextureRect(IntRect (0,300,1920,1080));
}
void Dialogue:: prolog (RenderWindow &window, Event event, int &lvl, bool &gamestart)
{
    if(shows)
    {
        if(lvl==0)
        {
            dialogs[0] = L"Историю Покорителя Лестеха? Снова? Интересно...";
            dialogs[1] = L"Вам случайно не нужен рассказчик?";
            dialogs[2] = L"Ну конечно, позволь мне. Будет очень приятно.";
            dialogs[3] = L"   Однажды Романов проснулся с мыслью.\nЗачёт, ему нужен зачёт, иначе его отчислят.";
            dialogs[4] = L"Это, однако, была сложная миссия.\nОна могла стоить Романову жизни.";
            dialogs[5] = L"''Когда дело касается зачёта у Афанасьева, нет такой цены,\n"+std::string(20, ' ')+L"которая была бы слишком высока''\n     Сказал Романов, отправившись прямиком в Лестех.";
            name.setString(L"Афанасьев");
            if(num==0)
            {
                dialog[2].loadFromFile("images/Afa.png");
                dialog_[2].setTexture(dialog[2]);
                dialog_[2].setTextureRect(IntRect (0,0,448,604));
                dialog_[2].setPosition(window.getSize().x / 2 - dialog_[2].getGlobalBounds().width / 2, 300);
            }

            for (auto &i : dialog_) window.draw(i);
            if (event.type == Event::MouseButtonPressed)
            {
                num++;
                if (num==6) {num=0; shows = false; lvl++;}
                if(num==2) dialog_[2].setTextureRect(IntRect (0,0,0,0));
                if (num == 3)
                {
                    dialog[2].loadFromFile("images/prolog.png");
                    dialog_[2].setTexture(dialog[2]);
                    dialog_[2].setTextureRect(IntRect(0, 1359, 1280, 652));
                    dialog_[2].setScale(0.8, 0.8);
                    dialog_[2].setPosition(window.getSize().x/2 - dialog_[2].getGlobalBounds().width/2, 190);
                }
                if (num == 4) dialog_[2].setTextureRect(IntRect(0, 2016, 1280, 651));
                if (num == 5) dialog_[2].setTextureRect(IntRect(0, 2673, 1280, 651));

            }
            text.setString(dialogs[num]);
            text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 800);
            name.setPosition(window.getSize().x/2 - name.getGlobalBounds().width/2, 750);
            window.draw(text);
            window.draw(name);

        }
        if(lvl==1)
        {
            dialogs[0]=L"Эй, привет, скажи, ты случайно не видела Афанасьева?";
            dialogs[1]=L"Хммм... Афанасьев?";
            dialogs[2]=L"Он был здесь минуту назад, принимал лабы.";
            dialogs[3]=L"Сейчас обед, поищи его в столовой.";
            dialogs[4]=L"Спасибо.";

            dialog[2].loadFromFile("images/tyan_.png");
            dialog_[2].setTextureRect(IntRect (0,0,700,1000));
            dialog_[2].setPosition(window.getSize().x/2 - dialog_[2].getGlobalBounds().width/2,0);
            dialog_[2].setScale(1,1);
            for (auto &i : dialog_) window.draw(i);
            if(num==0){name.setString(L"Романов");}
            if (event.type == Event::MouseButtonPressed)
            {

                num++;
                if (num==5){num=0; shows = false; lvl++; return;}
                if(num==4){name.setString(L"Романов");}
                if(num==1){name.setString(L"Какая-то тянка");}

            }
            text.setString(dialogs[num]);
            text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 800);
            name.setPosition(window.getSize().x / 2 - name.getGlobalBounds().width / 2, 750);
            window.draw(text);
            window.draw(name);
        }
        if(lvl==2)
        {
            dialogs[0]=L"Ух, ты уже здесь?";
            dialogs[1]=L"Да, я пришла купить булочку.";
            dialogs[2]=L"А Афанасьев?";
            dialogs[3]=L"Нет, не видела. Думаю, тебе стоит сходить на кафедру.";
            dialogs[4]=L"Посмотреть его расписание.";
            dialogs[5]=L"Да, думаю ты права.";
            dialogs[6]=L"Только это?";
            dialogs[7]=L"Что?";
            dialogs[8]=L"На кафедре есть щель в полу.";
            dialogs[9]=L"            Чтобы перескочить через нее,\n    нужно бахнуть под дарксайд энергетос,\n тогда тебя разкумарит и будет всё по кайфу)";
            dialogs[10]=L"О, спасибо за хороший совет!";
            dialogs[11]=L"Не за что благодарить, фраер)";
            for (auto &i : dialog_) window.draw(i);
            if(num==0){name.setString(L"Романов");}
            if (event.type == Event::MouseButtonPressed)
            {
                num++;
                if (num==12){num=0; shows = false; lvl++; return;}
                if(num==0 || num==2 ||num==5 || num==7 || num==10){name.setString(L"Романов");}
                if(num==1|| num==3 || num==6 || num==8 || num==11){name.setString(L"Какая-то тянка");}

            }
            text.setString(dialogs[num]);
            text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 800);
            name.setPosition(window.getSize().x / 2 - name.getGlobalBounds().width / 2, 750);
            window.draw(text);
            window.draw(name);
        }
        if(lvl==3)
        {
            dialogs[0]=L"Что? Как ты тут оказалась?";
            dialogs[1]=L"У меня тоже есть дела на кафедре.";
            dialogs[2]=L"Как видишь, у Афанасьева пара в УЛК-2.";
            dialogs[3]=L"Чёрт, и где же это?";
            dialogs[4]=L"На 2 этаже есть переход в УЛК-1.";
            dialogs[5]=L"А там мы найдём переход в УЛК-2.";
            dialogs[6]=L"Хмм... Это вполне логично. СТОЙ!!!";
            dialogs[7]=L"Я побежала, догоняй.";
            dialogs[8]=L"Чёрт, опять мне придётся скитаться по вузу.";
            dialogs[9]=L"А могли пойти вместе. Странная девица.";
            for (auto &i : dialog_) window.draw(i);
            if(num==0){name.setString(L"Романов"); }
            if (event.type == Event::MouseButtonPressed)
            {
                num++;
                if(num==8) dialog_[2].setTextureRect(IntRect (0,0,0,0));
                if (num==10){num=0; shows = false; lvl++;}
                if(num==0 || num==3 ||num==6 || num==8){name.setString(L"Романов");}
                if(num==1 || num==4 ||num==7){name.setString(L"Какая-то тянка");}
            }
            text.setString(dialogs[num]);
            text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 800);
            name.setPosition(window.getSize().x / 2 - name.getGlobalBounds().width / 2, 750);
            window.draw(text);
            window.draw(name);
        }
        if(lvl==4)
        {
            dialogs[0]=L"Ты уже здесь. Могла не убегать от меня...";
            dialogs[1]=L"Не суть, мы добрались до УЛК-1 - это гараздо важнее.";
            dialogs[2]=L"Не могу не согласиться, однако... СТОЙ!!!";
            dialogs[3]=L"Догоняй))) ";
            dialogs[4]=L"Да что с ней не так!!!";
            for (auto &i : dialog_) window.draw(i);
            if(num==0){name.setString(L"Романов"); dialog_[2].setTextureRect(IntRect (0,0,700,1000));}
            if (event.type == Event::MouseButtonPressed)
            {
                num++;
                if(num==4) dialog_[2].setTextureRect(IntRect (0,0,0,0));
                if (num==5){num=0; shows = false; lvl++;}
                if(num==0 ||num==2 || num==4){name.setString(L"Романов");}
                if(num==1 || num==3){name.setString(L"Какая-то тянка");}
            }
            text.setString(dialogs[num]);
            text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 800);
            name.setPosition(window.getSize().x / 2 - name.getGlobalBounds().width / 2, 750);
            window.draw(text);
            window.draw(name);
        }
        if(lvl==5)
        {
            dialogs[0]=L"Страшное место этот УЛК.";
            dialogs[1]=L"Не могу не согласиться, вон там переход во второй УЛК.";
            dialogs[2]=L"Сейчас ты увидишь поистине страшное место)";
            dialogs[3]=L"Да ты чо? ***";
            dialogs[4]=L"Ну, я побежала.";
            dialogs[5]=L"Да, да, да...";
            for (auto &i : dialog_) window.draw(i);
            if(num==0){name.setString(L"Романов");dialog_[2].setTextureRect(IntRect (0,0,700,1000));}
            if (event.type == Event::MouseButtonPressed)
            {
                num++;
                if(num==5) dialog_[2].setTextureRect(IntRect (0,0,0,0));
                if (num==6){num=0; shows = false; lvl++;}
                if(num==0 || num==3 || num==5) {name.setString(L"Романов");}
                if(num==1 || num==4){name.setString(L"Какая-то тянка");}
            }
            text.setString(dialogs[num]);
            text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 800);
            name.setPosition(window.getSize().x / 2 - name.getGlobalBounds().width / 2, 750);
            window.draw(text);
            window.draw(name);
        }
        if(lvl==6)
        {
            dialogs[0]=L"Мне надоело бегать за тобой, я в вузе 2 раз.";
            dialogs[1]=L"Мне сложно искать эти кабинеты.";
            dialogs[2]=L"Не ной, у нас есть проблема побольше.";
            dialogs[3]=L"Какая?";
            dialogs[4]=L"Как видишь, Афанасьева тут нет.";
            dialogs[5]=L"Кстати, что это за скелеты тут ходят и не дают мне прохода?";
            dialogs[6]=L"Это ЛТшники. Жалкое зрелище...";
            dialogs[7]=L"У Афанасьева будет лекция в 404, предлагаю пойти туда.";
            dialogs[8]=L"Ты опять убежишь?";
            dialogs[9]=L"Да)))";

            for (auto &i : dialog_) window.draw(i);
            if(num==0){name.setString(L"Романов");dialog_[2].setTextureRect(IntRect (0,0,700,1000));}
            if (event.type == Event::MouseButtonPressed)
            {
                num++;
                if (num==10){num=0; shows = false; lvl++;}
                if(num==0 || num==3 || num==5 || num==8){name.setString(L"Романов");}
                if(num==2 || num==4 || num==6 || num==9){name.setString(L"Какая-то тянка");}
            }
            text.setString(dialogs[num]);
            text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 800);
            name.setPosition(window.getSize().x / 2 - name.getGlobalBounds().width / 2, 750);
            window.draw(text);
            window.draw(name);
        }
        if(lvl==7)
        {
            dialogs[0]=L"Это всё очень странно, ты вечно убегаешь от меня.";
            dialogs[1]=L"И мы никак не можем найти Афанасьева.";
            dialogs[2]=L"Ладно, я раскрою тебе секрет...";
            dialogs[3]=L"ЧТО?????";
            dialogs[4]=L"Да, всё это время, это был Я.";
            dialogs[5]=L"АФАНАСЬЕВ АЛЕКСЕЙ ВИКТОРОВИЧ!";
            dialogs[6]=L"Но почему вы были в образе девушки?";
            dialogs[7]=L"Мне надоели должники, поэтому я научился искусству макияжа у Цветковой и начал скрываться.";
            dialogs[8]=L"Однако, видя твоё упорство, я не могу не поставить зачёт. Давай зачётку.";
            dialogs[9]=L"Спасибо, но у меня ещё 8 незакрытых предметов и это только начало)";

            for (auto &i : dialog_) window.draw(i);
            if(num==0){name.setString(L"Романов");dialog_[2].setTextureRect(IntRect (0,0,700,1000));}
            if (event.type == Event::MouseButtonPressed)
            {
                num++;
                if (num==10){num=0; gamestart= false; lvl = 0;}
                if(num==3) dialog_[2].setTextureRect(IntRect (2000,2000,0,0));
                if(num==4)
                {
                    dialog[2].loadFromFile("images/Afa.png");
                    dialog_[2].setTexture(dialog[2]);
                    dialog_[2].setTextureRect(IntRect (0,0,448,604));
                    dialog_[2].setPosition(window.getSize().x / 2 - dialog_[2].getGlobalBounds().width / 2, 300);
                }
                if(num==0 || num==3 || num==6 || num==9){name.setString(L"Романов");}
                if(num==2){name.setString(L"Какая-то тянка");}
                if(num==4 || num==7) name.setString(L"Афанасьев");
            }
            text.setString(dialogs[num]);
            text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 800);
            name.setPosition(window.getSize().x / 2 - name.getGlobalBounds().width / 2, 750);
            window.draw(text);
            window.draw(name);
        }
    }
}