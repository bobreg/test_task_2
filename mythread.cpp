#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}


void MyThread::run(){
    MainLogic return_xy;  // создание обекта класса генерации списка новых точек

    // соединение сигнала паузы со слотом объекта генерации точек
    connect(this, &MyThread::pause_th, &return_xy, &MainLogic::start_stop_timer);
    // соединение сигнала возврата списка коорлинат новых точек
    connect(&return_xy, &MainLogic::send_list_points, this, &MyThread::send_list_points, Qt::QueuedConnection);
    return_xy.start_stop_timer(true);  // запуск таймера по интервалу которого создаются новые точки
    exec(); // обработка событий потока
}

void MyThread::start_th(){
    if(this->isRunning() == false){  // если поток не запущен, то запустим его
        this->start();
        //qDebug() << "поток запущен";
    }else{  // если поток запущен, то отправим ему сигнал для запуска таймера
        emit pause_th(true);
        //qDebug() << "поток снова запущен";

    }
}


void MyThread::stop_th(){ // остановка потока
    this->quit();
    //qDebug() << "поток остановлен";
}

