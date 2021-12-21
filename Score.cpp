#include <QFont>
#include "Score.h"





Score::Score(QGraphicsItem *parent)
{
    score = 0 ;
    setPlainText(QString("СЧЕТ: ") + QString::number(score)) ; // score: 0
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));

}

void Score::increase()
{
    score++;

    setPlainText(QString("СЧЕТ: ") + QString::number(score));
}

int Score::getScore()
{
    return score ;
}

