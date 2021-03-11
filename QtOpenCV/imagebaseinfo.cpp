/*
 * mhd
 * 用于显示图片信息
*/
#include "imagebaseinfo.h"
#include <QDockWidget>
#include <QStandardItemModel>
#include <QDebug>

ImageBaseInfo::ImageBaseInfo(QWidget *parent) : QTableView(parent)
{
    QStandardItemModel* model = new QStandardItemModel();

    /* 设置表格标题行(输入数据为QStringList类型) */
    model->setVerticalHeaderLabels({"名称", "分辨率", "宽度", "高度", "水平分辨率", "垂直分辨率","位深度","类型"});

    /* 自适应所有列，让它布满空间 */
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model->setItem(0, 0, new QStandardItem(""));
//    model->setItem(0, 0, new QStandardItem(QString("Dog.png")));
//    model->setItem(1, 0, new QStandardItem(QString("401 X 300")));
//    model->setItem(2, 0, new QStandardItem(QString("401 px")));
//    model->setItem(3, 0, new QStandardItem(QString("300 px")));
//    model->setItem(4, 0, new QStandardItem(QString("96 dpi")));
//    model->setItem(5, 0, new QStandardItem(QString("96 dpi")));
//    model->setItem(6, 0, new QStandardItem(QString("24")));
//    model->setItem(7, 0, new QStandardItem(QString("原始")));

    /* 设置表格视图数据 */
    this->setModel(model);

    /* 显示 */
    this->show();
}

void ImageBaseInfo::getImage(QString name, int width, int height, int hor, int ver, int channels, bool type)
{
    qDebug() << "name" << name;

    this->name = name;
    this->width = width;
    this->height = height;
    this->hor = hor;
    this->ver = ver;
    this->channels = channels;
    this->type = type;

    setTableView();
}

void ImageBaseInfo::setTableView()
{
    QStandardItemModel* model = new QStandardItemModel();

    model->setVerticalHeaderLabels({"名称", "分辨率", "宽度", "高度", "水平分辨率", "垂直分辨率","位深度","类型"});

    model->setItem(0, 0, new QStandardItem(name));
    QString px = QString(QString::number(width)) + " X " + QString(QString::number(height));
    model->setItem(1, 0, new QStandardItem(QString(px)));
    model->setItem(2, 0, new QStandardItem(QString(QString::number(width))));
    model->setItem(3, 0, new QStandardItem(QString(QString::number(height))));
    model->setItem(4, 0, new QStandardItem(QString(QString::number(hor))));
    model->setItem(5, 0, new QStandardItem(QString(QString::number(ver))));
    model->setItem(6, 0, new QStandardItem(QString(QString::number(channels * 8))));
    if(type == true)
    {
        model->setItem(7, 0, new QStandardItem(QString("原始")));
    }else
    {
        model->setItem(7, 0, new QStandardItem(QString("mask")));
    }


    /* 设置表格视图数据 */
    this->setModel(model);

    /* 显示 */
    this->show();
}
