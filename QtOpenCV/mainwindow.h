#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void SendImage(QString name, int width, int height, int hor, int ver, int channels, bool type);

private slots:
    void on_inputPushButton_clicked();
    void on_outputPushButton_pressed();
    void on_inputLineClear_clicked();

    void on_outputGenerate_clicked();

protected:
    void closeEvent(QCloseEvent *event);
private:
    void loadSettings();
    void saveSettings();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
