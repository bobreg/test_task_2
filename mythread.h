#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include "mainlogic.h"

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);


private:


    void run();

signals:
    void pause_th(bool);
    void send_list_points(QVector <coordinate>);

public slots:
    void start_th();
    void stop_th();


};

#endif // MYTHREAD_H
