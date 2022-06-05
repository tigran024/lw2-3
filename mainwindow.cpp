#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    Point *pp = new Point(event->x(), event->y(), 3);
    if (n<10)
    {
        p[n] = pp;
        pp->setW(3+n);
        repaint();
        n++;
    }
    qDebug("x=%d, y=%d", pp->getX(), pp->getY());
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    Point *pp = p[n];
    if (pp)
        for (int i=0; i<=n; i++){
            pp->draw(&painter);
        }
}
MainWindow::~MainWindow()
{
    delete ui;
}
