#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QBrush>
#include <QImage>
#include <QList>
#include <QGraphicsScene>
#include <QFileInfo>
#include <QProcess>
#include "Health.h"
#include "Button.h"
#include <stdlib.h>
#include <QApplication>
#include <QPushButton>

extern Enemy * enemy;

Game::Game(QSize oScreenSize, QWidget*parent) : QGraphicsView(parent), m_oScreenSize(oScreenSize)
{
    QGraphicsScene* pScene = new QGraphicsScene();
    setScene(pScene);

    pScene->setSceneRect(0,0,800,600);

    setBackgroundBrush(QBrush(QImage(":/ima/gad.png")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCursor(Qt::PointingHandCursor);
    setStyleSheet("border-style:none");
}


void Game::Menu()
{
//    Добавляем кнопку для начала игры
    Button *retryButton = new Button(QString("Играть"));
    int xRetryPos = this->width()/2 - retryButton->boundingRect().width()/2;
    int yRetryPos = 275;
    retryButton->setPos(xRetryPos, yRetryPos);
    connect(retryButton, &Button::clicked, this, &Game::start);
    scene()->addItem(retryButton);
//    добавляем кнопку для выхода
    Button *exitButton = new Button(QString("Выход"));
    int xExitPos = this->width()/2 - exitButton->boundingRect().width()/2;
    int yExitPos = 350;
    exitButton->setPos(xExitPos, yExitPos);
    connect(exitButton, &Button::clicked, this, &Game::onGameOver);
    scene()->addItem(exitButton);
}


void Game::start()
{
    scene()->clear();
    // предмет на сцене
    player = new Player();
    player->setPos(400,500);
    // сделать предмет фикусированным
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    // делает разрушение фикусированым
    player->setFocus();

    scene()->addItem(player);
    // чтобы была граница у пуль

    score = new Score();
    scene()->addItem(score);


    health = new Health();
    health->setPos(health->x(),health->y()+25);

    scene()->addItem(health);

    QTimer* pTimer = new QTimer(this);
    QObject::connect(pTimer,SIGNAL(timeout()),player,SLOT(spawn()));
    pTimer->start(2000);
}

void Game::onGameOver()
{
    close();
}
