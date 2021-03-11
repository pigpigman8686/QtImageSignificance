#include "statusbar.h"
#include <QLabel>

StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent)
{
    QLabel* pLable; //创建QLable
    pLable= new QLabel(QString("项目名称：Dog.png"));
    pLable->setAlignment(Qt::AlignCenter);
    pLable->setMinimumSize(pLable->sizeHint());
    //this->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 不显示label的边框
    this->setSizeGripEnabled(false); //不显示右边的大小控制点
    this->addWidget(pLable); //永久展示文字
}
