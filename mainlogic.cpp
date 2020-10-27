#include "mainlogic.h"

MainLogic::MainLogic(QObject *parent) : QObject(parent)
{
    connect(timer, &QTimer::timeout, this, &MainLogic::my_rand);
}

MainLogic::~MainLogic(){
    delete timer;
}

// функция которая генерирует список координат новых точке и испускает сигнал с этим списком
void MainLogic::my_rand(){
    QVector <coordinate> points;
    coordinate temp;
    for(int i = 0; i < COUNT_POINTS; i++){
        temp.x = rand() % 600 + 50;
        temp.y = rand() % 350 + 50;
        points.append(temp);
    }
    /*
    for(auto i: points){
        qDebug() << i.x << i.y;
    }
    */
    emit send_list_points((&points)[0]);
}

// слот который обрабатывает сигнал паузы (останавливает таймер)
void MainLogic::start_stop_timer(bool flag = true){
    if(flag == true){
        timer->start(1000);
    }else{
        //qDebug() << "поток приостановлен";
        timer->stop();
    }
}
