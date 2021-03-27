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
#include <Python.h>
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

    /*
     * 测试代码
     */
    if(!fileName.isEmpty())
    {
        /*
        Mat inImg, gray, thresh;
        inImg = imread(ui->inputLineEdit->text().toStdString());
        qDebug() << ui->inputLineEdit->text();
        cvtColor(inImg, gray, COLOR_BGR2GRAY);
        threshold(gray, thresh, 0, 255, THRESH_BINARY_INV+CV_THRESH_OTSU);

        //*****************
        Mat opening; Mat sure_bg;
        Mat sure_fg; Mat unknow;
        Mat dist_transform;
        double maxValue;
        // noise removal
        Mat kernel = Mat::ones(3, 3, CV_8U);
        morphologyEx(thresh, opening, MORPH_OPEN, kernel);

        // sure background area
        dilate(opening, sure_bg, kernel, Point(-1, -1), 3);

        // Finding sure foreground area
        distanceTransform(opening, dist_transform, DIST_L2, 5);
        minMaxLoc(dist_transform, 0, &maxValue, 0, 0);
        threshold(dist_transform, sure_fg, 0.7*maxValue, 255, 0);

        // Finding unknown region
        sure_fg.convertTo(sure_fg, CV_8U);
        subtract(sure_bg, sure_fg, unknow);
        //*****************
        // Marker labelling
        Mat markers;
        connectedComponents(sure_fg, markers);

        // Add one to all labels so that sure background is not 0, but 1
        markers = markers + 1;

        // Now, mark the region of unknown with zero
        markers.setTo(0, unknow);

        Mat marker;
        Mat mask;
        watershed(inImg, markers);
        compare(markers, -1, mask, CMP_EQ);
        inImg.setTo(Scalar(0, 0, 255), mask);
        //*****************

        imshow("QtImage",inImg);
        */
        Mat I = imread(fileName.toStdString());
        if (I.empty())
        {
            return;
        }
        //彩色图转成灰色图
        if (I.channels()==3)
        {
            cvtColor(I,I,CV_RGB2GRAY);
        }
        Mat planes[] = { Mat_<float>(I), Mat::zeros(I.size(), CV_32F) };
        Mat complexI;
        //构造复数双通道矩阵
        merge(planes,2,complexI);
        //快速傅里叶变换
        dft(complexI,complexI);
        Mat mag, pha, mag_mean;
        Mat Re, Im;
        //分离复数到实部和虚部
        Re = planes[0]; //实部
        split(complexI, planes);
        Re = planes[0]; //实部
        Im = planes[1]; //虚部
        //计算幅值
        magnitude(Re, Im, mag);
        //计算相角
        phase(Re, Im, pha);

        float *pre, *pim, *pm, *pp;
        //对幅值进行对数化
        for (int i = 0; i<mag.rows; i++)
        {
            pm = mag.ptr<float>(i);
            for (int j = 0; j<mag.cols; j++)
            {
                *pm = log(*pm);
                pm++;
            }
        }
        //对数谱的均值滤波
        blur(mag, mag_mean, Size(5, 5));
        //求取对数频谱残差
        mag = mag - mag_mean;

        for (int i = 0; i<mag.rows; i++)
        {
            pre = Re.ptr<float>(i);
            pim = Im.ptr<float>(i);
            pm = mag.ptr<float>(i);
            pp = pha.ptr<float>(i);
            for (int j = 0; j<mag.cols; j++)
            {
                *pm = exp(*pm);
                *pre = *pm * cos(*pp);
                *pim = *pm * sin(*pp);
                pre++;
                pim++;
                pm++;
                pp++;
            }
        }
        Mat planes1[] = { Mat_<float>(Re), Mat_<float>(Im) };
        //重新整合实部和虚部组成双通道形式的复数矩阵
        merge(planes1, 2, complexI);
        // 傅立叶反变换
        idft(complexI, complexI, DFT_SCALE);
        //分离复数到实部和虚部
        split(complexI, planes);
        Re = planes[0];
        Im = planes[1];
        //计算幅值和相角
        magnitude(Re, Im, mag);
        for (int i = 0; i<mag.rows; i++)
        {
            pm = mag.ptr<float>(i);
            for (int j = 0; j<mag.cols; j++)
            {
                *pm = (*pm) * (*pm);
                pm++;
            }
        }
        GaussianBlur(mag, mag, Size(7, 7), 2.5, 2.5);
        Mat invDFT, invDFTcvt;
        //归一化到[0,255]供显示
        normalize(mag, invDFT, 0, 255, NORM_MINMAX);
        //转化成CV_8U型
        invDFT.convertTo(invDFTcvt, CV_8U);
        imshow("SpectualResidual", invDFTcvt);
        imshow("Original Image", I);
        waitKey(0);
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
