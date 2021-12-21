#include <QApplication>
#include <QScreen>
#include "Game.h"

Game *game;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
   game  = new Game(qApp->screens()[0]->size());
   game->show();
   game->Menu();

   return a.exec();
}
