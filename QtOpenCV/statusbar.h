#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>
#include <QStatusBar>

class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    explicit StatusBar(QWidget *parent = nullptr);

signals:

};

#endif // STATUSBAR_H
