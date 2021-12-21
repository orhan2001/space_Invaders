#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"
extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    if(game->health->getHealth() > 0){
    int random_number = rand()%700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/ima/bullet1.png"));

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);


    }
}


void Enemy::move()
{
    // пуля идет вверх
    if(game->health->getHealth() > 0){
        setPos(x(),y()+5);

    }



    if (pos().y() > 600){
        game->health->decrease();
        if(game->health->getHealth() <  1){
           game->Menu();
            //game->health->decrease();
        }

        scene()->removeItem(this);
        delete this;
    }

}
