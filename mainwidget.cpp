#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MainWidget)
{
        ui->setupUi(this);

        server = new TimeServer(this);//新建服务器对象并监听，当有一个客户端连接时，客户端被分配到另外一个子线程中，发送一条数据到服务器。然后服务器显示。
        if(!server->listen(QHostAddress::Any,54910)){
                qDebug() << server->errorString();
                server->close();
        }
        qDebug() << "listen..."<<server->serverAddress().toString()<<server->serverPort();
}

MainWidget::~MainWidget()
{
        delete ui;
}
