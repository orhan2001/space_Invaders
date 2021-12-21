#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <vector>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/ima/bullet3.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x()> 0)
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100< 800)
        setPos(x()+10,y());
    }

    else if (event ->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        //если простраство ограниченно то создаем пулю
       // qDebug()<< "пуля создает это ";
        bullet ->setPos(x(),y());
        scene()->addItem(bullet);
    }





}

void Player::spawn()
{
    Enemy * enemy =new Enemy();
    scene()->addItem(enemy);
}
