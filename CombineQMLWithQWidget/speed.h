#ifndef SPEED_H
#define SPEED_H

#include <QObject>
#include <QWidget>

namespace Ui {
class Speed;
}

class Speed : public QWidget
{
    Q_OBJECT

public:
    Speed();

signals:
    void speedChanged(int);

private:
    Ui::Speed *ui;
};

class SpeedQML : public QObject {
    Q_OBJECT

    Q_PROPERTY(int speed READ speed NOTIFY speedChanged)
public:
    SpeedQML(QObject *parent = 0);
    int speed() const;

public slots:
    void updateSpeed(int);

signals:
    void speedChanged();

private:
    int m_speedData;
    Speed m_speed;
};

#endif // SPEED_H
