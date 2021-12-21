#include <QFont>
#include "Health.h"
#include<QBrush>
#include <QImage>
#include <QGraphicsScene>
#include "Game.h"

extern Game * game;


Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    health = 3 ;
    setPlainText(QString("ЗДОРОВЬЕ: ") + QString::number(health)); // Health: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));

}

void Health::decrease(){
    health--;
    if (game->health->getHealth() <  1){
        // Закрываем приложение
        game->Menu();
    }
    else{
        setPlainText(QString("ЗДОРОВЬЕ: ") + QString::number(health));
    }
}


int Health::getHealth()
{
    return health ;
}

bool Health::gameOver(){

    return health < 1;
}
