#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QStandardItemModel>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <inference_engine.hpp>
using namespace cv;
//using namespace InferenceEngine;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    loadSettings();

    setFixedSize(660, 510);

}

MainWindow::~MainWindow()
{
    delete ui;
}
//加载图片
void MainWindow::on_PhotoLocationButton_clicked()
{

    QString fileName= QFileDialog::getOpenFileName(this,
                                                   "打开图片",
                                                   QDir::currentPath(),
                                                   "Images (*.jpg *.png *.bmp)");
    if(QFile::exists(fileName)){
        ui->PhotoLocationLineEdit->setText(fileName);
    }

}

//清除输入图片
void MainWindow::on_PhotoLocationClear_clicked()
{

    ui->PhotoLocationLineEdit->setText("");

}

//生成按钮
void MainWindow::on_GenButton_clicked()
{
    //这里连接后端 【*********************************************】
}

//加载预期MASK图片
void MainWindow::on_TrueMaskButton_clicked()
{

    QString fileName= QFileDialog::getOpenFileName(this,
                                                   "打开预期MASK",
                                                   QDir::currentPath(),
                                                   "Images (*.jpg *.png *.bmp)");
    if(QFile::exists(fileName)){
        ui->TrueMaskLineEdit->setText(fileName);
    }

}

//清除预期MASK图片
void MainWindow::on_TrueMaskClear_clicked()
{

    ui->TrueMaskLineEdit->setText("");

}

//关闭时提示
void MainWindow::closeEvent(QCloseEvent *event)
{

    int result = QMessageBox::warning(this,
                                      "Exit",
                                      "请确认是否退出程序",
                                      QMessageBox::Yes,
                                      QMessageBox::No);
    if(result == QMessageBox::Yes){
        saveSettings();
        event->accept();
    }else{
        event->ignore();
    }

}

//导入设置
void MainWindow::loadSettings()
{
    QSettings settings("Packt",
                       "Hello_OpenCV_Qt",
                       this);
    ui->PhotoLocationLineEdit->setText(settings.value("PhotoLocationLineEdit","").toString());
    ui->ModelRadioButton->setChecked(settings.value("ModelRadioButton",true).toBool());
    ui->midValueCheckBox->setChecked(settings.value("midValueCheckBox",false).toBool());
    ui->gaussCheckBox->setChecked(settings.value("gaussCheckBox",false).toBool());
    ui->GenMaskCheckBox->setChecked(settings.value("GenMaskCheckBox",true).toBool());
    ui->GenResultCheckBox->setChecked(settings.value("GenResultCheckBox",true).toBool());
    ui->displayImageCheckBox->setChecked(settings.value("displayImageCheckBox",false).toBool());
}

//保存设置
void MainWindow::saveSettings()
{
    QSettings settings("Packt",
                       "Hello_OpenCV_Qt",
                       this);
    settings.value("PhotoLocationLineEdit",ui->PhotoLocationLineEdit->text());
    settings.value("ModelRadioButton",ui->ModelRadioButton->isChecked());
    settings.value("midValueCheckBox",ui->midValueCheckBox->isChecked());
    settings.value("gaussCheckBox",ui->gaussCheckBox->isChecked());
    settings.value("GenMaskCheckBox",ui->GenMaskCheckBox->isChecked());
    settings.value("GenResultCheckBox",ui->GenResultCheckBox->isChecked());
    settings.value("displayImageCheckBox",ui->displayImageCheckBox->isChecked());
}
