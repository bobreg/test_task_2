#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include "xy_struct.h"
//#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();  // старт

    void on_pushButton_2_clicked();  // пауза

    void on_pushButton_3_clicked();  // стоп

public slots:
    void pull_points(const QVector <coordinate> &);

signals:
    void start_thread();
    void pause_thread(bool);
    void stop_thread();

private:
    Ui::Widget *ui;
    QGraphicsScene my_graph; // графический виджет для отображения точек и пр. элементов
    QGraphicsSimpleTextItem tx;
    QGraphicsSimpleTextItem ty;
    QGraphicsLineItem line_x;
    QGraphicsLineItem line_x1;
    QGraphicsLineItem line_x2;
    QGraphicsLineItem line_y;
    QGraphicsLineItem line_y1;
    QGraphicsLineItem line_y2;
    QList <QGraphicsSimpleTextItem*> points;
    bool flag_pause; // флаг показывающий статус приостановки генерации точек
    // bool flag_stop;

    // специальная переопределённая виртуальная функция для корректного закрытия окна с остановкой потока
    void closeEvent(QCloseEvent *event) override;
};
#endif // WIDGET_H
