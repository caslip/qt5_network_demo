#include "mainwindow.h"
#include <QHostInfo>
#include <QNetworkAddressEntry>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0,0,800,480);     //初始化屏幕大小，4.3寸RGB屏大小为800*480

    btn[0] = new QPushButton();
    btn[1] = new QPushButton();

    btn[0]->setText("显示主机信息");
    btn[1]->setText("清空显示");

    QHWidget = new QWidget();
    QVWidget = new QWidget();

    Vboxlayout = new QVBoxLayout();
    Hboxlayout = new QHBoxLayout();

    Hboxlayout->addWidget(btn[0]);
    Hboxlayout->addWidget(btn[1]);

    QHWidget->setLayout(Hboxlayout);

    text = new QTextBrowser();
    Vboxlayout->addWidget(text);
    Vboxlayout->addWidget(QHWidget);

    QVWidget->setLayout(Vboxlayout);

    setCentralWidget(QVWidget);

    timer = new QTimer();
    connect(btn[0],SIGNAL(clicked(bool)),this,SLOT(openTimer()));
    connect(btn[1],SIGNAL(clicked(bool)),this,SLOT(clearText()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Timertimeout()));
}

void MainWindow::openTimer(){
    text->clear();
    timer->start(1000);
}

void MainWindow::Timertimeout(){
    showHostinfo();
    timer->stop();
}

void MainWindow::showHostinfo(){

    QString str = getHostinfo();
    text->insertPlainText(str);
}

QString MainWindow::getHostinfo(){
    QString str = "主机名称： " + QHostInfo::localHostName() + "\n" ;
    QList<QNetworkInterface> addList = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface i,addList){
        str += "网卡设备： " + i.name() + "\n";
        str += "MAC地址： " + i.hardwareAddress() + "\n";
        QList<QNetworkAddressEntry> entries = i.addressEntries();
        foreach (QNetworkAddressEntry entry, entries) {
            if(entry.ip().protocol() == QAbstractSocket::IPv4Protocol){
                str += "IP地址： " + entry.ip().toString() + "\n";
                str += "子网掩码： " + entry.netmask().toString() + "\n";
                str += "广播地址： " + entry.broadcast().toString() + "\n\n";
            }
        }
    }

    return str;
}

void MainWindow::clearText(){
    text->clear();
}

MainWindow::~MainWindow()
{
}

