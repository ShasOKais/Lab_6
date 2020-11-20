#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this); // инициалищация графической сцены
    ui->graphicsView->setScene(scene); // установка графической сцены
    ui->graphicsView->setRenderHints(QPainter::Antialiasing); // сглаживание сцены
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->RB_RED->setChecked(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    QPen pen(Qt::black);
    pen.setWidth(3);
    QBrush br(Qt::red);
    QRectF rect(0,0,100,100);
    switch (index) {
    case 0:
    {
        CCircle *m = new CCircle(rect, pen, br);
        stor.push_back(m);
        scene->addItem(stor.back());
        repaint();
        break;
    }
    case 1:
    {
        CRect *m = new CRect(rect, pen, br);
        stor.push_back(m);
        scene->addItem(stor.back());
        repaint();
        break;
    }
    }
}
void MainWindow::on_RB_RED_clicked()
{
    for(int i = 0; i < stor.size(); i++){
        if(stor[i]->ThisAlloc()){
            stor[i]->setBrush(QBrush(Qt::red, Qt::SolidPattern));
        }
    }
    scene->update();
    repaint();
}

void MainWindow::on_RB_BLUE_clicked()
{
    for(int i = 0; i < stor.size(); i++){
        if(stor[i]->ThisAlloc()){
            stor[i]->setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        }
    }
    scene->update();
    repaint();
}

void MainWindow::on_RB_GREEN_clicked()
{
    for(int i = 0; i < stor.size(); i++){
        if(stor[i]->ThisAlloc()){
            stor[i]->setBrush(QBrush(Qt::green, Qt::SolidPattern));
        }
    }
    scene->update();
    repaint();
}


void MainWindow::keyPressEvent(QKeyEvent *d)
{
    if(d->key() == Qt::Key_Delete) { // при нажатии клавиши Delete
        for(int i = stor.size() - 1; i >= 0; i--){ // удаляет выделенные фигуры
            if(stor[i]->ThisAlloc()){
                delete stor[i];
                stor.Delete(i);
            }
        }
        scene->update();
        repaint();
    }
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    for(int i = stor.size() - 1; i >= 0; i--){
        if(stor[i]->ThisAlloc()){
            stor[i]->setScale(arg1);
        }
        scene->update();
        repaint();
    }
    ui->progressBar->setValue(arg1);
}

void MainWindow::on_pushButton_Delete_clicked()
{
    for(int i = stor.size() - 1; i >= 0; i--){ // удаляет выделенные фигуры
        delete stor[i];
        stor.Delete(i);
    }
    scene->update();
    repaint();
}
