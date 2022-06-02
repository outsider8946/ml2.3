#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <point.h>
#include <QMouseEvent>
#include <QPen>
Point mas[10];
int i=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(Qt::black);
    if(valid)
    {
        for(int i = 0;i<10;i++)
        {
            mas[i].SetSize();
            int cnt = mas[i].GetSize();
            mas[i].SetSize(cnt+i);
            if(i<=4)
                pen.setWidth(mas[i].GetThickness());
            else
                pen.setWidth(mas[i].GetThickness()*2);
            painter.setPen(pen);
            mas[i].draw(&painter);

        }
    }


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   Point point;
   point.SetX(event->x());
   point.SetY(event->y());
   mas[i++] =point;
   valid = true;
   repaint();
}

