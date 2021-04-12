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

private slots:
    void on_PhotoLocationButton_clicked();
    void on_PhotoLocationClear_clicked();
    void on_GenButton_clicked();
    void on_TrueMaskButton_clicked();
    void on_TrueMaskClear_clicked();

protected:
    void closeEvent(QCloseEvent *event);
private:
    void loadSettings();
    void saveSettings();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
