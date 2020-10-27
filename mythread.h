#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include "mainlogic.h"
//#include <QDebug>


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);


private:
    void run(); // переопределённая функция для запуска потока

signals:
    void pause_th(bool); // сигнал для приостановки генерации новых точек
    void send_list_points(const QVector <coordinate> &);  // сигнал со списком новых сгенерированных точек

public slots:
    void start_th(); // слот запуска потока
    void stop_th();  // слот остановки потока


};

#endif // MYTHREAD_H
