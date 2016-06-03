#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MainWidget)
{
        ui->setupUi(this);

        server = new TimeServer(this);//�½����������󲢼���������һ���ͻ�������ʱ���ͻ��˱����䵽����һ�����߳��У�����һ�����ݵ���������Ȼ���������ʾ��
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
