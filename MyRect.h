#ifndef Player_H
#define Player_H

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QObject>


class Player: public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public :
        void keyPressEvent(QKeyEvent *event);
public slots :
    void spawn();
};
#endif // Player_H
