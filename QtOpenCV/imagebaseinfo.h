#ifndef IMAGEBASEINFO_H
#define IMAGEBASEINFO_H

#include <QWidget>
#include <QDockWidget>
#include <QTableView>

class ImageBaseInfo : public QTableView
{
    Q_OBJECT
public:
    explicit ImageBaseInfo(QWidget *parent = nullptr);
    void getImage(QString name, int width, int height, int hor, int ver, int channels, bool type);
    void setTableView();

signals:

private:
    QString name;
    int width;
    int height;
    int hor;
    int ver;
    int channels;
    bool type;
};

#endif // IMAGEBASEINFO_H
