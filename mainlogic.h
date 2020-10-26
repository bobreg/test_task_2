#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include "xy_struct.h"

class MainLogic : public QObject
{
    Q_OBJECT
public:
    explicit MainLogic(QObject *parent = nullptr);
    ~MainLogic();

private:
    QTimer *timer = new QTimer;

signals:
    void send_list_points(const QVector <coordinate> &);

public slots:
    void start_stop_timer(bool);

private slots:
    void my_rand();

};

#endif // MAINLOGIC_H
