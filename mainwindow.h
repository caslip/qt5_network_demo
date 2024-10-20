#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include <QTimer>
#include <QWidget>
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QTextBrowser"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QPushButton *btn[2];
    QTextBrowser *text;
    QTimer *timer;
    QWidget *QHWidget , *QVWidget;
    QVBoxLayout *Vboxlayout;
    QHBoxLayout *Hboxlayout;
    QString getHostinfo();

private slots:
    void Timertimeout();
    void showHostinfo();
    void openTimer();
    void clearText();


};
#endif // MAINWINDOW_H
