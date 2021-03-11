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
using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();

    setFixedSize(850, 450);

    //表格初始化
    ui->dockWidget_3->setFixedSize(QSize(160,500)); //图片信息大小


    //开关图片信息窗口
    connect(ui->actionphotoInfo,&QAction::triggered,ui->dockWidget_3,[=](){
        if(ui->dockWidget_3->isVisible())
        {
            ui->dockWidget_3->hide();
        }else{
            ui->dockWidget_3->show();
        }
    });
    //传输数据
    connect(this,&MainWindow::SendImage,ui->tableView,&ImageBaseInfo::getImage);
    //emit SendImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Loading image file
void MainWindow::on_inputPushButton_clicked()
{
    QString fileName= QFileDialog::getOpenFileName(this,
                                                   "Open Input Image",
                                                   QDir::currentPath(),
                                                   "Images (*.jpg *.png *.bmp)");
    if(QFile::exists(fileName)){
        ui->inputLineEdit->setText(fileName);
    }
}

void MainWindow::on_outputPushButton_pressed()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Select Output Image",
                                                    QDir::currentPath(),
                                                    "*.jpg;;*.png;;*.bmp");//打开单个文件获取其路径
    //QStringList filepaths = QFileDialog::getOpenFileNames(this,"选择多个文件","./");                        //打开多个文件获取其路径
    //QString dirpath = QFileDialog::getExistingDirectory(this,"选择目录","./",QFileDialog::ShowDirsOnly);   //打开文件夹获取其路径

    if(!fileName.isEmpty())
    {
        ui->outputLineEdit->setText(fileName);
    }
//    if(!fileName.isEmpty()){
//        ui->outputLineEdit->setText(fileName);
//        Mat inImg, outImg;
//        inImg = imread(ui->inputLineEdit->text().toStdString());
//        //qDebug() << inImg.channels();
//        if(ui->medianBlurRadioButton->isChecked())
//            cv::medianBlur(inImg,outImg,5);
//        else if(ui->gaussianBlurRradioButton->isChecked())
//            cv::GaussianBlur(inImg,outImg,Size(5, 5), 1.25);
//        imwrite(fileName.toStdString(), outImg);
//        if(ui->displayImageCheckBox->isChecked())
//        {
//            imshow("Output Image", outImg);
//        }
//    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int result = QMessageBox::warning(this,
                                      "Exit",
                                      "Are you sure you want to close this program?",
                                      QMessageBox::Yes,
                                      QMessageBox::No);
    if(result == QMessageBox::Yes){
        saveSettings();
        event->accept();
    }else{
        event->ignore();
    }


    QSettings settings("Packt",
                       "Hello_OpenCV_Qt",
                       this);
}

void MainWindow::loadSettings()
{
    QSettings settings("Packt",
                       "Hello_OpenCV_Qt",
                       this);
    ui->inputLineEdit->setText(settings.value("inputLineEdit","").toString());
    ui->outputLineEdit->setText(settings.value("outputLineEdit","").toString());
    ui->medianBlurRadioButton->setChecked(settings.value("medianBlurRadioButton",true).toBool());
    ui->gaussianBlurRradioButton->setChecked(settings.value("gaussianBlurRradioButton",false).toBool());
    ui->displayImageCheckBox->setChecked(settings.value("displayImageCheckBox",false).toBool());
}

void MainWindow::saveSettings()
{
    QSettings settings("Packt",
                       "Hello_OpenCV_Qt",
                       this);
    settings.value("inputLineEdit",ui->inputLineEdit->text());
    settings.value("outputLineEdit",ui->outputLineEdit->text());
    settings.value("medianBlurRadioButton",ui->medianBlurRadioButton->isChecked());
    settings.value("gaussianBlurRradioButton",ui->gaussianBlurRradioButton->isChecked());
    settings.value("displayImageCheckBox",ui->displayImageCheckBox->isChecked());
}

//清除输入框
void MainWindow::on_inputLineClear_clicked()
{
    if(!ui->inputLineEdit->text().isEmpty())
    {
        ui->inputLineEdit->setText("");
    }
}

//生成
void MainWindow::on_outputGenerate_clicked()
{
    QString fileName = ui->outputLineEdit->text();
    if(!fileName.isEmpty())
    {
        ui->outputLineEdit->setText(fileName);
        Mat inImg, outImg;
        inImg = imread(ui->inputLineEdit->text().toStdString());
        emit SendImage(fileName, inImg.rows, inImg.cols, inImg.rows, inImg.cols, inImg.channels(), true);
        qDebug() << inImg.channels();
        //qDebug() << inImg;
        if(ui->medianBlurRadioButton->isChecked())
            cv::medianBlur(inImg,outImg,5);
        else if(ui->gaussianBlurRradioButton->isChecked())
            cv::GaussianBlur(inImg,outImg,Size(5, 5), 1.25);
        imwrite(fileName.toStdString(), outImg);
        if(ui->displayImageCheckBox->isChecked())
        {
            imshow("Output Image", outImg);
        }
    }else
    {
        QMessageBox::warning(NULL, "警告", "文件路径为空，生成失败\n请检查文件路径", QMessageBox::Yes);
    }
}

//void MainWindow::setSerSetDlgParams(int iDataBit,int iStopBoit,int iVerifyBit,
//                                    int iCtrlBit,bool bDts,bool bDtr)
//{
//    qDebug() << "data bit: " << iDataBit;
//    qDebug() << "stop bit: " << iStopBoit;
//    qDebug() << "verify bit: " << iVerifyBit;
//    qDebug() << "control bit: " << iCtrlBit;
//    qDebug() << "DTS: " << bDts;
//    qDebug() << "DTR: " << bDtr;
//}
