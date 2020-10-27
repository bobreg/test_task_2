#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <QObject>
#include <QTimer>
#include "xy_struct.h"
#include <QVector>
//#include <QDebug>


class MainLogic : public QObject
{
    Q_OBJECT
public:
    explicit MainLogic(QObject *parent = nullptr);
    ~MainLogic();

private:
    QTimer *timer = new QTimer; // таймер по которому генерируются новые точки
    void my_rand();

signals:
    void send_list_points(const QVector <coordinate> &);  // сигнал отправки новых точек

public slots:
    void start_stop_timer(bool);  // слот для обработки паузы

private slots:

};

#endif // MAINLOGIC_H
