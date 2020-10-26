#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QDebug>
#include "xy_struct.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public slots:
    void pull_points(const QVector <coordinate> &);

signals:
    void start_thread();
    void pause_thread(bool);
    void stop_thread();

private:
    Ui::Widget *ui;
    QGraphicsScene my_graph;
    QGraphicsSimpleTextItem tx;
    QGraphicsSimpleTextItem ty;
};
#endif // WIDGET_H
