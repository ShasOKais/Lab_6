#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DrawCircle(){
    QPen pen(Qt::red);
    QBrush br(Qt::white);
    pen.setWidth(5);
    square = new MySquare();
    scene->addItem(square);
}

void MainWindow::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        DrawCircle();
        break;
    case 1:
        scene->addItem(square);
        break;
    case 2:
        break;
    case 3:
        break;
    }
}
