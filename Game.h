#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include "Player.h"
#include <Score.h>
#include "Health.h"
#include "Enemy.h"
#include <vector>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QSize oScreenSize, QWidget* parent = nullptr);

    Player  *player;
    Score *score;
    Health* health;


    void Menu();
    void onGameOver();
    void start();
private:
    QSize       m_oScreenSize;
};

# endif // GAME_H
