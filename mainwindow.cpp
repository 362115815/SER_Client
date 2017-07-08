#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),openSmile(new cOpenSmileComp),serEngine(new cSER_Engine())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(serEngine)
    {
        delete serEngine;
    }
    if(openSmile)
    {
        delete openSmile;
    }
}

void MainWindow::on_pushButton_clicked()
{
    openSmile->start_record("D:/xiaomin/SER_Client/opensmile");//开始录音

}

void MainWindow::on_pushButton_2_clicked()
{
    openSmile->stop_record();//停止录音
}


void MainWindow::on_pushButton_3_clicked()
{
    serEngine->start_engine();
}

void MainWindow::on_pushButton_4_clicked()
{
    serEngine->stop_engine();
}
