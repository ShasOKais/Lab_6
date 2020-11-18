#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <bits/stdc++.h>
#include "mysquare.h"
#include "SimpleVector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(int index);

    void DrawCircle();

private:
    QGraphicsScene *scene;
    MySquare *square;
    Ui::MainWindow *ui;
    //void paintEvent(QPaintEvent *);
};
#endif // MAINWINDOW_H
